#include "globals.h"
#include "util.h"

#define INDENT indentno += 2
#define UNINDENT indentno -= 2

static int indentno = 0;

int lineno = 1;  // Definição única da variável

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */

void printToken(TokenType token, const char *tokenString) {
    switch (token) {
    case IF:
        printf("%s\n", tokenString);
        break;
    case ELSE:
        printf( "%s\n", tokenString);
        break;
    case INT:
        printf( "%s\n", tokenString);
        break;
    case RETURN:
        printf( "%s\n", tokenString);
        break;
    case VOID:
        printf( "%s\n", tokenString);
        break;
    case WHILE:
        printf( "%s\n", tokenString);
        break;
    case SOM:
        printf( "+\n");
        break;
    case SUB:
        printf( "-\n");
        break;
    case MUL:
        printf( "*\n");
        break;
    case MEN:
        printf( "<\n");
        break;
    case MMI:
        printf( "<=\n");
        break;
    case MAI:
        printf( ">\n");
        break;
    case IGU:
        printf( "==\n");
        break;
    case DIF:
        printf( "!=\n");
        break;
    case ATR:
        printf( "=\n");
        break;
    case PEV:
        printf( ";\n");
        break;
    case VIR:
        printf( ",\n");
        break;
    case APA:
        printf( "(\n");
        break;
    case FPA:
        printf( ")\n");
        break;
    case ACO:
        printf( "[\n");
        break;
    case FCO:
        printf( "]\n");
        break;
    case ACH:
        printf( "(\n");
        break;
    case FCH:
        printf( "}\n");
        break;
    case NUM:
        printf("NUM, val = %s\n", tokenString);
        break;
    case ID:
        printf("ID, nome = %s\n", tokenString);
        break;
    default:
        printf( "Token Desconhecido: %d\n", token);
    }
}

TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    // fprintf(listing,"Out of memory error at line %d\n",lineno);
    printf("Out of memory error at line\n");
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
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
TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    // fprintf(listing,"Out of memory error at line %d\n",lineno);
        printf("Out of memory error at line\n");
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    // t->lineno = lineno;
    // t->type = Void;
  }
  return t;
}

char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = (char*) malloc(n);
  if (t==NULL)
    printf("Out of memory error at line\n");
    // fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

static void printSpaces(void) {
    int i;
    for (i = 0; i < indentno; i++) {
        printf(" ");
    }
}

void printTree(TreeNode *tree) {
    int i;
    INDENT;
    while (tree != NULL) {
        printf(" %d", tree->lineno);
        printSpaces();
        if (tree->nodekind == StmtK) {
            switch (tree->kind.stmt) {
            case IfK:
                printf( "If\n");
                break;
            case WhileK:
                printf( "While\n");
                break;
            case AssignK:
                printf( "Assign: \n");
                break;
            case ReturnINT:
                printf( "Return\n");
                break;
            case ReturnVOID:
                printf( "Return\n");
                break;
            default:
                printf( "Unknown StmtNode kind\n");
                break;
            }
        } else if (tree->nodekind == ExpK) {
            switch (tree->kind.exp) {
            case OpK:
                printf( "Op: ");
                printToken(tree->attr.op, "\0");
                break;
            case ConstK:
                printf( "Const: %d\n", tree->attr.val);
                break;
            case IdK:
                printf( "Id: %s\n", tree->attr.name);
                break;
            case VarDeclK:
                printf( "Var: %s\n", tree->attr.name);
                break;
            case FunDeclK:
                printf( "Func: %s\n", tree->attr.name);
                break;
            case AtivK:
                printf( "Chamada da Função: %s\n", tree->attr.name);
                break;
            case TypeK:
                printf( "Tipo: %s\n", tree->attr.name);
                break;
            case VarParamK:
                printf( "Parametro: %s\n", tree->attr.name);
                break;
            case VetParamK:
                printf( "Parametro: %s\n", tree->attr.name);
                break;
            case VetorK:
                printf( "Vetor: %s", tree->attr.name);
                break;
            default:
                printf( "Unknown ExpNode kind: %d\n", tree->nodekind);
                break;
            }
        } else {
            printf( "Unknown Node kind\n");
        }

        for (i = 0; i < MAXCHILDREN; i++) {
            printTree(tree->child[i]);
        }
        tree = tree->sibling;
    }
    UNINDENT;
}