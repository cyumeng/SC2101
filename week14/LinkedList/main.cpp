/*
	Name: A Linked List Sample
	Copyright: cyumeng
	Author: cyumeng
	Date: 22/04/15 20:41
	Description: A Linked List Sample
*/

#include <iostream>
#include "linkedlist.h"

using std::cout;
using std::endl;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Node * list;
	
	createlist(list);
	printlist(list);
	insert(list, 5);
	printlist(list);
	insert(list, 3);
	insert(list, 10);
	insert(list, 7);
	printlist(list);
	insert(list, 5);
	printlist(list);
	deletenode(list, 5);
	printlist(list);
	deletenode(list, 11);
	
	Node * n1 = findnode(list, 7);
	cout << n1->data << endl;
	cout << "There are " << countnodes(list) << " nodes";

	deletelist(list);
	
	return 0;
}


