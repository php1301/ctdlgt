#include <iostream>
using namespace std;
struct node
{
    int info;
    node *pNext;
};
struct List
{
    node *pHead;
    node *pTail;
};
void CreateList(List &l);
node *CreateNode(int x);
void AddTail(List &l, node *p);
void enqueue(List &l, int x);
void dequeue(List &l);
bool isEmpty(List l);
int main()
{
    List q;
    CreateList(q);
    long long x;
    cin >> x;
    int temp;
    int s = 0;
    while (x > 0)
    {
        temp = x % 10;
        enqueue(q, temp);
        x = x / 10;
    }
    node *P = q.pHead;
    while (P != NULL)
    {
        cout << P->info << "";
        P = P->pNext;
    }
}

void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
bool isEmpty(List Q)
{
    if (Q.pHead == NULL)
        return 1;
    else
        return 0;
}
void enqueue(List &l, int x)
{
    if (isEmpty(l))
    {
        if (x != 0)
        {
            l.pHead = new node;
            l.pHead->info = x;
            l.pHead->pNext = l.pTail;
            l.pTail = l.pHead;
        }
        return;
    }
    l.pTail->pNext = new node;
    l.pTail = l.pTail->pNext;
    l.pTail->info = x;
    l.pTail->pNext = NULL;
}
void dequeue(List &l)
{

    node *p;

    if (isEmpty(l) != 1)

    {

        p = l.pHead;

        l.pHead = l.pHead->pNext;

        if (l.pHead == NULL)

            l.pTail = NULL;

        delete p;
    }
}
void AddTail(List &l, node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
node *CreateNode(int x)
{
    node *pNew = new node;

    pNew->pNext = NULL;
    pNew->info = x;
    return pNew;
}
