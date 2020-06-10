#include <iostream>
using namespace std;

struct TNode
{
    int info;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode *Tree;

void CreateTree(Tree &T)
{
    T = NULL;
}

int Leaf(Tree T)
{
    if (T == NULL)
        return 0;
    else if (T->pLeft == NULL && T->pRight == NULL)
        return 1;
    else
        return Leaf(T->pLeft) + Leaf(T->pRight);
}

void LNR(Tree &T)
{
    if (T != NULL)
    {
        LNR(T->pLeft);
        if (T->pLeft == NULL && T->pRight == NULL)
            cout << T->info << " ";
        LNR(T->pRight);
    }
}

int InsertNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (T->info == x)
            return 0;
        if (T->info > x)
            return InsertNode(T->pLeft, x);
        else
            return InsertNode(T->pRight, x);
    }
    T = new TNode;
    if (T == NULL)
        return -1;
    T->info = x;
    T->pLeft = T->pRight = NULL;
    return 1;
}

void nhap(Tree &T, int n)
{
    int x;
    int i = 0;
    while (i < n)
    {
        cin >> x;
        InsertNode(T, x);
        i++;
    }
}

int main()
{
    Tree T;
    int n;
    cin >> n;
    CreateTree(T);
    nhap(T, n);
    cout << Leaf(T) << endl;
    LNR(T);
    return 0;
}