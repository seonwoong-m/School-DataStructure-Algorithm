#include "BTree.h"

#include <iostream>

using namespace std;

BTreeNode* MakeBTNode(void)
{
    BTreeNode* nd = new BTreeNode;

    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

void SetData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}

BTData GetData(BTreeNode* bt)
{
    return bt->data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->left != NULL)
    {
        delete main->left;
    }

    main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->right != NULL)
    {
        delete main->right;
    }

    main->right = sub;
}

void PreorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;

    cout << bt->data << endl;
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void InorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left);
    cout << bt->data << endl;
    InorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left);
    PostorderTraverse(bt->right);
    cout << bt->data << endl;
}