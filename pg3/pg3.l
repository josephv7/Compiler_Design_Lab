%{
//program to find identiers using lex tool
#include<stdio.h>
#include<string.h>
%}

%%
[a-z]([a-z0-9])* {printf("Identifier %s.",yytext);}
.* {;}
%%

void main()
{
FILE *fptr,*temp;
char t,ts[20];
int i=0;
fptr=fopen("rel.txt","r");
temp=fopen("temp.txt","w+");
t=fgetc(fptr);
while(t!=EOF)
{
	if(t==' '||t=='\n'||t==',')
	{
		ts[i]='\0';
		fprintf(temp,"%s\n",ts);
		i=0;
		t=fgetc(fptr);
	}
	else
	{
		ts[i]=t;
		i++;
		t=fgetc(fptr);
	}
}
fclose(temp);
fclose(fptr);
yyin=fopen("temp.txt","r");
yylex();
fclose(yyin);
}
int yywrap()
{
	return 0;
}
