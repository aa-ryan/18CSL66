%{
#include<stdio.h>
int a_count = 0, text, n;
%}
%token A B

%%
	s: X B {
		if (a_count != n) 
			{
				printf("Invalid count of a\n");
				exit(0);
			}
	}
	X: X T | T
	T: A {a_count++;}
%%
int main() {
	printf("Enter the value of N: ");
	scanf("%d", &n);
	printf("Enter the String: \n");
	scanf("%d", &text);
	yyparse();
	printf("Valid String");
}

int yyerror() {
	printf("Invalid String");
	exit(0);
}
