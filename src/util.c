#include "globals.h"
#include "util.h"

#define INDENT indentno += 2
#define UNINDENT indentno -= 2
static int indentno = 0;

int lineno = 1; // Contador de linhas no código fonte

// Função para imprimir o token
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
    case DIV:
        printf("/\n");
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

// Função para criar um novo noh de declaração
TreeNode *newStmtNode(StmtKind kind) 
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        printf("Out of memory error at line\n"); // Erro de memória
    else
    {
        for (i = 0; i < MAXCHILDREN; i++) // Inicializa os filhos como null
            t->child[i] = NULL;
        t->sibling = NULL; // Inicializa o irmão como null
        t->nodekind = StmtK;
        t->kind.stmt = kind;
    }
    return t;
}

// Função para criar um novo noh de expressão
TreeNode *newExpNode(ExpKind kind) 
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        printf("Out of memory error at line\n"); // Erro de memória
    else
    {
        for (i = 0; i < MAXCHILDREN; i++) // Inicializa os filhos como null
            t->child[i] = NULL;
        t->sibling = NULL; // Inicializa o irmão como null
        t->nodekind = ExpK;
        t->kind.exp = kind;
    }
    return t;
}

char *copyString(char *s) // Função para copiar uma string
{
    int n;
    char *t;
    if (s == NULL)
        return NULL;
    n = strlen(s) + 1;
    t = (char *)malloc(n);
    if (t == NULL)
        printf("Out of memory error at line\n");
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

void printTree(TreeNode *tree) // Função para imprimir a árvore sintática
{
    int i;
    INDENT;
    while (tree != NULL)
    {
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
