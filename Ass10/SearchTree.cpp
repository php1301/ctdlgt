#include <iostream>
using namespace std;

double key = 0;
struct TNode
{
    double key;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode *Tree;

void createTree(Tree &T)
{
    T = NULL;
}

void LNR(Tree &T)
{
    if (T != NULL)
    {
        LNR(T->pLeft);
            cout << T->key << " ";
        LNR(T->pRight);
    }
}

double InsertNode(Tree &T, double x)
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
    T->pLeft = T->pRight = NULL;
    return 1;
}

void nhap(Tree &T, double n)
{
    double x;
    double i = 0;
    while (i < n)
    {
        cin >> x;
        InsertNode(T, x);
        key += x;
        i++;
    }
}

TNode *SearchNode(TNode *root, double x)
{
    if (root == NULL)
        return NULL;

    TNode *p = root;
    while (p != NULL)
    {
        if (p->key == x)
        {
            cout << "1";
            return p;
        }
        else if (p->key > x)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
    }
    cout << "0";
    return p;
}
int main()
{
    double n;
    TNode *T;
    createTree(T);
    cin >> n;
    nhap(T, n);
    key = key / n;
    SearchNode(T, key);
    cout << endl;
    LNR(T);
}