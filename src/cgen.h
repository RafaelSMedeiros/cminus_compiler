#ifndef _CGEN_H_
#define _CGEN_H_    

typedef enum {
    opFUN, opEND, opALLOC, opGOTO, opIF, opCALL, opRETURN, opPARAM, opLOAD,
    opSTORE, opADD, opSUB, opMUL, opDIV, opHALT, opASSIGN, opRET, opARG,
    opLABEL, opPRINT, opREAD, opAND, opOR, opNOT, opBLT, opBGT, opEQUAL, 
    opATTR, opMOVE, opBNT
} opKind;

typedef enum{
    constINT, String, Empty
} addressKind;

typedef struct
{
    addressKind type;
    union {
        int val;
        char *name;
    } var;
} Address;

typedef struct {
    opKind op;
    Address addr1, addr2, addr3; // operands
} Quad;

typedef struct QuadListRec {
    Quad quad;
    struct QuadListRec *next;
} QuadList;

void createQuad(opKind op, Address addr1, Address addr2, Address addr3);
void printCodeGen();

static void genExp(TreeNode *t);
void codeGen(TreeNode *t);

#endif
