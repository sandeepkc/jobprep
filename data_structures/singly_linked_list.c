#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node *nodeptr;

nodeptr create_node(int val) {
	nodeptr p = (nodeptr)malloc(sizeof(struct node));
	p->value = val;
	p->next = NULL;
	return (p);
}

void insert_node(int val, nodeptr head){
	nodeptr p = head;
	while(p->next != NULL){
		p = p->next;
	}
		
	nodeptr temp = create_node(val);
	p->next = temp;
}

void print_list(nodeptr head) {
	nodeptr p = head;
	while(p->next != NULL) {
		printf("%d ", p->value);
		p = p->next;
	}
	
	printf("%d ", p->value);
}

int main(void) {
	nodeptr head = create_node(0);
	insert_node(1, head);
	insert_node(2, head);
	insert_node(3, head);
	insert_node(4, head);

	print_list(head);

	return(0);
}
