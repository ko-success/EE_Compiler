yacc -d project3.y -v
lex project3.l
cc lex.yy.c y.tab.c -o problem2
