%{
#include<stdio.h>
int com=0;
%}
%s COMMENT
%%
"/*" { BEGIN COMMENT; }
<COMMENT>"*/" { BEGIN 0; com++;}
<COMMENT>\n { com++; }
<COMMENT>. {;}
\/\/.* {; com++;}
.|\n { fprintf(yyout,"%s",yytext); }
%%

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		printf("usage : ./a.out in.file out.file \n");
		exit(0);
	}
		yyin=fopen(argv[1],"r");
		yyout=fopen(argv[2],"w");
		yylex();
		printf("\n number of comments are = %d\n",com);
}
int yywrap()
{
	return 1;
}
