from dataclasses import dataclass
from enum import Enum, auto
from typing import List, Optional

class Format(Enum):
    R = auto()
    I = auto()
    J = auto()
    H = auto()  # HALT
    N = auto()

class InstrKind(Enum):
    ADD = "add"
    SUB = "sub"
    MUL = "mul"
    DIV = "div"
    AND = "and"
    OR = "or"
    ADDI = "addi"
    SUBI = "subi"
    ANDI = "andi"
    LI = "li"
    LIN = "lin"
    MOVE = "move"
    LW = "lw"
    SW = "sw"
    BEQ = "beq"
    BNE = "bne"
    BLT = "blt"
    BGT = "bgt"
    JUMP = "jump"
    JAL = "jal"
    JR = "jr"
    HALT = "halt"
    OUT = "out"
    NOP = "nop"

class LineKind(Enum):
    INST = auto()
    LABEL = auto()

@dataclass
class Instruction:
    format: Optional[Format] = None
    instrKind: Optional[InstrKind] = None
    rs: Optional[str] = None
    rt: Optional[str] = None
    rd: Optional[str] = None
    immediate: Optional[int] = None
    label: Optional[str] = None
    lineKind: Optional[LineKind] = LineKind.INST
    lineNumber: Optional[int] = None

@dataclass
class Quadruple:
    op: str
    addr1: Optional[str] = None
    addr2: Optional[str] = None
    addr3: Optional[str] = None

instructionList: List[Instruction] = []

def insertInstructionR(instrKind, rs, rt, rd, lineNumber):
    instructionList.append(Instruction(format=Format.R, instrKind=instrKind, rs=rs, rt=rt, rd=rd, lineNumber=lineNumber))

def insertInstructionI(instrKind, rs, rt, immediate, lineNumber):
    instructionList.append(Instruction(format=Format.I, instrKind=instrKind, rs=rs, rt=rt, immediate=immediate, lineNumber=lineNumber))

def insertInstructionJ(instrKind, label, lineNumber):
    instructionList.append(Instruction(format=Format.J, instrKind=instrKind, label=label, lineKind=LineKind.INST, lineNumber=lineNumber))

def insertInstructionH(instrKind, lineNumber):
    instructionList.append(Instruction(format=Format.H, instrKind=instrKind, lineNumber=lineNumber))

def insertInstructionN(instrKind, lineNumber):
    instructionList.append(Instruction(format=Format.N, instrKind=instrKind, lineNumber=lineNumber))

def insertLabel(label, lineNumber):
    instructionList.append(Instruction(lineKind=LineKind.LABEL, label=label, lineNumber=lineNumber))

def insertSpInstruction(mem, lineNumber):
    instructionList.insert(0, Instruction(format=Format.I, instrKind=InstrKind.LI, rs="$sp", immediate=mem, lineNumber=lineNumber))

def normalize_arg(arg):
    if arg is not None:
        arg = arg.strip().strip("()")
    if arg is None or arg == "___":
        return None
    return arg

def load_quadruples(filename):
    quads = []
    with open(filename, "r") as f:
        for line in f:
            line = line.strip().lower()
            if not line or line.startswith("#"):
                continue
            parts = [normalize_arg(x) for x in line.strip("()").split(",")]
            while len(parts) < 4:
                parts.append(None)
            quad = Quadruple(*parts[:4])
            quads.append(quad)
    return quads

def generate_asm():
    WORD_SIZE = 1
    mem_locations = {}
    current_function_stack_size = 0
    param_count = 0
    current_function_name = ""

    i = 0
    insertSpInstruction(2, i)
    i += 1
    insertInstructionJ(InstrKind.JUMP, "main", i)
    i += 1

    quads = load_quadruples("codigo_intermediario.txt")
    for quad in quads:
        op = quad.op
        addr1, addr2, addr3 = quad.addr1, quad.addr2, quad.addr3

        if op == "fun":
            current_function_name = addr2
            insertLabel(current_function_name, i)
            mem_locations = {}
            current_function_stack_size = 0
            param_count = 0
            if current_function_name != "main":
                insertInstructionI(InstrKind.SW, "$fp", "$sp", 0, i)
                i += 1
                insertInstructionI(InstrKind.SW, "$ra", "$sp", 1, i)
                i += 1
                insertInstructionI(InstrKind.MOVE, "$fp", "$sp", None, i)
                i += 1
                insertInstructionI(InstrKind.ADDI, "$sp", "$sp", WORD_SIZE*2, i)
                i += 1

        elif op == "alloc":
            var_name = addr1
            current_function_stack_size += WORD_SIZE
            offset = current_function_stack_size + WORD_SIZE
            mem_locations[var_name] = offset
            insertInstructionI(InstrKind.ADDI, "$sp", "$sp", WORD_SIZE, i)
            i += 1

        elif op == "arg":
            var_name = addr2
            current_function_stack_size += WORD_SIZE
            offset = current_function_stack_size + WORD_SIZE
            mem_locations[var_name] = offset
            insertInstructionI(InstrKind.ADDI, "$sp", "$sp", WORD_SIZE, i)
            i += 1
            insertInstructionI(InstrKind.SW, f"$a{param_count}", "$fp", offset, i)
            i += 1
            param_count += 1
            
            # Se a próxima quadrupla não for 'arg', zere param_count
            next_index = quads.index(quad) + 1
            if next_index < len(quads):
                next_quad = quads[next_index]
                if next_quad.op != "arg":
                    param_count = 0

        elif op == "load":
            dest_reg, var_name = f"${addr1}", addr2
            offset = mem_locations.get(var_name, 0)
            insertInstructionI(InstrKind.LW, dest_reg, "$fp", offset, i)
            i += 1

        elif op == "store":
            src_reg, var_name = f"${addr2}", addr1
            offset = mem_locations.get(var_name, 0)
            insertInstructionI(InstrKind.SW, src_reg, "$fp", offset, i)
            i += 1

        elif op == "assign":
            if addr2.isdigit():
                insertInstructionI(InstrKind.LI, f"${addr1}", None, int(addr2), i)
                i += 1
            else:
                insertInstructionI(InstrKind.MOVE, f"${addr1}", f"${addr2}", None, i)
                i += 1

        elif op in ("add", "sub", "mul", "div", "and", "or"):
            dest_reg, src1 = f"${addr1}", f"${addr2}"
            if addr3 and addr3.isdigit():
                instr_map = {"add": InstrKind.ADDI, "sub": InstrKind.SUBI, "and": InstrKind.ANDI, "mul": InstrKind.MUL, "div": InstrKind.DIV, "or": InstrKind.OR}
                kind = instr_map.get(op, None)
                if kind:
                    insertInstructionI(kind, dest_reg, src1, int(addr3), i)
                    i += 1
            else:
                src2 = f"${addr3}" if addr3 else None
                kind = InstrKind[op.upper()]
                insertInstructionR(kind, dest_reg, src1, src2, i)
                i += 1

        elif op in ("bgt", "blt", "beq", "bne"):
            rs = f"${addr2}" if addr2 != "0" else "$zero"
            rt = f"${addr3}" if addr3 != "0" else "$zero"
            last_comparison = {
            "kind": InstrKind[op.upper()],
            "rs": rs,
            "rt": rt
            }

        elif op == "if":
            if 'last_comparison' not in locals():
                raise ValueError(f"Erro: IF na linha {i} sem comparação anterior válida.")
            kind = last_comparison["kind"]
            rs = last_comparison["rs"]
            rt = last_comparison["rt"]
            label = addr2
            if kind == InstrKind.BEQ:
                insertInstructionI(InstrKind.BNE, rs, rt, label, i)
            elif kind == InstrKind.BNE:
                insertInstructionI(InstrKind.BEQ, rs, rt, label, i)
            else:
                insertInstructionI(kind, rs, rt, label, i)
            i += 1
            del last_comparison

        elif op == "label":
            insertLabel(addr1, i)

        elif op == "goto":
            insertInstructionJ(InstrKind.JUMP, addr1, i)
            i += 1

        elif op == "param":
            insertInstructionI(InstrKind.MOVE, f"$a{param_count}", f"${addr1}", None, i)
            i += 1
            param_count += 1

        elif op == "call":
            if addr2 == "input":
                insertInstructionI(InstrKind.LIN, f"${addr1}", None, None, i)
                i += 1
            elif addr2 == "output":
                insertInstructionI(InstrKind.MOVE, "$out0", "$a0", None, i)
                i += 1
                insertInstructionN(InstrKind.OUT, i)
                i += 1
            else:
                insertInstructionI(InstrKind.MOVE, "$out0", "$sp", None, i)
                i += 1
                insertInstructionN(InstrKind.OUT, i)
                i += 1
                insertInstructionJ(InstrKind.JAL, addr2, i)
                i += 1
                if addr1:
                    insertInstructionI(InstrKind.MOVE, f"${addr1}", "$v0", None, i)
                    i += 1
            param_count = 0

        elif op == "return":
            if addr1:
                insertInstructionI(InstrKind.MOVE, "$v0", f"${addr1}", None, i)
                i += 1

        elif op == "end":
            if current_function_name != "main":
                insertInstructionI(InstrKind.LW, "$ra", "$fp", 1, i)
                i += 1
                insertInstructionI(InstrKind.LW, "$fp", "$fp", 0, i)
                i += 1
                insertInstructionJ(InstrKind.JR, "$ra", i)
                i += 1

        elif op == "halt":
            insertInstructionH(InstrKind.HALT, i)
            i += 1

    write_final_code()
    return instructionList

def write_final_code():
    with open("final_code2.asm", "w") as f:
        for instr in instructionList:
            if instr.lineKind == LineKind.LABEL:
                f.write(f"{instr.label}:\n")
            elif instr.instrKind:
                parts = [instr.instrKind.value]
                if instr.format == Format.N:
                    pass  # Apenas o opcode
                elif instr.format == Format.J:
                    if instr.label:
                        parts.append(instr.label)
                else:
                    if instr.rs: parts.append(instr.rs)
                    if instr.rt: parts.append(instr.rt)
                    if instr.rd: parts.append(instr.rd)
                    if instr.immediate is not None: parts.append(str(instr.immediate))
                f.write(f"{instr.lineNumber}" + "   " + " ".join(parts) + "\n")

if __name__ == "__main__":
    try:
        generate_asm()
    except FileNotFoundError:
        print("Erro: 'codigo_intermediario.txt' não encontrado.")
    except Exception as e:
        print(f"Erro inesperado: {e}")
