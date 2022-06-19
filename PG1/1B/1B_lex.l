%{
#include "y.tab.h"
extern yylval;
%}

%%
[0-9]+ {
	yylval=atoi(yytext);
	return num;}	/* convert the string to number and send the value*/

[\+\-\*\/] { return yytext[0]; }
[)]	{ return yytext[0]; }
[(]	{ return yytext[0]; }
. {;}
\n { return 0; }
%%


