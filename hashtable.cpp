#include <iostream>
#include <cmath>

using namespace std;

class Node {
	public:
		string key, value;
		Node* next;

	Node(string a, string b) {
		key = a;
		value = b;
		next = NULL;
	}
};

class LinkedList {
	public:
		Node* start;

	int insertData(string key, string value){
		Node* node_last = start;
		Node* node_temp = start;
		while (node_temp != NULL && node_temp->key != key) {
			node_last = node_temp;
			node_temp = node_temp->next;
		}
		node_last->next = new Node(key, value);

		if (node_temp != NULL) {
			node_last->next->next = node_temp->next;
			delete node_temp;
		}

		return(1);
	}

	void dump() {
		Node* current = start;
		while (current->next != NULL) {
			current = current->next;
			cout << "\nCurrent key " << current->key << " with value " << current->value << "\n";
		}
	}

	string getData(string keyToGet) {
		Node* current = start;
		while (current->next != NULL) {
			current = current->next;
			if (current->key == keyToGet) {
				return(current->value);
			}
		}

		return("Could not find");
	}

	LinkedList() {
		start = new Node("head", "");
	}
};

class Hashtable {
	public:
		LinkedList* table;
		int hash_size;

	int hash(string key) {
		int hash_value = 0;
		for (int i = 0; i < key.length(); i++)
			hash_value += key[i];
		return hash_value % hash_size;
	}

	int insertData(string key, string value) {
		int hash_value = hash(key);
		table[hash_value].insertData(key, value);
		return 1;
	}

	string getData(string key) {
		int hash_value = hash(key);
		return(table[hash_value].getData(key));
	}

	void dump(string key) {
		int hash_value = hash(key);
		table[hash_value].dump();
	}

    Hashtable(int size) {
         table = new LinkedList[size];
         hash_size = size;
    }

    ~Hashtable() {
    	delete [] table;
    }

};

int main() {

Hashtable test(3);
test.insertData("testdfsersdf", "womp");
test.insertData("dffd", "tim");
test.insertData("dff", "PLO");
test.insertData("testdfsdfsersdf", "123");
test.insertData("fsda", "321");
test.insertData("testdfsersdf", "3233");

test.insertData("wer", "1");
test.insertData("tre", "2");
test.insertData("dff", "PLO2");

test.dump("testdfsersdf");

cout << "\n\n\n\n" << test.getData("dff");
  return 0;
}

