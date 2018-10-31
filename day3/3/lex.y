%{
	#include<stdio.h>
%}

%token NUMBER NEWLINE

%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
S:	E NEWLINE	{printf("Output = %d", $1);}
E:	E '+' E	{$$ = $1 + $3;}
 |	E '-' E {$$ = $1 - $3;}
 |	E '*' E	{$$ = $1 * $3;}
 |	E '/' E {$$ = $1 / $3;}
 |	'(' E ')'	{$$ = $2;}
 |	NUMBER	{$$ = $1;}
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
