#include <iostream>
using namespace std;

struct TNode
{
    int key;
    TNode *pLeft;
    TNode *pRight;
    bool check = false;
    int count = 0;
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

void InsertNode(Tree &T, int x, bool check)
{
    if (T != NULL)
    {
        if (T->key == x)
        {
            T->count++;
            return;
        }

        if (T->key > x)
            return InsertNode(T->pLeft, x, check);
        else
            return InsertNode(T->pRight, x, check);
    }
    T = new TNode;
    T->key = x;
    T->pLeft = NULL;
    T->pRight = NULL;
    return;
}
void delNodeMax(Tree &n)
{

    TNode *prev = n;
    TNode *temp = n;
    if (!n)
        return;

    while (temp->pRight)
    {
        prev = temp;
        temp = temp->pRight;
    }
    if (temp->count == 0)
    {
        TNode *d = temp;
        cout << d->key << endl;
        temp = temp->pLeft;
        delete d;
    }
    else
    {
        TNode *d = n;
        cout << d->key << endl;
        n->count--;
    }
}
void deleteIterative(Tree &root)
{
    Tree curr = root;
    Tree prev = NULL;

    while (curr->pRight != NULL)
    {
        prev = curr;

        curr = curr->pRight;
    }

    if (curr->count == 0)
    {

        if (curr->pLeft == NULL && curr->pRight == NULL && prev == NULL)
        {
            cout << curr->key << endl;
            root = NULL;
            return;
        }
        if (curr->pLeft == NULL && curr->pRight == NULL && prev != NULL)
        {
            cout << curr->key << endl;
            prev->pRight = NULL;
            return;
        }
        if (curr->pLeft && prev)
        {
            cout << curr->key << endl;
            prev->pRight = curr->pLeft;
            return;
        }
        if (root == curr)
        {

            cout << curr->key << endl;
            root = root->pLeft;
            curr->pLeft = NULL;
            return;
        }
    }
    else
    {
        cout << curr->key << endl;
        curr->count--;
        return;
    }
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
            }
            else
            {

                // delNodeMax(T);
                // delNodeMax(T);
                // delNode(T, maxValue(T));
                deleteIterative(T);
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
            if (T == NULL)
            {
                InsertNode(T, x, true);
            }
            else
            {
                InsertNode(T, x, false);
            }
        }
    }
}

int main()
{
    int n;
    Tree T;
    List L;
    CreateTree(T);
    CreateList(L);

    nhap(T, L);
}