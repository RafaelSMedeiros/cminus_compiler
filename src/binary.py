from assembly import generate_asm, InstrKind, LineKind, Format, Quadruple

opcode_map = {
    InstrKind.ADD:    "000000",
    InstrKind.SUB:    "000001",
    InstrKind.MUL:    "000010",
    InstrKind.DIV:    "000011",
    InstrKind.AND:    "000100",
    InstrKind.OR:     "000101",
    InstrKind.ADDI:   "000110",
    InstrKind.SUBI:   "000111",
    InstrKind.ANDI:   "001000",
    InstrKind.LI:     "001001",
    InstrKind.MOVE:   "001010",
    InstrKind.LW:     "001111",
    InstrKind.SW:     "010000",
    InstrKind.BEQ:    "010001",
    InstrKind.BNE:    "010010",
    InstrKind.BLT:    "010011",
    InstrKind.BGT:    "010100",
    InstrKind.JUMP:   "010101",
    InstrKind.JAL:    "010110",
    InstrKind.JR:     "010111",
    InstrKind.HALT:   "011000",
    InstrKind.NOP:    "011001",
    InstrKind.LIN:    "011010",
    InstrKind.OUT:    "011011",
}

reg_map = {
    "$out0": "00000",
    "$t0":   "00001",
    "$t1":   "00010",
    "$t2":   "00011",
    "$t3":   "00100",
    "$t4":   "00101",
    "$t5":   "00110",
    "$t6":   "00111",
    "$t7":   "01000",
    "$t8":   "01001",
    "$t9":   "01010",
    "$t10":  "01011",
    "$t11":  "01100",
    "$t12":  "01101",
    "$t13":  "01110",
    "$t14":  "01111",
    "$t15":  "10000",
    "$a0":   "10001",
    "$a1":   "10010",
    "$a2":   "10011",
    "$a3":   "10100",
    "$a4":   "10101",
    "$a5":   "10110",
    "$a6":   "10111",
    "$a7":   "11000",
    "$a8":   "11001",
    "$a9":   "11010",
    "$zero":  "11011",
    "$v0":   "11100",
    "$sp":   "11101",
    "$fp":   "11110",
    "$ra":   "11111"
}

def to_bin16(val):
    try:
        val = int(val)
    except (ValueError, TypeError):
        # Se não for um número (ex: label), retorna 16 zeros
        return "0000000000000000"
    if val < 0:
        val = (1 << 16) + val
    return format(val, '016b')

def generate_binary(instructionList):
    binary_lines = []
    
    label_line_map = {
        instr.label: instr.lineNumber
        for instr in instructionList
        if instr.lineKind == LineKind.LABEL and instr.label
    }

    for instr in instructionList:
        print(instr)
        if instr.lineKind == LineKind.LABEL:
            continue  # Labels não geram instruções binárias
        
        opcode = opcode_map.get(instr.instrKind)

        if instr.format == Format.R:
            rs = reg_map.get(instr.rs)
            rt = reg_map.get(instr.rt)
            rd = reg_map.get(instr.rd)
            binary = f"{opcode}{rt}{rd}{rs}00000000000"

        elif instr.format == Format.I:
            rs = reg_map.get(instr.rs) if instr.rs else "00000"
            rt = reg_map.get(instr.rt) if instr.rt else "00000"
            imm = to_bin16(instr.immediate if instr.immediate is not None else 0)
            if instr.instrKind in (InstrKind.BEQ, InstrKind.BNE, InstrKind.BLT, InstrKind.BGT):
                label = instr.immediate or "0"
                target_line = label_line_map.get(label, 0)
                offset = target_line - instr.lineNumber - 1
                imm = to_bin16(offset)
                binary = f"{opcode}{rt}{rs}{imm}"
            else:
                binary = f"{opcode}{rt}{rs}{imm}"

        elif instr.format == Format.J:
            if instr.instrKind == (InstrKind.JR):
                rs = reg_map.get(instr.label)
                binary = f"{opcode}{rs}000000000000000000000"
            else:
                label = instr.label or "0"
                line = label_line_map.get(label, 0)
                imm = to_bin16(line)
                binary = f"{opcode}0000000000{imm}"
            
        elif instr.format == Format.H:
            binary = f"{opcode}00000000000000000000000000"    
        
        elif instr.format == Format.N:
            binary = f"{opcode}00000000000000000000000000"

        binary_lines.append(binary)

    with open("binary_output.txt", "w") as f:
        for line in binary_lines:
            f.write(line + "\n")

    print("Arquivo 'binary_output.txt' gerado com sucesso.")

if __name__ == "__main__":
    generate_binary(generate_asm())
