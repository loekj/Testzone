#include <iostream>
#include <string>

#pragma once
using namespace std;

struct DLinkedListNode{
	double data;
	DLinkedListNode* next;
	DLinkedListNode* prev;
};

void initDLinkedListNode(DLinkedListNode *head, double d){
	head->data = d;
	head->next = NULL;
	head->prev = NULL;
}
void appendHead(DLinkedListNode *head, double d){
	DLinkedListNode *newDLinkedListNode = new DLinkedListNode;
	newDLinkedListNode = (DLinkedListNode*)malloc(sizeof(DLinkedListNode));
	newDLinkedListNode->data = d;
	newDLinkedListNode->next = NULL;
	DLinkedListNode *current = head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newDLinkedListNode;
	newDLinkedListNode->prev = current;
}
void appendTail(DLinkedListNode *tail, double d){
	DLinkedListNode *newDLinkedListNode = new DLinkedListNode;
	newDLinkedListNode = (DLinkedListNode*)malloc(sizeof(DLinkedListNode));
	newDLinkedListNode->data = d;
	newDLinkedListNode->prev = NULL;
	DLinkedListNode *current = tail; 
	while(current->prev != NULL){
		current = current->prev;
	}
	current->prev = newDLinkedListNode;
	newDLinkedListNode->next = current;
}
void access(DLinkedListNode *root, int idx){
	DLinkedListNode *current = root;
	while(current->prev != NULL){
		current = current->prev;
	}
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
