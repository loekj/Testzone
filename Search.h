#include <iostream>

#include "Graph.h"
#pragma once

template<class T>
Node<T>* dfs(Node<T>* rootNode, T key){
	Node<T> *returnVal;
	if(rootNode->visited == false){
		rootNode->visited = true;
		if (rootNode->getData() == key)
			return rootNode;
		for(int i=0;i<rootNode->n;i++){
			returnVal = dfs(rootNode->getEdge(i),key);
			if (returnVal != NULL)
				return returnVal;
			delete returnVal;
		}
	}
	return NULL;
}

template<class T>
Node<T>* bfs(Node<T>* rootNode, T key){
	Queue<Node<T>*> *queue;
	queue = new Queue<Node<T>*>();
	queue->enqueue(rootNode);
	while(!queue->isEmpty()){
		Node<T> *myRoot = queue->dequeue();
		if(myRoot->visited == false){
			myRoot->visited = true;
			if (myRoot->getData() == key)
				return myRoot;
			for (int i=0;i<myRoot->n;i++)
				queue->enqueue(myRoot->getEdge(i));
		}
	}
	delete queue;
	return NULL;
}
