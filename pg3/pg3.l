%{
	#include<stdio.h>
%}

d [0-9]
a [a-zA-Z]
%{
//	int ctr;
%}

%%
void|int|if|else {printf("%s -> keyword\n",yytext);}
(<=)|(>=) {printf("%s -> rel\n",yytext);}
[(){},]
[=+*\-;,<>]
[0-9]* {printf("%s -> number\n",yytext);}
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

