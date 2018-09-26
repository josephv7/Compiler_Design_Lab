%{
	#include<stdio.h>
%}

d [0-9]
a [a-zA-Z]
%{
	int ctr;
%}

%%
void|int|if|else
[(){}]
[=+*\-;,<>]
[0-9]
\"(\\.|[^"\\])*\"
{a}({a}|{d})* {printf("%s -> identifier\n",yytext);}
%%

main(){
    yyin = fopen("rel.txt", "r");
    yylex();
    return 1;
}

int yywrap()
{
        return 0;
}

