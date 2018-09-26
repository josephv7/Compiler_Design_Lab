#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  void main() {

    int state = 0;
    char buffer[200];
    char ch, sub;
    int key_flag = 0, i;

    FILE * fptr;
    fptr = fopen("input.txt", "r");
    int p = 0;
    char keywords_array[7][20] = {
      "main",
      "if",
      "for",
      "break",
      "while",
      "continue",
      "do"
    };

    while ((ch = getc(fptr)) != EOF) {
      switch (state) {
      case 0:
        if (ch == '<')
          state = 1;
        else if (ch == '>')
          state = 4;
        else if (ch == '!')
          state = 7;
        else if (isalnum(ch)) {
          //printf("%c is char",ch);
          if (isalpha(ch))
            state = 11;
          else if (isdigit(ch))
            state = 9;
        }
        break;
      case 1:
        if (ch == '=')
          printf("<= is a relational operator\n");
        else
          fseek(fptr, -1, SEEK_CUR);
        state = 0;
        break;

      case 4:
        if (ch == '=')
          printf(">= is a relational operator\n");
        else
          fseek(fptr, -1, SEEK_CUR);
        state = 0;
        break;
      case 7:
        if (ch == '=') {
          printf("!= is a relational operator\n");
          state = 0;
        }
        break;
      case 11: //printf("\n case11");
        fseek(fptr, -2, SEEK_CUR);
        p = 0;
        char b = getc(fptr);
        //printf("%c is b",b);
        buffer[0] = b;
        p = 1;
        //printf("\n%c is buffer",buffer[0]);
        //printf("\n%c is next2",getc(fptr));
        //buffer[1] = getc(fptr);
        //p = 2;
        //printf("\n next %c",getc(fptr));
        ////fseek(fptr,-1,SEEK_CUR);
        while (isalpha(sub = getc(fptr))) {
          //if(sub == ' ' || sub == '\0')
          //	break;
          //else{
          if (sub != EOF)
            buffer[p++] = sub;
          //printf("\n %s is sub",sub);
          //}
        }

        buffer[p] = '\0';
        //printf("\n %s is buffer",buffer);
        state = 12;
        fseek(fptr, -1, SEEK_CUR);
        break;

      case 12: //printf("\n case12");
        key_flag = 0;
        //printf("\n%s full buffer",buffer);
        for (i = 0; i < 7; i++) { //printf("\n buffer in loop %s",buffer);
          //printf("\n keyword %s",keywords_array[i]);
          if (strcmp(buffer, keywords_array[i]) == 0)
            key_flag = 1;
          break;

        }

        if (key_flag == 1)
          printf("\n%s is keyword\n", buffer);
        else
          printf("\n%s is an identifier\n", buffer);
        strcpy(buffer, "");
        state = 0;
        break;

      case 9:
        fseek(fptr, -2, SEEK_CUR);
        char e = getc(fptr);
        // printf("\n case 9 %c",e);
        p = 0;
        buffer[p++] = e;
        while (isalnum(sub = getc(fptr))) {
          buffer[p++] = sub;
        }

        buffer[p] = '\0';
        state = 0;
        fseek(fptr, -1, SEEK_CUR);

        printf("%s is a number", buffer);
        //strcpy(buffer,'');
        break;
      }
    }
  }
