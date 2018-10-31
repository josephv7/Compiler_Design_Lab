%{
	#include<stdio.h>
%}

%token NUMBER NEWLINE

%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
S:	E NEWLINE	{printf("Valid Input\n");}
E:	E '+' E	
 |	E '-' E 
 |	E '*' E	
 |	E '/' E 
 |	'(' E ')'	
 |	NUMBER	
 ;
%%
void main()
{
	yyparse();
}
int yyerror()
{
	printf("Invalid Input\n");
}
