#include<iostream>
#include<list>
#include<map>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class LinkedList{
private:
    LinkedList *next;
    LinkedList *prev;
    int key;
    int value;

public:
    LinkedList *head;
    LinkedList *tail;

    LinkedList() {
        prev = NULL;
        next = NULL;
        head = NULL;
        tail = NULL;
    }
    LinkedList *allocate_node(int key, int value) {
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->prev = NULL;
        node->next = NULL;
        node->key = key;
        node->value = value;
        return node;
    }

    void insert_at_tail(int key, int value) {
        if(tail == NULL) {
            LinkedList *node = allocate_node(key, value);
            head = node;
            tail = node;
        } else {
            LinkedList *node = allocate_node(key, value);
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void make_it_tail(LinkedList *node, int key, int value) {
        if(node == NULL) return;
        node->key = key;
        node->value = value;
        if(head == tail) return;
        LinkedList *prevn = node->prev;
        LinkedList *nextn = node->next;
        
        if(prevn != NULL && nextn != NULL) {
            nextn->prev = prevn;
            prevn->next = nextn;
            tail->next = node;
            node->prev = tail;
            node->next = NULL;
            tail = node;
            return;
        }
        
        if(nextn != NULL) {
            nextn->prev = NULL;
            head = nextn;
            tail->next = node;
            node->prev = tail;
            node->next = NULL;
            tail = node;
            return;
        }
        
        if(prevn != NULL) {
            return;
        }
        return;
    }

    int get_value(LinkedList *node) {
        if(node == NULL) return -1;
        else return node->value;
    }
    int get_key(LinkedList *node) {
        if(node == NULL) return -1;
        else return node->key;
    }


};


class LRUCache{
    LinkedList l;
    int capacity;
    int count;
    map<int, LinkedList*> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->count = 0;
    }

    int get(int key) {
        if(mp[key] !=  NULL) {
            int temp_val = l.get_value(mp[key]);
            l.make_it_tail(mp[key], key, temp_val);
            mp[key] = l.tail;
            return l.get_value(l.tail);
        }
	return -1;
    }

    void set(int key, int value) {
        if(mp[key] != NULL) {
            l.make_it_tail(mp[key], key, value);
            mp[key] = l.tail;
            return;
        } else {
            if(count == capacity) {
                int temp_key = l.get_key(l.head);
                l.make_it_tail(l.head, key, value);
                mp[key] = l.tail;
                mp[temp_key] = NULL;
                return;
            } else {
                l.insert_at_tail(key, value);
                mp[key] = l.tail;
                count++;
                return;
            }
        }
    }
};


int main(void) {
	LRUCache l(1);
	l.set(2, 1);
	cout<<l.get(2)<<endl;

	l.set(3, 2);
	cout<<l.get(2)<<endl;

	cout<<l.get(3)<<endl;
	//l.set(3, 12);
	//l.set(4, 13);
	//l.set(5, 14);

	return (0);
}
