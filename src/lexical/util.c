#include "globals.h"
#include "util.h"

#define INDENT indentno += 2
#define UNINDENT indentno -= 2

static int indentno = 0;

#define SIZE 211
#define SHIFT 4
static int hash(char *key)
{
    int temp = 0;
    int i = 0;
    while (key[i] != '\0')
    {
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

int lineno = 1; // Definição única da variável

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */

void printToken(TokenType token, const char *tokenString)
{
    switch (token)
    {
    case IF:
        printf("%s\n", tokenString);
        break;
    case ELSE:
        printf("%s\n", tokenString);
        break;
    case INT:
        printf("%s\n", tokenString);
        break;
    case RETURN:
        printf("%s\n", tokenString);
        break;
    case VOID:
        printf("%s\n", tokenString);
        break;
    case WHILE:
        printf("%s\n", tokenString);
        break;
    case SOM:
        printf("+\n");
        break;
    case SUB:
        printf("-\n");
        break;
    case MUL:
        printf("*\n");
        break;
    case MEN:
        printf("<\n");
        break;
    case MMI:
        printf("<=\n");
        break;
    case MAI:
        printf(">\n");
        break;
    case IGU:
        printf("==\n");
        break;
    case DIF:
        printf("!=\n");
        break;
    case ATR:
        printf("=\n");
        break;
    case PEV:
        printf(";\n");
        break;
    case VIR:
        printf(",\n");
        break;
    case APA:
        printf("(\n");
        break;
    case FPA:
        printf(")\n");
        break;
    case ACO:
        printf("[\n");
        break;
    case FCO:
        printf("]\n");
        break;
    case ACH:
        printf("(\n");
        break;
    case FCH:
        printf("}\n");
        break;
    case NUM:
        printf("NUM, val = %s\n", tokenString);
        break;
    case ID:
        printf("ID, nome = %s\n", tokenString);
        break;
    default:
        printf("Token Desconhecido: %d\n", token);
    }
}

TreeNode *newStmtNode(StmtKind kind)
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        // fprintf(listing,"Out of memory error at line %d\n",lineno);
        printf("Out of memory error at line\n");
    else
    {
        for (i = 0; i < MAXCHILDREN; i++)
            t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = StmtK;
        t->kind.stmt = kind;
        // t->lineno = lineno;
    }
    return t;
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode *newExpNode(ExpKind kind)
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        // fprintf(listing,"Out of memory error at line %d\n",lineno);
        printf("Out of memory error at line\n");
    else
    {
        for (i = 0; i < MAXCHILDREN; i++)
            t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = ExpK;
        t->kind.exp = kind;
        // t->lineno = lineno;
        // t->type = Void;
    }
    return t;
}

char *copyString(char *s)
{
    int n;
    char *t;
    if (s == NULL)
        return NULL;
    n = strlen(s) + 1;
    t = (char *)malloc(n);
    if (t == NULL)
        printf("Out of memory error at line\n");
    // fprintf(listing,"Out of memory error at line %d\n",lineno);
    else
        strcpy(t, s);
    return t;
}

static void printSpaces(void)
{
    int i;
    for (i = 0; i < indentno; i++)
    {
        printf(" ");
    }
}

void printTree(TreeNode *tree)
{
    int i;
    INDENT;
    while (tree != NULL)
    {
        printf(" %d", tree->lineno);
        printSpaces();
        if (tree->nodekind == StmtK)
        {
            switch (tree->kind.stmt)
            {
            case IfK:
                printf("If\n");
                break;
            case WhileK:
                printf("While\n");
                break;
            case AssignK:
                printf("Assign: \n");
                break;
            case ReturnINT:
                printf("Return\n");
                break;
            case ReturnVOID:
                printf("Return\n");
                break;
            default:
                printf("Unknown StmtNode kind\n");
                break;
            }
        }
        else if (tree->nodekind == ExpK)
        {
            switch (tree->kind.exp)
            {
            case OpK:
                printf("Op: ");
                printToken(tree->attr.op, "\0");
                break;
            case ConstK:
                printf("Const: %d\n", tree->attr.val);
                break;
            case IdK:
                printf("Id: %s\n", tree->attr.name);
                break;
            case VarDeclK:
                printf("Var: %s\n", tree->attr.name);
                break;
            case FunDeclK:
                printf("Func: %s\n", tree->attr.name);
                break;
            case AtivK:
                printf("Chamada da Função: %s\n", tree->attr.name);
                break;
            case TypeK:
                printf("Tipo: %s\n", tree->attr.name);
                break;
            case VarParamK:
                printf("Parametro: %s\n", tree->attr.name);
                break;
            case VetParamK:
                printf("Parametro: %s\n", tree->attr.name);
                break;
            case VetorK:
                printf("Vetor: %s", tree->attr.name);
                break;
            default:
                printf("Unknown ExpNode kind: %d\n", tree->nodekind);
                break;
            }
        }
        else
        {
            printf("Unknown Node kind\n");
        }

        for (i = 0; i < MAXCHILDREN; i++)
        {
            printTree(tree->child[i]);
        }
        tree = tree->sibling;
    }
    UNINDENT;
}

static void
traverse(TreeNode *t,
         void (*preProc)(TreeNode *),
         void (*postProc)(TreeNode *))
{
    if (t != NULL)
    {
        preProc(t);
        {
            int i;
            for (i = 0; i < MAXCHILDREN; i++)
                traverse(t->child[i], preProc, postProc);
        }
        postProc(t);
        traverse(t->sibling, preProc, postProc);
    }
}

static void nullProc(TreeNode *t)
{
    if (t == NULL)
        return;
    else
        return;
}

static void insertNode(TreeNode *t)
{
    switch (t->nodekind)
    {
    case StmtK:
        switch (t->kind.stmt)
        {
        case ReturnINT:
            st_insert("return", t->lineno);
            break;

        case ReturnVOID:
            st_insert("return", t->lineno);
            break;

        default:
            break;
        }
        break;

    case ExpK:
        switch (t->kind.exp)
        {
        case IdK:
            if (st_lookup(t->attr.name) == -1)
            { // Se não estiver na tabela, insere
                st_insert(t->attr.name, t->lineno);
            }
            else
                /* already in table, so ignore location,
                   add line number of use only */
                st_insert(t->attr.name, t->lineno);
            break;

        case VarDeclK:
            if (st_lookup(t->attr.name) == -1)
            { // Se não estiver na tabela, insere
                st_insert(t->attr.name, t->lineno);
            }
            break;

        case VetorK:
            st_insert(t->attr.name, t->lineno);
            break;

        case FunDeclK:
            // if (strcmp(t->child[1]->attr.name, "void") == 0) {
            //     TIPO = VOIDTYPE;
            // } else {
            //     TIPO = INTTYPE;
            // }
            if (st_lookup(t->attr.name) == -1)
            { // Se não estiver na tabela, insere
                st_insert(t->attr.name, t->lineno);
            }
            break;

        case AtivK:
            st_insert(t->attr.name, t->lineno);
            break;

        case VarParamK:
            st_insert(t->attr.name, t->lineno);
            break;

        case VetParamK:
            st_insert(t->attr.name, t->lineno);
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
}

void buildSymtab(TreeNode *syntaxTree)
{
    traverse(syntaxTree, insertNode, nullProc);
    printSymTab();
}

typedef struct LineListRec
{
    int lineno;
    struct LineListRec *next;
} *LineList;

typedef struct BucketListRec
{
    char *name;
    LineList lines;
    int memloc; /* memory location for variable */
    struct BucketListRec *next;
} *BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

void st_insert(char *name, int lineno)
{
    int h = hash(name);
    BucketList l = hashTable[h];
    while ((l != NULL) && (strcmp(name, l->name) != 0))
        l = l->next;
    if (l == NULL) /* variable not yet in table */
    {
        l = (BucketList)malloc(sizeof(struct BucketListRec));
        l->name = name;
        l->lines = (LineList)malloc(sizeof(struct LineListRec));
        l->lines->lineno = lineno;
        l->lines->next = NULL;
        l->next = hashTable[h];
        hashTable[h] = l;
    }
    else /* found in table, so just add line number */
    {
        LineList t = l->lines;
        while (t->next != NULL)
            t = t->next;
        t->next = (LineList)malloc(sizeof(struct LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;
    }
} /* st_insert */

int st_lookup(char *name)
{
    int h = hash(name);
    BucketList l = hashTable[h];
    while ((l != NULL) && (strcmp(name, l->name) != 0))
        l = l->next;
    if (l == NULL)
        return -1;
    else
        return l->memloc;
}

void printSymTab()
{
    int i;
    printf("Variable Name   Line Numbers\n");
    printf("-------------   ------------\n");
    for (i = 0; i < SIZE; ++i)
    {
        if (hashTable[i] != NULL)
        {
            BucketList l = hashTable[i];
            while (l != NULL)
            {
                LineList t = l->lines;
                printf("%-14s ", l->name);
                while (t != NULL)
                {
                    printf("%4d ", t->lineno);
                    t = t->next;
                }
                printf("\n");
                l = l->next;
            }
        }
    }
} /* printSymTab */