%{
    #include<string>
    #include<iostream>

    using namespace std;

    FILE *out ;
	int linha;
%}

NUM [0-9]
ID [a-zA-Z][a-zA-Z0-9]*
WHITESPACE [ ]
LINEBREAK [\n]
TAB [\t]

%option yylineno

%%

{LINEBREAK}

else {fprintf(out,"(%d,ELSE,\"%s\")\n",yylineno ,yytext);} 

if {fprintf(out,"(%d,IF,\"%s\")\n",yylineno ,yytext);} 

int {fprintf(out,"(%d,INT,\"%s\")\n",yylineno ,yytext);} 

return {fprintf(out,"(%d,RETURN,\"%s\")\n",yylineno ,yytext);} 

void {fprintf(out,"(%d,VOID,\"%s\")\n",yylineno ,yytext);} 

while {fprintf(out,"(%d,WHILE,\"%s\")\n",yylineno ,yytext);} 

"+" {fprintf(out,"(%d,SOMA,\"%s\")\n",yylineno,yytext);}

"-" {fprintf(out,"(%d,SUB,\"%s\")\n",yylineno,yytext);}

"*" {fprintf(out,"(%d,MULTI,\"%s\")\n",yylineno,yytext);}

"/" {fprintf(out,"(%d,DIV,\"%s\")\n",yylineno,yytext);}

"<" {fprintf(out,"(%d,MENOR,\"%s\")\n",yylineno,yytext);}

"<=" {fprintf(out,"(%d,MENORIGUAL,\"%s\")\n",yylineno,yytext);}

">" {fprintf(out,"(%d,MAIOR,\"%s\")\n",yylineno,yytext);}

">=" {fprintf(out,"(%d,MAIORIGUAL,\"%s\")\n",yylineno,yytext);}

"==" {fprintf(out,"(%d,IGUAL,\"%s\")\n",yylineno,yytext);}

"!=" {fprintf(out,"(%d,DIFERENTE,\"%s\")\n",yylineno,yytext);}

"=" {fprintf(out,"(%d,ATRIB,\"%s\")\n",yylineno,yytext);}

";" {fprintf(out,"(%d,PEVIRGULA,\"%s\")\n",yylineno,yytext);}

"," {fprintf(out,"(%d,VIRGULA,\"%s\")\n",yylineno,yytext);}

"(" {fprintf(out,"(%d,ABREPAR,\"%s\")\n",yylineno,yytext);}

")" {fprintf(out,"(%d,FECHAPAR,\"%s\")\n",yylineno,yytext);}

"[" {fprintf(out,"(%d,ABRECOL,\"%s\")\n",yylineno,yytext);}

"]" {fprintf(out,"(%d,FECHACOL,\"%s\")\n",yylineno,yytext);}

"{" {fprintf(out,"(%d,ABRECHAVE,\"%s\")\n",yylineno,yytext);}

"}" {fprintf(out,"(%d,FECHACHAVE,\"%s\")\n",yylineno,yytext);}

{WHITESPACE}+|{LINEBREAK}|{TAB}+
 
{NUM}+ {fprintf(out,"(%d,NUM,\"%s\")\n",yylineno,yytext);}

{NUM}+{ID}+ {fprintf(out,"(%d,ERROR,\"%s\")\n",yylineno,yytext); return 0;}

{ID}+ {fprintf(out,"(%d,ID,\"%s\")\n",yylineno,yytext);}

. {fprintf(out,"(%d,ERROR,\"%s\")\n",yylineno,yytext); return 0;}

%%

int yywrap();

int main(int argc, char *argv[]){
    FILE *arquivo = fopen(argv[1],"r");
    if (!arquivo) {
      cout << "Arquivo inexistente" << endl;
      return -1;
    }
    yyin = arquivo;
    out = fopen(argv[2],"w");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}