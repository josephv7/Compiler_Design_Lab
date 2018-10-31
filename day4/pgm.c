#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ind = 0;
int len;
char str[100];	
int flag = 1;

int S(){
   if(str[ind] == 'c'){
	ind++;
	if(str[ind] == 'd'){
		printf("Rule: S->cd\n");
		ind++;
		flag = 0;
		return 1;
	}
   }
	
   if(flag==1){
	ind = 0;
	printf("Rule: S->AB\n");
	if(A()){
		if(B()){
			flag = 0;
			return 1;
		}
	}
	if(flag == 1){
		printf("Rule: S->B\n");
		ind = 0;
		if(B()){	
		 return 1;}
	}
	return 0;
   }
      
}

int A(){
   if(str[ind] == 'a'){
	ind++;
	printf("Rule: A->a\n");
	return 1;
   }
   else{
	if(str[ind] == 'b'){
		ind++;
		printf("Rule: A->b\n");
		return 1;
	}
	return 0;
   }
}

int B(){
   if(str[ind] == 'b'){
	ind++;
	printf("Rule: B->b\n");
	return 1;
   }
   else{
	if(str[ind] == 'c'){
		printf("Rule: B->cAd\n");
		ind++;
		if(A()){
			if(str[ind] == 'd'){
				ind++;
				return 1;
			}
			else{
				return 0;
			}
		}
	}
   }
}

void main(){
   printf("\nEnter the string:");
   scanf("%s",str);
   printf("\n");
   len = strlen(str);
   if(S() && ind>=len){
	printf("\n");
	printf("String is Valid\n");
   }
   else{	
	printf("\n");
	if(str[ind] != '\0')
		printf("Mismatch: %c\n",str[ind]);
	printf("String is Invalid!!\n");
   }
}
