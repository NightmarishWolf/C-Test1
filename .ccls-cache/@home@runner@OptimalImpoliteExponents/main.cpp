#include <iostream>

using namespace std;

struct node {
	int data;
	struct node * next;
};

node *head = NULL;

// returning the pointer to the element 
// whose data is less than or equal to input data
struct node *searchNode(int n) {
	if(head == NULL) return head;
	node *cur = head;
	node *prev = head;
	while(cur) {
		if(cur->data == n) return cur;
		if(cur->data > n) return prev;
		prev = cur;
		cur = cur->next;
	}
}

// returning the pointer to the element 
// whose data is equal to input data
struct node *searchNode2(int n) {
	if(head == NULL) return head;
	node *cur = head;
	node *prev = head;
	while(cur) {
		if(cur->data == n) return cur;
		prev = cur;
		cur = cur->next;
	}
	return cur;
}

void addNode(int n) {
	node *newNode = new node;
	newNode->data = n;
	newNode->next = NULL;

	if(head == NULL) {
		head = newNode;
		return;
	}
	node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertNode(int n) {
	node *ptr = searchNode(n);
	node *newNode = new node;
	newNode->data = n;
	node *cur = head;
	while(cur) {
		if(cur == ptr ) {
			newNode->next = cur->next;
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

