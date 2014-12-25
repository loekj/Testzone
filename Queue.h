#include <iostream>
#include <vector>

#pragma once
using namespace std;

template<class T>
struct queueNode{
	T data;
	queueNode<T> *next;
	queueNode(){
		next = NULL;
	}
};
template<class T>
class Queue{
	queueNode<T> *first;
	queueNode<T> *last;
	public:
		Queue(){
			first = NULL;
			last = NULL;
		}
		void enqueue(T d);
		T dequeue();
		void peek();
		void printPath();
		bool isEmpty();
};
template<class T>
bool Queue<T>::isEmpty(){
	if (first == NULL){
		return true;
	}
	return false;
}
template<class T>
void Queue<T>::printPath(){
	int depth = 0;
	queueNode<T> *current = first;
	while (current->next != NULL){
		cout << "depth: " << depth++ << ", nextpointer of current: " << current->next << endl;
		current = current->next;
	}
	cout << "depth: " << depth << ", nextpointer of current: " << current->next << endl;
}
template<class T>
void Queue<T>::enqueue(T d){
	queueNode<T> *newqueueNode = new queueNode<T>;
	newqueueNode->data = d;
	if(first == NULL){
		last = newqueueNode;
		first = last;
	} else {
		last->next = newqueueNode;
		last = newqueueNode;
	}
}
template<class T>
T Queue<T>::dequeue(){
	T val;
	try{
		if (first != NULL){
			val = first->data;
			if (first->next != NULL){
				queueNode<T> *temp = first->next;
				delete first;
				first = temp;
			} else {
				delete first;
				first = NULL;
				last = NULL;
			}
			return val;
		} else {
			string excep = "Queue is already empty!";
			throw excep;
		}
	} catch(string e){
		cout << "Exception raised: " << e << endl;
	}
	return 0;
}
template<class T>
void Queue<T>::peek(){
	try {
		if (first == NULL){
			string excep = "Queue is already empty!";
			throw excep;
		} else {
			cout << "Value at top: " << first->data << endl;
		}
	} catch(string e){
		cout << "Exception raised: " << e << endl;
	}
}
