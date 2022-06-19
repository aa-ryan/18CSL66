lex 1B_lex.l
yacc -d 1B_yacc.y
gcc lex.yy.c y.tab.c -ll -w  # using -w to turn off implicit declaration warning being treated as error in compiler
./a.out
