yacc -d problem2.y -v
lex problem2.l
cc lex.yy.c y.tab.c -o project2_2
