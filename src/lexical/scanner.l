%{
    #include "parser.tab.h"
    #include "globals.h"
    #include "util.h"

    #define MAXTOKENLEN 40
    char tokenID[MAXTOKENLEN+1];  // Variável global


    extern YYSTYPE yylval;  // Garantir que o Bison use YYSTYPE
%}

NUM [0-9]+
ID [a-zA-Z][a-zA-Z0-9]*
newline \n

%option yylineno

%%

"else" { return ELSE; }
"if" { return IF; }
"int" { return INT; }
"return" { return RETURN; }
"void" { return VOID; }
"while" { return WHILE; }

"+" { return SOM; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"<" { return MEN; }
"<=" { return MMI; }
">" { return MIG; }
">=" { return MAI; }
"==" { return IGU; }
"!=" { return DIF; }
"=" { return ATR; }
";" { return PEV; }
"," { return VIR; }
"(" { return APA; }
")" { return FPA; }
"[" { return ACO; } 
"]" { return FCO; }
"{" { return ACH; }
"}" { return FCH; }

{NUM} { return NUM; }
{ID} {
    strncpy(tokenID, yytext, MAXTOKENLEN);  // Aqui o Flex preenche tokenID
    return ID;
}

{newline} { lineno++; }
[ \t]+ ;  // Ignorar espaços e tabs

. {
    printf("ERRO LÉXICO: '%s' LINHA: %d\n", yytext, yylineno);  // Exibe o token inválido
    return 0;  // Retorna um valor inválido para sinalizar o erro
}
%%

int yywrap() {
    return 1;
}
