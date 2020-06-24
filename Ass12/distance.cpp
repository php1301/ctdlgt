#include <iostream>
using namespace std;

struct TNode
{
    int key;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode *Tree;
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
void CreateTree(Tree &T)
{
    T = NULL;
}

int count = 0;
TNode *temp = NULL;

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
    count++;
    if (count == 1)
    {
        temp = T;
    }
    if (T == NULL)
        return -1;
    T->key = x;
    T->pLeft = NULL;
    T->pRight = NULL;
    return 1;
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

bool searchInTree(Tree T, int x)
{
    int level = 1;
    int distance = 0;
    if (T == NULL)
    {
        return false;
    }
    while (T != NULL)
    {
        if (T->key == x)
        {
            if (T == temp)
            {
                cout << "0" << endl;
                return true;
            }
            else
            {
                cout << level << endl;
                return true;
            }
        }
        if (T->key > x)
        {
            if (T->pLeft == NULL)
            {
                return false;
            }
            T = T->pLeft;
            if (T->key != x)
                level += 1;
        }
        else
        {
            if (T->pRight == NULL)
            {
                return false;
            }
            T = T->pRight;
            if (T->key != x)
                level += 1;
        }
    }
    return false;
}
void nhapList(List &l)
{
    while (1)
    {
        double x;
        cin >> x;
        if (x == 0)
            break;
        Node *temp = CreateNode(x);
        AddTail(l, temp);
    }
}
void duyetList(List l, Tree T)
{
    for (Node *i = l.pHead; i != NULL; i = i->pNext)
    {
        if (!searchInTree(T, i->info))
            cout << "-1" << endl;
    }
}

int main()
{
    Tree T;
    List L;
    CreateTree(T);
    CreateList(L);
    nhap(T);
    nhapList(L);
    duyetList(L, T);
}