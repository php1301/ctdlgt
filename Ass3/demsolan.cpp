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
void xuat(List L)
{
    node *P = L.pHead;
    while (P != NULL)
    {
        cout << P->info << ": " << P->max;
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
void dem(List &l, List &l1)
{
    node *p = l.pHead;

    int total_count = 0, max = 0, res = -1;
    while (p != NULL)
    {

        // Count all occurrences of p->data
        int count = 1;
        struct node *q = p->pNext;
        while (q != NULL)
        {
            if (p->info == q->info)
                count++;
            q = q->pNext;
        }

        // Update max_count and res if count
        // is more than max_count
        if (count > max)
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
    CreateList(l);
    CreateList(l1);
    nhap(l);
    ReverseList(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        dem(l, l1);
        xuat(l1);
    }
    return 0;
}