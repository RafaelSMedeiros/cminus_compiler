%{
    #define YYPARSER /* distinguishes Yacc output from other code files */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "globals.h"
    #include "util.h"

    #define MAXTOKENLEN 40
    extern char tokenID[MAXTOKENLEN+1];  // Declaração externa de tokenID


    extern int yylex();
    extern int yylineno; 
    extern char *yytext; 
    void yyerror(const char *s);
    extern FILE *yyin;

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
    DeclLista Decl { 
        YYSTYPE t = $1;
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $2;
            $$ = $1;
        }
        else $$ = $2;
    } | /* epsilon */ { $$ = NULL; }
;

Decl:
    TipoEspec varID PEV {
        $$ = $2;
        $$->attr.name = $2->attr.name;
        $2->child[0] = $1;
    } | FunDecl { $$ = $1; }
;

varID:
    ID {
        $$ = newExpNode(IdK);
        $$->attr.name = copyString(tokenID);
        $$->kind.exp = IdK;
    } 

TipoEspec:
    INT {
        $$ = newExpNode(TypeK);
        $$->attr.name = copyString(yytext);
        $$->kind.exp = TypeK; 
    } | VOID {
        $$ = newExpNode(TypeK);
        $$->attr.name = copyString(yytext);
        $$->kind.exp = TypeK;
    }
;

FunDecl:
    TipoEspec funID APA Params FPA CompostoDecl {
        printf("aqui: %s\n", yytext);
        $$ = newExpNode(FunDeclK);
        $$->kind.exp = FunDeclK;
        $$->attr.name = $2->attr.name;
        $$->child[0] = $1;
        $$->child[1] = $4;
        $$->child[2] = $6;
    }
;

funID:
    ID {
        $$ = newExpNode(IdK);
        $$->attr.name = copyString(tokenID);
        $$->kind.exp = IdK;
    }
;

Params:
    ParamLista { $$ = $1; }
    | VOID {
        $$ = newExpNode(TypeK);
        $$->attr.name = copyString(tokenID);
        $$->kind.exp = TypeK;
    }
;

ParamLista:
    ParamLista VIR Param {
        YYSTYPE t = $1;
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $3;
            $$ = $1;
        }
    } | Param { $$ = $1; }
;

Param:
    TipoEspec ID {
        $$ = newExpNode(VarParamK);
        $$->attr.name = copyString(tokenID);
        $$->kind.exp = VarParamK;
        $$->child[0] = $1;
    } | TipoEspec ID ACO FCO {
        $$ = newExpNode(VetParamK);
        $$->attr.name = copyString(yytext);
        $$->kind.exp = VetParamK;
        $$->child[0] = $1;
    }
;

CompostoDecl:
    ACH LocalDecl ComandoLista FCH {
        YYSTYPE t = $2;
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $3;
            $$ = $2;
        }
        else $$ = $3;
    }
;

LocalDecl:
    DeclLista { $$ = $1; }
;

ComandoLista:
    ComandoLista Comando {
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

Comando:
    ExpDecl { $$ = $1; }
    | CompostoDecl { $$ = $1; }
    | SelecaoDecl { $$ = $1; }
    | IteracaoDecl { $$ = $1; }
    | RetornoDecl { $$ = $1; }
;

ExpDecl:
    Exp PEV { $$ = $1; }
    | PEV
;

SelecaoDecl:
    IF APA Exp FPA Comando ELSE Comando {
        $$ = newStmtNode(IfK);
        $$->attr.name = copyString(yytext);
        $$->kind.stmt = IfK;
        $$->child[0] = $3;
        $$->child[1] = $5;
        $$->child[2] = $7;
    }
    | IF APA Exp FPA Comando {
        $$ = newStmtNode(IfK);
        $$->attr.name = copyString(yytext);
        $$->kind.stmt = IfK;
        $$->child[0] = $3;
        $$->child[1] = $5;
    }
;

IteracaoDecl:
    WHILE APA Exp FPA Comando {
        $$ = newStmtNode(WhileK);
        $$->attr.name = copyString(yytext);
        $$->kind.stmt = WhileK;
        $$->child[0] = $3;
        $$->child[1] = $5;
    }
;

RetornoDecl:
    RETURN PEV { $$ = newStmtNode(ReturnVOID); }
    | RETURN Exp PEV {
        $$ = newStmtNode(ReturnINT);
        $$->child[0] = $2;
    }
;

Exp:
    Var ATR Exp {
        $$ = newStmtNode(AssignK);
        $$->kind.stmt = AssignK;
        $$->attr.name= $1->attr.name;
        $$->child[0] = $1;
        $$->child[1] = $3;
    } | SimplesExp { $$ = $1; }
;

Var:
    ID {
        $$ = newExpNode(IdK);
        $$->attr.name = copyString(tokenID);

    } | ID ACO Exp FCO {
        $$ = newExpNode(IdK);
        $$->attr.name = $1->attr.name;
        $$->child[0] = $3;
    }
;

SimplesExp:
    SomaExp Relacional SomaExp {
        $$ = newStmtNode(AssignK);
        $$ = $2;
        $$->child[0] = $1;
        $$->child[1] = $3;
    }
    | SomaExp { $$ = $1; }
;

Relacional:
    MEN {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    } | MMI {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    } | MIG {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    } | MAI {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    } | IGU {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    } | DIF  {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    }
;

SomaExp:
    SomaExp Soma Termo {
        $$ = $2;
        $$->child[0] = $1;
        $$->child[1] = $3;
    } | Termo { $$ = $1; }
;

Soma:
    SOM {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    } | SUB {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    }
;

Termo:
    Termo Mult Fator {
        $$ = $2;
        $$->child[0] = $1;
        $$->child[1] = $3;
    } | Fator { $$ = $1; }
;

Mult:
    MUL {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    } | DIV {
        $$ = newExpNode(OpK);
        $$->attr.name = copyString(yytext);
    }
;

Fator:
    APA Exp FPA { $$ = $2; } 
    | Var { $$ = $1; }
    | Ativacao { $$ = $1; }
    | NUM {
        $$ = newExpNode(ConstK);
        $$->attr.name = copyString(yytext);
        $$->attr.val = atoi(yytext);
    }
;

Ativacao:
    funID APA ArgLista FPA {
        $$ = newExpNode(AtivK);
        $$->attr.name = $1->attr.name;
        $$->kind.exp = AtivK;
        $$->child[0] = $3;
    } | funID APA FPA {
        $$ = newExpNode(AtivK);
        $$->attr.name = $1->attr.name;
        $$->kind.exp = AtivK;
    }
;

ArgLista:
    ArgLista VIR Exp {
        YYSTYPE t = $1;
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $3;
            $$ = $1;
        }
        else $$ = $3;
    } | Exp { $$ = $1; }
;

%%

// Função para tratamento de erros
void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: '%s' LINHA: %d\n", yytext, yylineno);
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
        printTree(arvoreSintatica);
    } else {
        printf("Erro na análise sintática.\n");
    }

    return 0;
}
