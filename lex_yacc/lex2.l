%{

#include<stdio.h>

int yylineno;

%}

%%

^(.*)\n {printf("%d\t%s",++yylineno,yytext);}

. ;

\n ;

%%

int main(void) {

yylex();

printf("\n");

return 0;

}

int yywrap()
{return(1);}