%{
    #include "parser.tab.h"
    #include <string>
    #include <iostream>
    #include <cstring> // Para strdup

    using namespace std;

    extern YYSTYPE yylval;  // Garantir que o Bison use YYSTYPE
%}

NUM [0-9]+
ID [a-zA-Z][a-zA-Z0-9]*

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

{NUM} { yylval.str = strdup(yytext); return NUM; }
{ID}  { yylval.str = strdup(yytext); return ID; }

[ \t\n]+ ;  // Ignorar espaços, tabs e quebras de linha

. {
    printf("ERRO LÉXICO: '%s' LINHA: %d\n", yytext, yylineno);  // Exibe o token inválido
    return 0;  // Retorna um valor inválido para sinalizar o erro
}
%%

int yywrap() {
    return 1;
}
