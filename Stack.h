#include <iostream>
#include <string>

#pragma once
using namespace std;

struct StackNode{
	double data;
	StackNode* next;
};
void initStack(StackNode *root, double d){
	root->data = d;
	root->next = NULL;
}
void append(StackNode *root, double d){
	StackNode *newStackNode = new StackNode;
	newStackNode = (StackNode*)malloc(sizeof(StackNode));
	newStackNode->data = d;
	newStackNode->next = NULL;
	StackNode *current = root;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newStackNode;
}
void pop(StackNode *root){
	StackNode *current = root;
	StackNode *current2 = root;
	if(current2->next != NULL){
		current2 = current2->next;
	}
	while(current2->next != NULL){
		current = current->next;
		current2 = current2->next;
	}
	free(current2);
	current->next = NULL;
}
void get_top(StackNode *root){
	int counter = 1;
	StackNode *current = root;
	while(current->next != NULL){
		current = current->next;
		counter++;
	}
	cout << "Top value is: " << current->data << ", and there is/are " << counter << " item(s) on the stack.\n";
}
