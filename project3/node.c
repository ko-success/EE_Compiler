
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//todo: define struct NODE
typedef struct NODE{
	char* name;
	struct NODE* parent;
	struct NODE* child;
	struct NODE* prev;
	struct NODE* next;
}NODE;


//MakeNode: make a new node
NODE* MakeNode(char* name){
	struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
	
	newNode->name = (char*)malloc(strlen(name) + 1);
	strcpy(newNode->name, name);

	newNode->parent = NULL;
	newNode->child = NULL;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

// Insert node (parent-child): append a child node to parent node
void InsertChild(NODE* parent_node, NODE* this_node){
	// unexpected input
	if (parent_node == NULL || this_node == NULL) {
		printf("Unexpected Input: InsertChild(%s, %s)\n", parent_node->name, this_node->name);
		return;
	}

	// child가 이미 존재할 경우 기존의 Child를 새로운 child의 next로 넣는다. // 해당 규칙이 필요한가?
	if (parent_node->child != NULL){
		parent_node->child->prev = this_node;
		printf("%s already have child\n", parent_node->name);
	}

	this_node->parent = parent_node;
	this_node->prev = NULL;
	this_node->next = parent_node->child; // 없으면 NULL
	parent_node->child = this_node;
}


// Insert node (prev-next): append a next node to prev node 
void InsertSibling(NODE* prev_node, NODE* this_node){
	// unexpected input
	if (prev_node == NULL || this_node == NULL) {
		printf("Unexpected Input: InsertSibling(%s, %s)\n", prev_node->name, this_node->name);
		return;
	}

	// prev_node에 이미 next node가 존재할 경우 그 사이에 this node를 넣는다.
	if(prev_node->next != NULL){
		// this node가 단일이 아닌 sibling이 있는 경우 해당 list의 끝에 prev node의 next를 넣는다.
		// prev_node->next->prev = this_node;
		printf("%s already have sibling\n", prev_node->name);
	}

	this_node->prev = prev_node;
	prev_node->next = this_node;
}


//Tree walk algorithm - DFS
void WalkTree(NODE* node){
	if (node == NULL) return;

	printf("(");
	printf("%s", node->name);

	// child 순회
	if (node->child != NULL){
		printf("\n");
		WalkTree(node->child);
	}
	printf(")");

	// sibling 순회
	if (node->next != NULL){
		printf("\n");
		WalkTree(node->next);
	}
}