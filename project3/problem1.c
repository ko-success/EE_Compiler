#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.c"

int main(){
	// generate node
	struct NODE* head = MakeNode("A");
	struct NODE* B = MakeNode("B");
	struct NODE* C = MakeNode("C");
	struct NODE* D = MakeNode("D");
	struct NODE* E = MakeNode("E");
	struct NODE* F = MakeNode("F");
	struct NODE* G = MakeNode("G");
	struct NODE* H = MakeNode("H");
	struct NODE* I = MakeNode("I");

	// generate tree structure
	// depth(1)
	InsertChild(head, B);
	InsertSibling(B, E);
	InsertSibling(E, I);
	// depth(2)
	InsertChild(B, C);
	InsertSibling(C, D);
	InsertChild(E, F);
	InsertSibling(F, G);
	InsertSibling(G, H);

	WalkTree(head);

	free(head);
	free(B);
	free(C);
	free(D);
	free(E);
	free(F);
	free(G);
	free(H);
	free(I);

	return 0;
}