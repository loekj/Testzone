#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Queue.h"
#pragma once
using namespace std;

template<class T>
struct BSTNode{
	T data;
	BSTNode* left;
	BSTNode* right;
	bool visited;
	BSTNode<T>(): left(NULL), right(NULL), visited(false){}
};

template<class T>
class BST{
	private:
		BSTNode<T> *root;
		int rootLeavesCount;
		ofstream dotFile;
		bool switchDot;
		bool setUnvisited;
		void writeEdge(T base, T target){
			dotFile << base << " -> " << target << ";" << endl;
		}
		void traverseTree(BSTNode<T> *current, vector<T> path){
			if(current == NULL){
				if (!switchDot && !setUnvisited){
					for(int i=0;i<path.size();i++) cout << path[i] << " ";
					cout << endl;
					rootLeavesCount++;
				}
			} else {
				if(setUnvisited) current->visited = false;
				if(!switchDot && !setUnvisited) path.push_back(current->data);
				if((current->left == NULL) && (current->right == NULL)) traverseTree(NULL, path);
				else if((current->left == NULL) && (current->right != NULL)) {
					if(switchDot) writeEdge(current->data,(current->right)->data);
					traverseTree(current->right, path);
				}
				else if((current->right == NULL) && (current->left != NULL)) {
					if(switchDot) writeEdge(current->data,(current->left)->data);
					traverseTree(current->left, path);
				}
				else if((current->left != NULL) && (current->right != NULL)) {
					if(switchDot) {
						writeEdge(current->data,(current->right)->data);
						writeEdge(current->data,(current->left)->data);
					}
					traverseTree(current->left, path);
					traverseTree(current->right, path);}
				else {cout << "traverseTree(): Error in node pointers." << endl; exit(0);}
				if((current == root) && !switchDot && !setUnvisited){
					cout << "# of different paths: " << rootLeavesCount << endl;
					rootLeavesCount = 0;
				}
			}
		}
	public:
		BST(): root(NULL), rootLeavesCount(0), switchDot(false), setUnvisited(false) {}
		BST(T arr[],int n): root(NULL), rootLeavesCount(0), switchDot(false), setUnvisited(false) {addNodes(arr,n);}
		void addNodes(T arr[],int n){
			int j=0;
			if (root == NULL){
				root = new BSTNode<T>;
				root->data = arr[0];
				j++;
			}
			for (int i=j;i<n;i++){
				BSTNode<T> *current = root;
				while(true){
					if(arr[i]<=current->data){
						if(current->left == NULL){
							(current->left) = new BSTNode<T>;
							(current->left)->data = arr[i];
							break;
						} else {current = current->left;}
					} else {
						if(current->right == NULL){
							(current->right) = new BSTNode<T>;
							(current->right)->data = arr[i];
							break;
						} else {current = current->right;}						
					}
				}
			}
		}
		void printPathLeaves(BSTNode<T> *current, vector<T> path){
			traverseTree(current, path);
		}
		void writeDot(char fileName[], string label){
			dotFile.open(fileName);
			dotFile << "digraph G {" << endl;
			//dotFile << "graph [ordering=\"out\"];" << endl;
			dotFile << "node [shape=circle];" << endl;
			switchDot = true;
			
			vector<T> path;
			traverseTree(root,path);

			dotFile << "labelloc=\"t\";label=\"" << label << "\";}";
			dotFile.close();
			switchDot = false;
		}
		BSTNode<T>* dfs(BSTNode<T> *current, T key){
			BSTNode<T> *returnValLeft;
			BSTNode<T> *returnValRight;
			if((current != NULL) && (current->visited == false)){
				current->visited = true;
				if (current->data == key){
					setUnvisited = true;
					vector<T> path;
					traverseTree(root,path);
					setUnvisited = false;
					return current;
				}
				returnValLeft = dfs(current->left,key);
				returnValRight = dfs(current->right,key);
				if (returnValLeft != NULL) return returnValLeft; //hence left exploration has priority
				if (returnValRight != NULL) return returnValRight;
				delete returnValLeft; //both point to NULL
				delete returnValRight;
			}
			return NULL;
		}
		BSTNode<T>* bfs(BSTNode<T> *current, T key){
			Queue<BSTNode<T>*> *queue;
			queue = new Queue<BSTNode<T>*>();
			queue->enqueue(current);
			while(!queue->isEmpty()){
				BSTNode<T> *myRoot = queue->dequeue();
				if((myRoot != NULL) && (myRoot->visited == false)){
					myRoot->visited = true;
					if (myRoot->data == key) return myRoot;
					queue->enqueue(myRoot->left);
					queue->enqueue(myRoot->right);
				}
			}
			delete queue;
			setUnvisited = true;
			vector<T> path;
			traverseTree(root,path);
			setUnvisited = false;
			return NULL;			
		}
		BSTNode<T>* returnRoot(){
			return root;
		}
};
