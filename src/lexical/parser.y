%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern int yylex();
    extern int yylineno; // Adicionando a declaração de yylineno
    extern char *yytext; // Adicionando a declaração de yytext
    void yyerror(const char *s);

    // Declarando yyin para que seja reconhecido
    extern FILE *yyin;

    typedef struct {
        char *str;
    } YYSTYPE;

    #define YYSTYPE YYSTYPE
%}


%union {
    char *str; // Para tokens como ID e NUM
}

%token <str> NUM ID
%token ELSE IF INT RETURN VOID WHILE
%token SOM SUB MUL DIV MEN MMI MIG MAI IGU DIF ATR
%token PEV VIR APA FPA ACO FCO ACH FCH

%%

Program:
    DeclList
;

DeclList:
    Decl DeclList
    | /* epsilon */
;

Decl:
    TypeEspec ID PEV 
    | FunDecl
;

TypeEspec:
    INT
    | VOID
;

FunDecl:
    TypeEspec ID APA Params FPA CompoundDecl
;

Params:
    ParamList
    | VOID
;

ParamList:
    Param VIR ParamList
    | Param
;

Param:
    TypeEspec ID
    | TypeEspec ID ACO FCO
;

CompoundDecl:
    ACH LocalDecl CommandList FCH
;

LocalDecl:
    DeclList
;

CommandList:
    Command CommandList
    | /* epsilon */
;

Command:
    ExpDecl
    | CompoundDecl
    | SelectionDecl
    | IterationDecl
    | ReturnDecl
;

ExpDecl:
    Exp PEV
    | PEV
;

SelectionDecl:
    IF APA Exp FPA Command ELSE Command
    | IF APA Exp FPA Command
;

IterationDecl:
    WHILE APA Exp FPA Command
;

ReturnDecl:
    RETURN PEV
    | RETURN Exp PEV
;

Exp:
    Var ATR Exp
    | SimpleExp
;

Var:
    ID
    | ID ACO Exp FCO
;

SimpleExp:
    SumExp Relational SimpleExp
    | SumExp
;

Relational:
    MEN
    | MIG
    | MAI
    | MMI
    | IGU
    | DIF
;

SumExp:
    SumExp Sum Term
    | Term
;

Sum:
    SOM
    | SUB
;

Term:
    Term Mult Factor
    | Factor
;

Mult:
    MUL
    | DIV
;

Factor:
    APA Exp FPA
    | Var
    | FunCall
    | NUM
;

FunCall:
    ID APA ArgList FPA
;

ArgList:
    ArgList VIR Exp
    | Exp
    | /* epsilon */
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
    } else {
        printf("Erro na análise sintática.\n");
    }

    return 0;
}
