#include <iostream>
#include <string>

#pragma once
using namespace std;

struct LinkedListNode{
	double data;
	LinkedListNode* next;
};

void initLinkedListNode(LinkedListNode *head, double d){
	head->data = d;
	head->next = NULL;
}
void append(LinkedListNode *head, double d){
	LinkedListNode *newLinkedListNode = new LinkedListNode;
	newLinkedListNode->data = d;
	newLinkedListNode->next = NULL;
	LinkedListNode *current = head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newLinkedListNode;
}
void access(LinkedListNode *root, int idx){
	LinkedListNode *current = root;
	int counter = 0;
	try{
		while(current->next != NULL){
			if(counter >= idx){
				cout << "value: " << current->data << endl;
				break;
			}		
			current = current->next;
			counter++;
		}
		if(current->next == NULL && idx >= counter){
			cout << "Last value list: " << current->data << endl;
			string excep = "No such index!";
			throw excep;
		}
	}
	catch(string e){
		cout << "Exception: " << e << endl;
	}
}
