#include <iostream>
#include <vector>

#include "Queue.h"
#pragma once
using namespace std;

template<class T>
class Node{
	T data;
	vector<Node<T>*> adjacent;
	public:
		bool visited;
		int n;
		Node(T initData) : data(initData), visited(false),n(0){}
		void addAdjacent(Node<T>& other){
			adjacent.push_back(&other);
			n++;
		}
		T getData(){
			return data;
		}
		Node<T>* getEdge(int edgeNum){
			return adjacent[edgeNum];
		}
};
template<class T>
class GraphCl{
	int n;
	int counter;
	vector<Node<T>*> nodes;
	T input;
	bool iterative;
	public:
		GraphCl(int size=0, bool it=false): n(size), iterative(it){
			counter = 0;
			if (iterative){
				for (int i=0;i<n;i++){
					cout << "Enter data for node " << i << ": ";
					cin >> input; 
					nodes.push_back(new Node<T>(input));
					counter++;
				}
			}
		}
		~GraphCl(){
			for (int i=0;i<counter;i++) 
				delete nodes[i];
		}
	void addNode(T input){
		if (!iterative){
			nodes.push_back(new Node<T>(input));
			cout << "Node #" <<++counter << " added" << endl;
		} else {
			cout << "addNode(): Not possible. Already initialized." << endl;
		}
	}
	void addEdge(int baseNode, int edgeNode){
		if (!(baseNode > counter || edgeNode > counter)) {
			nodes[baseNode]->addAdjacent(*nodes[edgeNode]);
		} else {
			cout << "addEdge(): Indices out of bound!" << endl;
		}
	}
	void printGraph(){
		for (int i=0;i<counter;i++){
			Node<T> *base = nodes[i];
			cout << "Data of node " << i <<": "<< base->getData() <<endl;
			for (int j=0;j<base->n;j++)
				cout << "Edge #"<< j+1 << " of node " << i << ": " << base->getEdge(j) <<endl;
		}
	}
	Node<T>* getNodeAddress(int idx){
		return nodes[idx];
	}
	void visitedFalse(){
		for (int i=0;i<counter;i++){
			nodes[i]->visited = false;
		}
	}
};
