#include <iostream>
#include <string>

#pragma once
using namespace std;

template<class T>
class HashEntry{
	private:
		int key;
		T *data;
	public:
		HashEntry() {};
		void putData(T input, int keyVal){
			// if (data != NULL){
			// 	cout << "Warning: Overriding data for key " << key << endl;
			// }
			key = keyVal;
			cout << "IN PUTDATA" << endl;
			data = input;
			cout << "IN PUTDATA" << endl;
		}
		T getData(){
			return data;
		}
};

template<class T>
class Hash{
	private:
		int myFunc; //0 = modulus, 1 = multiplicative
		//T tempData;
		size_t sizeHash;
		HashEntry<T> **table;
	public:
		//Hash():
		Hash(int func, size_t size): myFunc(func), sizeHash(size-1) {
			table = new HashEntry<T>*[sizeHash];
			for (int i=0;i<sizeHash;i++) table[i] = NULL;
		}
		int hashFunc(int key){
			try{
				if (myFunc == 0){
					cout << "KEY % SIZE: " << key % sizeHash << endl;
					return key % sizeHash;
				} else if (myFunc == 1){
					//do stuff
				} else {string excep = "No such hash function!"; throw excep;}
			} catch(string e) {cout << "Hash::hashFunc(): Exception Raised: " << e << endl; exit(0);}
			return -1;
		}
		void addEntry(T data, int key){
			int myHash = hashFunc(key);
			//cout << "myHash: " << myHash << endl;
			table[myHash]->putData(*data, key);
		}
		T getEntry(int key){
			int myHash = hashFunc(key);
			return table[myHash]->getData();
		}

		//hash class, representing table
};
