%{
	#include "y.tab.h"
%}

id [a-z]([a-z]|[0-9])*

%%
"switch"	{return SWITCH;}
"("		{return OBRACKET;}
")"		{return CBRACKET;}
"\n"		{return NEWLINE;}
"{"		{return COBRACKET;}
"case"		{return CASE;}
"default"	{return DEFAULT;}
[0-9]*		{return NUMBER;}
":"		{return COLON;}
"break"		{return BREAK;}
";"		{return SEMICOLON;}
"}"		{return CCBRACKET;}
{id}		{return IDENTIFIER;}
%%
	
int yywrap()
{
	printf("Invalid");
}
