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

struct Node
{
    int info;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

Node *CreateNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void nhap(List &l)
{
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        Node *p = CreateNode(x);
        AddTail(l, p);
    }
}





int SearchTNode(Tree T, int x)
{
    if (T != NULL)
    {
        if (T->info == x)
            return 1;
        else if (x > T->info)
            return SearchTNode(T->pRight, x);
        else
            return SearchTNode(T->pLeft, x);
    }
    return 0;
}



int InsertNode(Tree &T, float x)
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

void TaoCay(Tree &T)
{
    int x;
    do
    {
        cin >> x;
        if (x == 0)
            break;
        InsertNode(T, x);
    } while (1);
}

int main()
{
    Tree T;
    List L;
    CreateTree(T);
    CreateList(L);
    TaoCay(T);
    nhap(L);
    for (Node *i = L.pHead; i != NULL; i = i->pNext)
    {
        if (SearchTNode(T, i->info) == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}