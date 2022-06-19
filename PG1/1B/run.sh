lex 1B_lex.l
yacc -d 1B_yacc.y
gcc lex.yy.c y.tab.c -ll
./a.out
