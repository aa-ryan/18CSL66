lex main.l
cc lex.yy.c -ll -w
./a.out input_file.c output_file.c
