%{

#include<stdio.h>

%}

%%

[a-zA-Z]+ {printf("Word : %s\n",yytext);}

[0-9]+ {printf("Number : %s\n",yytext);}

[^ \t\na-zA-Z0-9]+|[a-zA-Z0-9]+ {printf("Others : %s\n",yytext);}

. ;

%%

int main(void)

{

yylex();

printf("\n");

return 0;

}

int yywrap()
{return(1);}