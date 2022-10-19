#include <iostream>
#include <vector>

#include "BTree.h"


using namespace std;

int main()
{
	vector<BTreeNode*> tree;

	int n = 0;
	int b = 1;
	int c = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		b += b * 2;
	}

	for (int i = 0; i < n - 1; i++)
	{
		c += c * 2;
	}

	for (int i = 0; i < b; i++)
	{
		tree.push_back(MakeBTNode());
	}

	for (int i = 0; i < n; i++)
	{
		SetData(tree[i], i + 1);
	}

	for (int i = 0; i < b; i++)
	{
		cout << tree[i]->data << endl;
	}


}