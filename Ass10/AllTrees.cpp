#include <iostream>
using namespace std;

struct TNode
{
    int key;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode *Tree;

void CreateTree(Tree &T)
{
    T = NULL;
}

int InsertNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (T->key == x)
            return 0;
        if (T->key > x)
            return InsertNode(T->pLeft, x);
        else
            return InsertNode(T->pRight, x);
    }
    T = new TNode;
    if (T == NULL)
        return -1;
    T->key = x;
    T->pLeft = NULL;
    T->pRight = NULL;
    return 1;
}

void nhap(Tree &T)
{
    while (1)
    {
        double x;
        cin >> x;
        if (x == 0)
            break;
        InsertNode(T, x);
    }
}

void LNR(Tree root)
{
    if (root == NULL)
        return;

    LNR(root->pLeft);

    cout << root->key << " ";

    LNR(root->pRight);
}
void LRN(Tree root)
{
    if (root != NULL)
    {
        LRN(root->pLeft);
        LRN(root->pRight);
        cout << root->key << " ";
    }
}
void RNL(Tree root)
{
    if (root == NULL)
        return;

    RNL(root->pRight);
    cout << root->key << " ";
    RNL(root->pLeft);
}
void RLN(TNode *root)
{
    if (root == NULL)
        return;
    RLN(root->pRight);
    RLN(root->pLeft);
    cout << root->key << " ";
}
void NLR(TNode *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    NLR(root->pLeft);
    NLR(root->pRight);
}
void NRL(TNode *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    NRL(root->pRight);
    NRL(root->pLeft);
}
int main()
{
    double n;
    Tree T;
    CreateTree(T);
    nhap(T);
    cout << "LNR: ";
    LNR(T);
    cout << endl;
    cout << "LRN: ";
    LRN(T);
    cout << endl;
    cout << "RNL: ";
    RNL(T);
    cout << endl;
    cout << "RLN: ";
    RLN(T);
    cout << endl;
    cout << "NLR: ";
    NLR(T);
    cout << endl;
    cout << "NRL: ";
    NRL(T);
    cout << endl;
}