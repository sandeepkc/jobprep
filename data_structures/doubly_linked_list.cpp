#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node {
	int value;
	struct node *next;
	struct node *prev;
};

typedef struct node *nodeptr;

nodeptr create_node(int val) {
	nodeptr p = (nodeptr)malloc(sizeof(struct node));
	p->value = val;
	p->next = NULL;
	p->prev = NULL;
	return (p);
}

void insert_node(int val, nodeptr head){
	nodeptr p = head;
	while(p->next != NULL){
		p = p->next;
	}
		
	nodeptr temp = create_node(val);
	p->next = temp;
	temp->prev = p;
}

void print_list(nodeptr head) {
	nodeptr p = head;
	while(p->next != NULL) {
		printf("%d ", p->value);
		p = p->next;
	}
	
	printf("%d ", p->value);
}

int length(node *n) {
	int len = 0;
	if(n == NULL) return len;

	//The node pointer may point to any node in the
	//list, so handle that case.
	node *prevTemp = n->prev, *nextTemp = n->next;

	//Increase count for the given node
	len++;

	//Measure the left part of the list
	while(prevTemp != NULL) {
		len++;
		prevTemp = prevTemp->prev;
	}

	//Measure the right part of the list
	while(nextTemp != NULL) {
		len++;
		nextTemp = nextTemp->next;
	}

	return len;
}

int main(void) {
	nodeptr head = create_node(0);
	insert_node(1, head);
	insert_node(2, head);
	insert_node(3, head);
	insert_node(4, head);

	print_list(head);

	cout<<"len = "<<length(head)<<endl;
	cout<<"len = "<<length(head->next)<<endl;
	cout<<"len = "<<length(head->next->next)<<endl;
	cout<<"len = "<<length(head->next->next->next->next)<<endl;

	cout<<"len = "<<length(NULL)<<endl;
	
	nodeptr h1 = create_node(4);

	cout<<"len = "<<length(h1)<<endl;

	return(0);
}
