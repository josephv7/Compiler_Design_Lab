%{
	#include "y.tab.h"
%}

%%
[0-9]*	{return NUMBER;}
.	{return yytext[0];}
"\n"	{return NEWLINE;}
%%

int yywrap()
{
	printf("error");
}
