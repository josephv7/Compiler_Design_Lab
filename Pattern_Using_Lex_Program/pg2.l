%{
//program to find identiers using lex tool
#include<stdio.h>
#include<string.h>
%}

%%
0((01)|(10))* {printf("Valid.\n");}
.* {printf("Invalid.\n");}
%%

void main()
{
	printf("Enter pattern: \n");
	yylex();
}
int yywrap()
{
        return 0;
}


