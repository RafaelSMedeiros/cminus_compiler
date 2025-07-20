#include "globals.h"
#include "cgen.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void cGen(TreeNode *t);

QuadList *head = NULL;

Address currentAddress, aux1, aux2, var, offset;

int labelCount = 0;
int tempCount = 0;
int nparam = -1;

char varEscopo[30] = "global";

const char *opKindStr[] = {
    "FUN", "END", "ALLOC", "GOTO", "IF", "CALL", "RETURN", "PARAM", "LOAD",
    "STORE", "ADD", "SUB", "MUL", "DIV", "HALT", "ASSIGN", "RET",
    "ARG", "LABEL", "PRINT", "READ", "AND", "OR", "NOT",
    "BLT", "BGT", "BEQ", "BNQ"};

void insertQuad(Quad quad)
{
    QuadList *newQuad = (QuadList *)malloc(sizeof(QuadList));
    newQuad->quad = quad;
    newQuad->next = NULL;

    if (head == NULL)
    {
        head = newQuad;
    }
    else
    {
        QuadList *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newQuad;
    }
}

void createQuad(opKind op, Address addr1, Address addr2, Address addr3)
{
    Quad quad;
    quad.op = op;
    quad.addr1 = addr1;
    quad.addr2 = addr2;
    quad.addr3 = addr3;

    insertQuad(quad);
}

char *newTemp()
{
    char *regTemp = (char *)malloc(10 * sizeof(char));
    sprintf(regTemp, "t%d", tempCount);
    tempCount++;
    if (tempCount > 15)
        tempCount = 0;
    return regTemp;
}

char *newLabel()
{
    char *regLabel = (char *)malloc(10 * sizeof(char));
    sprintf(regLabel, "L%d", labelCount);
    labelCount++;
    return regLabel;
}

static void genStmt(TreeNode *t)
{
    TreeNode *p1, *p2, *p3;
    Address addr1, addr2, addr3;
    char *label, *falseLabel, *trueLabel;

    switch (t->kind.stmt)
    {
    case IfK:
        p1 = t->child[0];
        p2 = t->child[1];
        p3 = t->child[2];

        cGen(p1); // Iff condição
        addr1 = currentAddress;
        falseLabel = newLabel();
        addr2.type = String;
        addr2.var.name = (char *)malloc(strlen(falseLabel) * sizeof(char));
        strcpy(addr2.var.name, falseLabel);

        addr3.type = Empty;

        createQuad(opIF, addr1, addr2, addr3);

        cGen(p2); // bloco if verdadeiro
        if (p3 != NULL)
        { // bloco else
            trueLabel = newLabel();
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(trueLabel) * sizeof(char));
            strcpy(addr1.var.name, trueLabel);

            addr2.type = Empty;
            addr3.type = Empty;
            createQuad(opGOTO, addr1, addr2, addr3);

            aux1.type = String;
            aux1.var.name = (char *)malloc(strlen(falseLabel) * sizeof(char));
            strcpy(aux1.var.name, falseLabel);
            createQuad(opLABEL, aux1, addr2, addr3);

            cGen(p3); // bloco else
            strcpy(addr1.var.name, trueLabel);

            createQuad(opGOTO, addr1, addr2, addr3);
            createQuad(opLABEL, addr1, addr2, addr3);
        }
        else
        {
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(falseLabel) * sizeof(char));
            strcpy(addr1.var.name, falseLabel);
            addr2.type = Empty;
            addr3.type = Empty;

            createQuad(opGOTO, addr1, addr2, addr3);
            createQuad(opLABEL, addr1, addr2, addr3);
        }


        break;
    case WhileK:
        label = newLabel();
        addr1.type = String;
        addr1.var.name = (char *)malloc(strlen(label) * sizeof(char));
        strcpy(addr1.var.name, label);
        addr2.type = Empty;
        addr3.type = Empty;

        createQuad(opLABEL, addr1, addr2, addr3);

        p1 = t->child[0];
        p2 = t->child[1];

        cGen(p1); // condição
        addr1 = currentAddress;

        falseLabel = newLabel();
        addr2.type = String;
        addr2.var.name = (char *)malloc(strlen(falseLabel) * sizeof(char));
        strcpy(addr2.var.name, falseLabel);

        createQuad(opIF, addr1, addr2, addr3);

        cGen(p2); // bloco while

        addr1.type = String;
        addr1.var.name = (char *)malloc(strlen(label) * sizeof(char));
        strcpy(addr1.var.name, label);
        addr2.type = Empty;
        addr3.type = Empty;

        createQuad(opGOTO, addr1, addr2, addr3);

        aux1.type = String;
        aux1.var.name = (char *)malloc(strlen(falseLabel) * sizeof(char));
        strcpy(aux1.var.name, falseLabel);

        createQuad(opLABEL, aux1, addr2, addr3);

        break;
    case AssignK:
        p1 = t->child[0];
        p2 = t->child[1]; 

        if (p1->child[0] != NULL)
        {
            cGen(p1->child[0]);
            Address indexAddr = currentAddress;

            Address baseAddr;
            baseAddr.type = String;
            baseAddr.var.name = strdup(p1->attr.name);

            char *temp = newTemp();
            Address tempAddr;
            tempAddr.type = String;
            tempAddr.var.name = strdup(temp);

            createQuad(opLOAD, tempAddr, baseAddr, indexAddr);

            cGen(p2);
            Address rhsAddr = currentAddress;

            addr3.type = Empty;

            createQuad(opASSIGN, tempAddr, rhsAddr, addr3);
            createQuad(opSTORE, baseAddr, tempAddr, addr3);
        }
        else
        {
            cGen(p1);
            addr1 = currentAddress;
            var = aux2;

            cGen(p2);
            addr2 = currentAddress;

            addr3.type = Empty;

            createQuad(opASSIGN, addr1, addr2, addr3);
            createQuad(opSTORE, var, addr1, addr3);
        }
        break;

    case ReturnINT:
        p1 = t->child[0];
        cGen(p1);
        addr1 = currentAddress;
        addr2.type = Empty;
        addr3.type = Empty;

        createQuad(opRETURN, addr1, addr2, addr3);
        break;
    case ReturnVOID:

        addr1.type = Empty;
        addr2.type = Empty;
        addr3.type = Empty;

        createQuad(opRETURN, addr1, addr2, addr3);
        break;
    default:
        break;
    }
}

static void genExp(TreeNode *t)
{
    TreeNode *p1, *p2, *p3, *k;
    Address addr1, addr2, addr3;
    char *temp;

    switch (t->kind.exp)
    {
    case OpK:
        p1 = t->child[0];
        p2 = t->child[1];
        cGen(p1);
        addr1 = currentAddress;
        cGen(p2);
        addr2 = currentAddress;

        temp = newTemp();
        aux1.type = String;
        aux1.var.name = (char *)malloc(strlen(temp) * sizeof(char));
        strcpy(aux1.var.name, temp);

        switch (t->attr.op)
        {
        case SOM:
            createQuad(opADD, aux1, addr1, addr2);
            break;
        case SUB:
            createQuad(opSUB, aux1, addr1, addr2);
            break;
        case MUL:
            createQuad(opMUL, aux1, addr1, addr2);
            break;
        case DIV:
            createQuad(opDIV, aux1, addr1, addr2);
            break;
        case MEN:
            createQuad(opBLT, aux1, addr1, addr2);
            break;
        case MMI:
            createQuad(opBLT, aux1, addr1, addr2);
            break;
        case MAI:
            createQuad(opBGT, aux1, addr1, addr2);
            break;
        case IGU:
            createQuad(opEQUAL, aux1, addr1, addr2);
            break;
        case DIF:
            createQuad(opBNT, aux1, addr1, addr2);
            break;
        default:
            break;
        }

        currentAddress = aux1;

        break;
    case ConstK:
        currentAddress.type = constINT;
        currentAddress.var.val = t->attr.val;

        break;
    case IdK:
        // TODO: verificar se é vetor
        p1 = t->child[0];
        if (p1 != NULL)
        {
            temp = newTemp();
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(temp) * sizeof(char));
            strcpy(addr1.var.name, temp);

            addr2.type = String;
            addr2.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
            strcpy(addr2.var.name, t->attr.name);

            cGen(p1);
            addr3 = currentAddress;

            createQuad(opLOAD, addr1, addr2, addr3);

            currentAddress = addr1;
            // var = addr2;
        }
        else
        {
            temp = newTemp();
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(temp) * sizeof(char));
            strcpy(addr1.var.name, temp);

            addr2.type = String;
            addr2.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
            strcpy(addr2.var.name, t->attr.name);

            aux2 = addr2;
            currentAddress = addr1;

            addr3.type = Empty;

            createQuad(opLOAD, addr1, addr2, addr3);
        }

        break;
    case VarDeclK:
        addr1.type = String;
        addr1.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
        strcpy(addr1.var.name, t->attr.name);

        addr2.type = String;
        addr2.var.name = (char *)malloc(strlen(varEscopo) * sizeof(char));
        strcpy(addr2.var.name, varEscopo);

        addr3.type = Empty;

        createQuad(opALLOC, addr1, addr2, addr3);
        break;
    case VetDeclK:
        addr1.type = String;
        addr1.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
        strcpy(addr1.var.name, t->attr.name);

        addr2.type = String;
        addr2.var.name = (char *)malloc(strlen(varEscopo) * sizeof(char));
        strcpy(addr2.var.name, varEscopo);

        addr3.type = constINT;
        addr3.var.val = t->child[1]->attr.val;

        createQuad(opALLOC, addr1, addr2, addr3);

        break;
    case VarParamK:
        k = t;
        while (t != NULL)
        {
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(t->child[0]->attr.name) * sizeof(char));
            strcpy(addr1.var.name, t->child[0]->attr.name);

            addr2.type = String;
            addr2.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
            strcpy(addr2.var.name, t->attr.name);

            addr3.type = String;
            addr3.var.name = (char *)malloc(strlen(varEscopo) * sizeof(char));
            strcpy(addr3.var.name, varEscopo);

            createQuad(opARG, addr1, addr2, addr3);

            t = t->sibling;
        }

        while (k != NULL)
        {
            temp = newTemp();
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(temp) * sizeof(char));
            strcpy(addr1.var.name, temp);

            aux2.type = String;
            aux2.var.name = (char *)malloc(strlen(k->attr.name) * sizeof(char));
            strcpy(aux2.var.name, k->attr.name);

            addr3.type = Empty;

            createQuad(opLOAD, addr1, aux2, addr3);

            k = k->sibling;
        }

        break;
    case VetParamK:
        k = t;
        while (t != NULL)
        {
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(t->child[0]->attr.name) * sizeof(char));
            strcpy(addr1.var.name, t->child[0]->attr.name);

            addr2.type = String;
            addr2.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
            strcpy(addr2.var.name, t->attr.name);

            addr3.type = String;
            addr3.var.name = (char *)malloc(strlen(varEscopo) * sizeof(char));
            strcpy(addr3.var.name, varEscopo);

            createQuad(opARG, addr1, addr2, addr3);

            t = t->sibling;
        }

        while (k != NULL)
        {
            temp = newTemp();
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(temp) * sizeof(char));
            strcpy(addr1.var.name, temp);

            aux2.type = String;
            aux2.var.name = (char *)malloc(strlen(k->attr.name) * sizeof(char));
            strcpy(aux2.var.name, k->attr.name);

            addr3.type = Empty;

            createQuad(opLOAD, addr1, aux2, addr3);

            k = k->sibling;
        }

        break;
    case FunDeclK:
        tempCount = 0;
        strcpy(varEscopo, t->attr.name);

        addr1.type = String;
        addr1.var.name = (char *)malloc(strlen(t->child[0]->attr.name) * sizeof(char));
        strcpy(addr1.var.name, t->child[0]->attr.name);
        addr3.type = Empty;
        addr2.type = String;
        addr2.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
        strcpy(addr2.var.name, t->attr.name);
        createQuad(opFUN, addr1, addr2, addr3);
        genExp(t->child[1]);
        cGen(t->child[2]);
        createQuad(opEND, addr1, addr2, addr3);
        strcpy(varEscopo, "global");
        break;
    case AtivK:

        nparam = 0;
        k = t->child[0];
        while (k != NULL)
        { // PARAMETROS
            genExp(k);

            addr1 = currentAddress;
            addr2.type = Empty;
            addr3.type = Empty;
            createQuad(opPARAM, addr1, addr2, addr3);

            nparam++;
            k = k->sibling;
        }

        if (t->type == INT_TYPE)
        {
            temp = newTemp();
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(temp) * sizeof(char));
            strcpy(addr1.var.name, temp);

            addr2.type = String;
            addr2.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
            strcpy(addr2.var.name, t->attr.name);
            addr3.type = constINT;
            addr3.var.val = nparam;

            createQuad(opCALL, addr1, addr2, addr3);
        }
        else
        {
            temp = newTemp();
            addr1.type = String;
            addr1.var.name = (char *)malloc(strlen(temp) * sizeof(char));
            strcpy(addr1.var.name, temp);

            addr2.type = String;
            addr2.var.name = (char *)malloc(strlen(t->attr.name) * sizeof(char));
            strcpy(addr2.var.name, t->attr.name);

            addr3.type = constINT;
            addr3.var.val = nparam;
            createQuad(opCALL, addr1, addr2, addr3);
        }
        nparam = 0;
        currentAddress = addr1;
        aux1 = currentAddress;
        break;
    default:
        break;
    }
}

static void cGen(TreeNode *t)
{
    if (t != NULL)
    {
        switch (t->nodekind)
        {
        case StmtK:
            genStmt(t);
            break;
        case ExpK:
            genExp(t);
            break;
        default:
            break;
        }

        cGen(t->sibling);
    }
}

void printCodeGen()
{
    FILE *file = fopen("codigo_intermediario.txt", "w");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    QuadList *q = head;
    if (q == NULL)
    {
        fprintf(file, "Nenhum código intermediário gerado.\n");
        fclose(file);
        return;
    }

    do
    {
        fprintf(file, "(%s,", opKindStr[q->quad.op]);
        switch (q->quad.addr1.type)
        {
        case Empty:
            fprintf(file, "___,");
            break;
        case constINT:
            fprintf(file, "%d,", q->quad.addr1.var.val);
            break;
        case String:
            fprintf(file, "%s,", q->quad.addr1.var.name);
            break;
        default:
            break;
        }
        switch (q->quad.addr2.type)
        {
        case Empty:
            fprintf(file, "___,");
            break;
        case constINT:
            fprintf(file, "%d,", q->quad.addr2.var.val);
            break;
        case String:
            fprintf(file, "%s,", q->quad.addr2.var.name);
            break;
        default:
            break;
        }
        switch (q->quad.addr3.type)
        {
        case Empty:
            fprintf(file, "___");
            break;
        case constINT:
            fprintf(file, "%d", q->quad.addr3.var.val);
            break;
        case String:
            fprintf(file, "%s", q->quad.addr3.var.name);
            break;
        default:
            break;
        }
        fprintf(file, ")\n");
        q = q->next;
    } while (q != NULL);
    printf("Codigo intermediario gerado...\n");
    fclose(file);
}

void codeGen(TreeNode *tree)
{
    cGen(tree);
    Address empty;
    empty.type = Empty;
    createQuad(opHALT, empty, empty, empty);

    printCodeGen();
}