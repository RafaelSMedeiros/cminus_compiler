%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern int yylex();
    extern int yylineno; 
    extern char *yytext; 
    void yyerror(const char *s);
    extern FILE *yyin;

    #define MAXCHILDREN 3 

    typedef struct TreeNode {
        struct TreeNode *child[MAXCHILDREN];
        struct TreeNode *sibling;           
        int lineno;                          
        char *type;                          
        char *value;                         
    } TreeNode;

    #define YYSTYPE TreeNode *
    static TreeNode * arvoreSintatica; /* Armazena a árvore sintática */



%}

%token NUM ID
%token ELSE IF INT RETURN VOID WHILE
%token SOM SUB MUL DIV MEN MMI MIG MAI IGU DIF ATR
%token PEV VIR APA FPA ACO FCO ACH FCH


%%

Programa:
    DeclLista { arvoreSintatica = $1; }
;

DeclLista:
    Decl DeclLista { 
        YYSTYPE t = $1;
            if (t != NULL){
                while (t->sibling != NULL)
                    t = t->sibling;
                t->sibling = $2;
                $$ = $1;
              }
            else $$ = $2;
        }
    | /* epsilon */ { $$ = NULL; }
;

Decl:
    TipoEspec ID PEV 
    | FunDecl { $$ = $1; }
;

TipoEspec:
    INT
    | VOID
;

FunDecl:
    TipoEspec ID APA Params FPA CompostoDecl {
        
    }
;

Params:
    ParamLista { $$ = $1; }
    | VOID
;

ParamLista:
    Param VIR ParamLista
    | Param
;

Param:
    TipoEspec ID
    | TipoEspec ID ACO FCO
;

CompostoDecl:
    ACH LocalDecl ComandoLista FCH
;

LocalDecl:
    DeclLista { $$ = $1; }
;

ComandoLista:
    Comando ComandoLista
    | /* epsilon */ { $$ = NULL; }
;

Comando:
    ExpDecl { $$ = $1; }
    | CompostoDecl { $$ = $1; }
    | SelecaoDecl { $$ = $1; }
    | IteracaoDecl { $$ = $1; }
    | RetornoDecl { $$ = $1; }
;

ExpDecl:
    Exp PEV
    | PEV
;

SelecaoDecl:
    IF APA Exp FPA Comando ELSE Comando
    | IF APA Exp FPA Comando
;

IteracaoDecl:
    WHILE APA Exp FPA Comando
;

RetornoDecl:
    RETURN PEV
    | RETURN Exp PEV
;

Exp:
    Var ATR Exp
    | SimplesExp { $$ = $1; }
;

Var:
    ID
    | ID ACO Exp FCO
;

SimplesExp:
    SomaExp Relacional SomaExp
    | SomaExp { $$ = $1; }
;

Relacional:
    MEN
    | MMI
    | MIG
    | MAI
    | IGU
    | DIF
;

SomaExp:
    SomaExp Soma Termo
    | Termo { $$ = $1; }
;

Soma:
    SOM
    | SUB
;

Termo:
    Termo Mult Fator
    | Fator { $$ = $1; }
;

Mult:
    MUL
    | DIV
;

Fator:
    APA Exp FPA
    | Var { $$ = $1; }
    | Ativacao { $$ = $1; }
    | NUM
;

Ativacao:
    ID APA ArgLista FPA
;

ArgLista:
    ArgLista VIR Exp
    | Exp { $$ = $1; }
    | /* epsilon */ { $$ = NULL; }
;

%%

// Função para tratamento de erros
void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: '%s' LINHA: %d\n", yytext, yylineno);
}

void printTree(TreeNode *tree, int level) {
    if (tree == NULL) {
        return;
    }
    
    // Imprime a indentação correspondente ao nível da árvore
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    
    // Imprime o tipo do nó e, se houver, seu valor
    if (tree->value) {
        printf("%s: %s (Linha: %d)\n", tree->type, tree->value, tree->lineno);
    } else {
        printf("%s (Linha: %d)\n", tree->type, tree->lineno);
    }
    
    // Chama recursivamente para os filhos
    for (int i = 0; i < MAXCHILDREN; i++) {
        printTree(tree->child[i], level + 1);
    }
    
    // Chama recursivamente para os irmãos
    printTree(tree->sibling, level);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    yyin = file;  // Redefine yyin para o arquivo

    printf("Analisando o arquivo: %s\n", argv[1]);
    int parse_result = yyparse();  // Chama o analisador gerado pelo Bison

    fclose(file);  // Fecha o arquivo após a análise

    // Verifica o resultado da análise
    if (parse_result == 0) {
        printf("Análise sintática bem-sucedida! A sintaxe está correta.\n");
        printTree(arvoreSintatica, 0);
    } else {
        printf("Erro na análise sintática.\n");
    }

    return 0;
}
