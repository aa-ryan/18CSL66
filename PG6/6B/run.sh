lex main.l
yacc -d main.y
cc lex.yy.c y.tab.c -ll -w
./a.out file.c

