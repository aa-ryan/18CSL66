lex 2_lex.l
yacc -d 2_yacc.y
cc lex.yy.c y.tab.c -ll -w
./a.out
