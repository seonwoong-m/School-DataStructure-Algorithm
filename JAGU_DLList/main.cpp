#include <iostream>

using namespace std;

struct  Node
{
	int data;
	struct Node* nextNode;
	struct Node* prevNode;
};