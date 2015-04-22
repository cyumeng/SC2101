#include <iostream>
#include "linkedlist.h"

using std::cout;
using std::endl;

void createlist(Node * &headref) {
	headref = NULL;
}

bool isEmpty(const Node * const headref) {
	return (headref == NULL);
}

// To do: Implement the remaining functions
bool insert(Node * &headref, const DataType & data) {
	Node * newNode = new Node;
	
	if (newNode == NULL) {
		return false;
	}
	newNode->data = data;
	newNode->next = NULL;
	
	if (isEmpty(headref)) {
		headref = newNode;
		return true;
	} else if (data < headref->data) {
		newNode->next = headref;
		headref = newNode;
		return true;
	} else {
		Node * prev = headref;
		Node * current = headref->next;
		while (current != NULL && data > current->data) {
			prev = current;
			current = current->next;
		}
		if (current == NULL) {
			prev->next = newNode;
			return true;
		} else if (current->data == data) {
			return false;
		} else {
			prev->next = newNode;
			newNode->next = current;
			return true;
		}
	}
}

bool deletenode(Node *&headref, const DataType & data) {
	if (isEmpty(headref)) {
		return false;
	} else if (headref->data == data) {
		Node * todelete = headref;
		headref = headref->next;
		delete todelete;
		return true;
	} else {
		Node * prev = headref;
		Node * current = headref->next;
		while (current != NULL && current->data != data) {
			prev = current;
			current = current->next;
		}
		if (current == NULL) {
			return false;
		} else {
			prev->next = current->next;
			delete current;
			return true;
		}
	}
}

Node * findnode(const Node * const headref, const DataType & data) {
	if (isEmpty(headref)) {
		return NULL;
	} else {
		Node * current = const_cast<Node *>(headref);
		while (current != NULL) {
			if (current->data == data) {
				return current;
			}
			current = current->next;
		}
		return NULL;
	}
}

unsigned countnodes(const Node * const headref) {
	int counter = 0;
	if (!isEmpty(headref)) {
		const Node * current = headref;
		while (current != NULL) {
			counter++;
			current = current->next;
		}
	}
	return counter;
}

void deletelist(Node *&headref) {
	if (!isEmpty(headref)) {
		Node * current = headref;
		while (current != NULL) {
			Node * todelete = current;
			current = current->next;
			delete todelete;
		}
	}
}

void printlist(const Node * const headref) {
	const Node * current = headref;
	
	cout << "[ ";
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << "]" << endl;
}



