
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
    string info;
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
Node *CreateNode(string x)
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
void CreateTree(Tree &T)
{
    T = NULL;
}

int InsertNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (T->key == x)
            return InsertNode(T->pLeft, x);
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

void delNode(Tree &t, int data)
{
    if (t == NULL)
    {
        return;
    }
    if (t->key < data)
    {
        delNode(t->pRight, data);
    }
    else if (t->key > data)
    {
        delNode(t->pLeft, data);
    }
    else
    {
        if (t->pLeft == NULL)
        {

            t = t->pRight;
        }
        else if (t->pRight == NULL)
        {
            t = t->pLeft;
        }

        else
        {
            TNode *x = t->pLeft;
            while (x->pRight != NULL)
            {
                x = x->pRight;
            }
            t->key = x->key;
            delNode(t->pLeft, x->key);
        }
    }
}
int maxValue(TNode *node)
{
    TNode *current = node;
    while (current->pRight != NULL)
        current = current->pRight;

    return (current->key);
}
void nhap(Tree &T, List &L)
{
    while (1)
    {
        char s;
        cin >> s;
        if (s == 'O')
        {
            if (T == NULL)
            {
                cout << "NULL" << endl;
                // string x = "NULL";
                // Node *temp = CreateNode(x);
                // AddTail(L, temp);
            }
            else
            {
                // string x = to_string(maxValue(T));
                // Node *temp = CreateNode(x);
                // AddTail(L, temp);
                cout << maxValue(T) << endl;
                delNode(T, maxValue(T));
            }
        }
        if (s == 'E')
        {
            break;
        }
        if (s == 'U')
        {
            int x;
            cin >> x;
            InsertNode(T, x);
        }
    }
}
void deleteTree(Tree &T)
{
    if (T == NULL)
        return;

    deleteTree(T->pLeft);
    deleteTree(T->pRight);

    delete T;
}
int main()
{
    int n;
    Tree T;
    List L;
    CreateTree(T);
    CreateList(L);

    nhap(T, L);
    deleteTree(T);
    for (Node *i = L.pHead; i != NULL; i = i->pNext)
    {
        cout << i->info << endl;
    }
}