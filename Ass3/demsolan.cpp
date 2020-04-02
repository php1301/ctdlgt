#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int info;
    node *pNext;
    int max;
};
struct List
{
    node *pHead;
    node *pTail;
};

void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
void ReverseList(List &l);

//Your code
node *CreateNode(int x)
{
    node *pNew = new node;

    pNew->pNext = NULL;
    pNew->info = x;
    return pNew;
}
node *CreateNodeMax(int x, int max)
{
    node *pNew = new node;

    pNew->pNext = NULL;
    pNew->info = x;
    pNew->max = max;
    return pNew;
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
void nhap(List &L)
{
    while (1)
    {
        int x;
        cin >> x;
        if (x == 0)
            break;
        node *P = CreateNode(x);
        AddTail(L, P);
    }
}
void xuatMax(List L, int max)
{
    node *P = L.pHead;
    while (P != NULL)
    {
        if (P->max == max)
            cout
                << endl
                << P->info << ": " << P->max;
        P = P->pNext;
    }
}
void xuat(List L)
{
    node *P = L.pHead;
    while (P != NULL)
    {
        cout << P->info << " ";
        P = P->pNext;
    }
}
void ReverseList(List &l)
{

    if (l.pHead != NULL)
    {
        node *p1 = l.pHead;
        node *p2 = l.pHead->pNext;
        p1->pNext = NULL;

        while (p2 != NULL)
        {

            p1 = p2;
            p2 = p2->pNext;
            p1->pNext = l.pHead;
            l.pHead = p1;
        }
    }
}
void dem(List &l, List &l1, int &max)
{
    node *p = l.pHead;
    max = 1;
    int total_count = 0, res = -1;
    while (p != NULL)
    {

        int count = 1;
        struct node *q = p->pNext;
        while (q != NULL)
        {
            if (p->info == q->info)
                count++;
            q = q->pNext;
        }

        if (count >= max)
        {
            max = count;
            res = p->info;
            node *t = CreateNodeMax(res, max);
            AddTail(l1, t);
        }
        p = p->pNext;
    }
}
int main()
{
    List l, l1;
    int max;
    CreateList(l);
    CreateList(l1);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        ReverseList(l);
        xuat(l);
        dem(l, l1, max);
        xuatMax(l1, max);
    }
    return 0;
}