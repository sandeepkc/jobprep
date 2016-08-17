#include<iostream>
using namespace std;

class node {
	public :
		int value;
		node *next;	
};

class linkedList {
	public:
	node *head;

	linkedList() {
		head = NULL;
	}

	//Insert after n and return the pointer to the last node
	node *insert_after(node *n, int val) {
		node *a = new node();
		a->next = NULL;
		a->value = val;

		if(n == NULL) {
			head = a;
			return head;
		} else {
			n ->next = a;		
			return a;
		}
	}
	void print_list() {
		node *temp = head;
		while(temp != NULL) {
			cout<<temp->value<<" ";
			temp = temp->next;
		}
	}
};

int main(void) {
	linkedList *ll = new linkedList();
	node *a = ll->insert_after(ll->head, 1);		
	a = ll->insert_after(a, 2);
	a = ll->insert_after(a, 3);
	a = ll->insert_after(a, 4);
	a = ll->insert_after(a, 5);
	a = ll->insert_after(a, 6);

	ll->print_list();

	return (0);
}
