#include "node.h"

void createlist(Node *&headref);
//void createlist(Node **);
bool insert(Node *&headref, const DataType & data);
bool deletenode(Node *&headref, const DataType & data);
Node * findnode(const Node * const headref, const DataType & data);
unsigned countnodes(const Node * const headref);
void deletelist(Node *&headref);
void printlist(const Node * const headref);
bool isEmpty(const Node * const headref);
