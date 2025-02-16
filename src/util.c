#include "globals.h"
#include "util.h"

#define INDENT indentno += 2
#define UNINDENT indentno -= 2
static int indentno = 0;

#define SIZE 211
#define SHIFT 4
static int hash(char *key) // Função de hash
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

int lineno = 1; // Contador de linhas no código fonte
char *escopo = "global"; // Escopo atual da análise.

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

// Função para percorrer a árvore sintática
static void traverse(TreeNode *t, void (*preProc)(TreeNode *), void (*postProc)(TreeNode *)) 
{
    if (t != NULL) {
 
        preProc(t); 
        {
            if (t->kind.exp == FunDeclK) { // Se for uma declaração de função, atualiza o escopo
                escopo = t->attr.name;
            }

            int i;
            for (i = 0; i < MAXCHILDREN; i++) 
                traverse(t->child[i], preProc, postProc);
        }

        if (t->child[0] != NULL && t->kind.exp == FunDeclK) { // Volta para o escopo global
            escopo = "global";
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

static void insertNode(TreeNode *t) // Função para inserir um nó na tabela de símbolos
{
    switch (t->nodekind) // Verifica o tipo de nó
    {
    case StmtK: 
        switch (t->kind.stmt) // Verifica o tipo de declaração
        {
        case ReturnINT: // Se for um retorno de inteiro
            st_insert("return", t->lineno, t->type, RETT, escopo);
            break;

        case ReturnVOID: // Se for um retorno de void
            st_insert("return", t->lineno, t->type, RETT, escopo);
            break;

        default:
            break;
        }
        break;

    case ExpK:
        switch (t->kind.exp) // Verifica o tipo de expressão
        {
        case IdK: // Se for uma variável
            if (st_lookup(t->attr.name) == -1)
            { // Se não estiver na tabela, insere
                st_insert(t->attr.name, t->lineno, t->type, VAR, escopo);
            }
            else
                /* already in table, so ignore location,
                   add line number of use only */
                st_insert(t->attr.name, t->lineno, t->type, VAR, escopo);
            break;

        case VarDeclK: // Se for uma declaração de variável
            if (st_lookup(t->attr.name) == -1)
            { // Se não estiver na tabela, insere
                st_insert(t->attr.name, t->lineno, t->type, VAR, escopo);
            }
            break;

        case VetorK: // Se for um vetor
            st_insert(t->attr.name, t->lineno, t->type, VET, escopo);
            break;

        case FunDeclK: // Se for uma declaração de função
            if (st_lookup(t->attr.name) == -1)
            { // Se não estiver na tabela, insere
                st_insert(t->attr.name, t->lineno, t->type, FUN, escopo);
            }
            break;

        case AtivK: // Se for uma chamada de função
            st_insert(t->attr.name, t->lineno, t->type, CALL, escopo);
            break;

        case VarParamK: // Se for um parâmetro de variável
            st_insert(t->attr.name, t->lineno, t->type, PVAR, escopo);
            break;

        case VetParamK: // Se for um parâmetro de vetor
            st_insert(t->attr.name, t->lineno, t->type, VET, escopo);
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
}

void buildSymtab(TreeNode *syntaxTree) // Função para construir a tabela de símbolos
{
    traverse(syntaxTree, insertNode, nullProc);
    printSymTab();
}

typedef struct LineListRec // Estrutura da lista de linhas
{
    int lineno;
    struct LineListRec *next; // Ponteiro para a próxima linha
} *LineList;

typedef struct BucketListRec // Estrutura da lista da lista
{
    char *name;
    IDTypes idtype;
    DataTypes type;
    char *escopo;
    LineList lines;

    int memloc;
    struct BucketListRec *next;
} *BucketList;

// Tabela hash de símbolos
static BucketList hashTable[SIZE];

void st_insert(char *name, int lineno, DataTypes type, IDTypes idtype, char *escopo) // Função para inserir um nó na tabela de símbolos
{
    int h = hash(name); // Calcula o hash
    BucketList l = hashTable[h]; // Pega o nó da tabela

    while ((l != NULL) && (strcmp(name, l->name) != 0)) // Percorre a tabela ate encontrar o nó
        l = l->next;

    if (l == NULL) // Se não encontrou, insere
    {
        l = (BucketList)malloc(sizeof(struct BucketListRec));
        l->name = name;
        l->lines = (LineList)malloc(sizeof(struct LineListRec));
        l->lines->lineno = lineno;
        l->lines->next = NULL;
        l->type = type;
        l->idtype = idtype;
        l->escopo = escopo;
        l->next = hashTable[h];
        hashTable[h] = l;
    }
    else // Se encontrou, atualiza as linhas
    {
        LineList t = l->lines;
        while (t->next != NULL)
            t = t->next;
        t->next = (LineList)malloc(sizeof(struct LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;
    }
}


int st_lookup(char *name) // Função para procurar um noh na tabela de símbolos
{
    int h = hash(name); // Calcula o hash
    BucketList l = hashTable[h]; // Pega o nó da tabela

    while ((l != NULL) && (strcmp(name, l->name) != 0)) // Percorre a tabela ate encontrar o noh
        l = l->next;

    if (l == NULL) // Se nao encontrou, retorna -1
        return -1;
    else
        return l->memloc;
}

void printSymTab() { // Função para imprimir a tabela de símbolos
    int i;
    printf("%-14s %-10s %-8s %-14s %s\n", "Variable Name", "DataType", "IDType", "Scope", "Line Numbers");
    printf("-------------- ---------- -------- -------------- -------------------------\n");

    for (i = 0; i < SIZE; ++i) { // Percorre a tabela
        if (hashTable[i] != NULL) { // Se o noh não for nulo 
            BucketList l = hashTable[i]; // Pega o noh

            while (l != NULL) { // Percorre a lista ate o final
                LineList t = l->lines;

                // Nome da variável
                printf("%-14s ", l->name);

                // Tipo de dado (INT ou VOID)
                printf("%-10s ", (l->type == INT_TYPE) ? "INT" : "VOID");

                // Tipo de identificador
                printf("%-8s ", 
                    (l->idtype == VAR)  ? "VAR"  :
                    (l->idtype == PVAR) ? "PVAR" :
                    (l->idtype == FUN)  ? "FUN"  :
                    (l->idtype == CALL) ? "CALL" :
                    (l->idtype == VET)  ? "VET"  : "RET");

                // Escopo
                printf("%-14s ", l->escopo);

                // Lista de números de linha
                while (t != NULL) {
                    printf("%-3d ", t->lineno);  // Espaço fixo para alinhar corretamente
                    t = t->next;
                }

                printf("\n");
                l = l->next;
            }
        }
    }
}

