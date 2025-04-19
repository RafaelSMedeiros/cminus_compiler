#include "globals.h"
#include "symtab.h"

char *escopo = "global"; // Escopo atual da análise.

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

static void insertNode(TreeNode *t)
{
    switch (t->nodekind)
    {
    case StmtK:
        switch (t->kind.stmt)
        {
        case ReturnINT:
            if (getFunType(escopo) == VOID_TYPE) {
                printf("ERRO SEMÂNTICO: %s LINHA: %d. A função deve retornar um INT.\n", t->attr.name, t->lineno);
            }
            break;

        case ReturnVOID:
            if (getFunType(escopo) == INT_TYPE) {
                printf("ERRO SEMÂNTICO: %s LINHA: %d. A função não deve retornar um inteiro.\n", t->attr.name, t->lineno);
            }
            break;

        case AssignK:
            if (t->child[1] != NULL && t->child[1]->kind.exp == AtivK) {
                if (getFunType(t->child[1]->attr.name) == VOID_TYPE) {
                    printf("ERRO SEMÂNTICO: %s LINHA: %d. Atribuição inválida. A função '%s' não retorna valor.\n",
                        t->attr.name, t->lineno, t->child[1]->attr.name);
                }
            }
            break;

        default:
            break;
        }
        break;

    case ExpK:
        switch (t->kind.exp)
        {
        case IdK:
            if (st_lookup(t->attr.name) == -1) {
                printf("ERRO SEMÂNTICO: %s LINHA: %d. A variável '%s' não foi declarada.\n",
                    t->attr.name, t->lineno, t->attr.name);
            } else {
                st_insert(t->attr.name, t->lineno, t->type, VAR, escopo);
            }
            break;

        case VarDeclK:
            if (isFunctionName(t->attr.name)) {
                printf("ERRO SEMÂNTICO: %s LINHA: %d. O nome '%s' já foi utilizado como função e não pode ser usado como variável.\n",
                    t->attr.name, t->lineno, t->attr.name);
            }

            if (st_lookup_scope(t->attr.name, escopo) == 0) {
                if (t->type == VOID_TYPE) {
                    printf("ERRO SEMÂNTICO: %s LINHA: %d. A variável '%s' não pode ser do tipo VOID.\n",
                        t->attr.name, t->lineno, t->attr.name);
                }
                st_insert(t->attr.name, t->lineno, t->type, VAR, escopo);
            } else {
                printf("ERRO SEMÂNTICO: %s LINHA: %d. Declaração inválida da variável '%s': já foi declarada no escopo '%s'.\n",
                    t->attr.name, t->lineno, t->attr.name, escopo);
            }
            break;

        case VetDeclK:
            if (isFunctionName(t->attr.name)) {
                printf("ERRO SEMÂNTICO: %s LINHA: %d. O nome '%s' já foi utilizado como função e não pode ser usado como variável.\n",
                    t->attr.name, t->lineno, t->attr.name);
            }

            if (st_lookup(t->attr.name) == -1) {
                if (t->type == VOID_TYPE) {
                    printf("ERRO SEMÂNTICO: %s LINHA: %d. O vetor '%s' não pode ser do tipo VOID.\n",
                        t->attr.name, t->lineno, t->attr.name);
                }
                st_insert(t->attr.name, t->lineno, t->type, VET, escopo);
            }
            break;

        case FunDeclK:
            if (st_lookup(t->attr.name) == -1) {
                st_insert(t->attr.name, t->lineno, t->type, FUN, escopo);
            } else {
                printf("ERRO SEMÂNTICO: %s LINHA: %d. A função '%s' já foi declarada.\n",
                    t->attr.name, t->lineno, t->attr.name);
            }
            break;

        case AtivK:
            if (st_lookup(t->attr.name) == -1 &&
                strcmp(t->attr.name, "input") != 0 &&
                strcmp(t->attr.name, "output") != 0) {
                printf("ERRO SEMÂNTICO: %s LINHA: %d. A função '%s' não foi declarada.\n",
                    t->attr.name, t->lineno, t->attr.name);
            } else {
                st_insert(t->attr.name, t->lineno, t->type, CALL, escopo);
            }
            break;

        case VarParamK:
            st_insert(t->attr.name, t->lineno, t->type, PVAR, escopo);
            break;

        case VetParamK:
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

    if (!main_declared()) {
        printf("ERRO SEMANTICO: A função 'main' não foi declarada no escopo global.\n");
    }

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

int st_lookup_scope(char *name, char *escopoAtual) {
    int h = hash(name);
    BucketList l = hashTable[h];

    while (l != NULL) {
        if ((strcmp(name, l->name) == 0) && (strcmp(escopoAtual, l->escopo) == 0)) {
            return 1; // Encontrado no mesmo escopo
        }
        l = l->next;
    }
    return 0; // Não encontrado no mesmo escopo
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

DataTypes getFunType(char *nome) {
    int h = hash(nome);
    BucketList l = hashTable[h];

    while ((l != NULL)) {
        if (strcmp(nome, l->name) == 0) {
            if (l->idtype == FUN) {
                break;
            }
        }
        l = l->next;
    }
    if (l == NULL) {
        return NULL_TYPE;
    } else {
        return l->type;
    }
}

int main_declared() {
    int h = hash("main");
    BucketList l = hashTable[h];

    while (l != NULL) {
        if (strcmp(l->name, "main") == 0 && strcmp(l->escopo, "global") == 0 && l->idtype == FUN) {
            return 1; // Função main encontrada
        }
        l = l->next;
    }

    return 0; // Não encontrada
}

int isFunctionName(char *name) {
    int h = hash(name);
    BucketList l = hashTable[h];

    while (l != NULL) {
        if (strcmp(name, l->name) == 0 && l->idtype == FUN) {
            return 1;
        }
        l = l->next;
    }
    return 0;
}