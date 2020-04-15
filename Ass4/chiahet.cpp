#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void AddHead(List &l, node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
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
    while (1)
    {
        int x;
        cin >> x;
        if (x == 0)
            break;
        node *P = CreateNode(x);
        AddTail(L, P);
    }
}void nhap(List &L)
{

node *Merge(node *h1, node *h2)
{
    node *t1 = new node;
    node *t2 = new node;
    node *temp = new node;

    if (h1 == NULL)
        return h2;

    if (h2 == NULL)
        return h1;

    t1 = h1;

    while (h2 != NULL)
    {
        t2 = h2;

        h2 = h2->pNext;
        t2->pNext = NULL;

        if (h1->info > t2->info)
        {
            t2->pNext = h1;
            h1 = t2;
            t1 = h1;
            continue;
        }

    flag:
        if (t1->pNext == NULL)
        {
            t1->pNext = t2;
            t1 = t1->pNext;
        }
        else if ((t1->pNext)->info <= t2->info)
        {
            t1 = t1->pNext;
            goto flag;
        }
        else
        {
            temp = t1->pNext;
            t1->pNext = t2;
            t2->pNext = temp;
        }
    }

    return h1;
}
void MergeSort(node **head)
{
    node *first = new node;
    node *second = new node;
    node *temp = new node;
    first = *head;
    temp = *head;

    if (first == NULL || first->pNext == NULL)
    {
        return;
    }
    else
    {
        while (first->pNext != NULL)
        {
            first = first->pNext;
            if (first->pNext != NULL)
            {
                temp = temp->pNext;
                first = first->pNext;
            }
        }
        second = temp->pNext;
        temp->pNext = NULL;
        first = *head;
    }

    MergeSort(&first);
    MergeSort(&second);

    *head = Merge(first, second);
}
void SortIncrease(List &l)
{
    MergeSort(&l.pHead);

    // for (node *t = l.pHead; t->pNext != NULL; t = t->pNext)
    // {
    //     for (node *p = t->pNext; p != NULL; p = p->pNext)
    //     {
    //         if (t->info > p->info)

    //             swap(t->info, p->info);
    //     }
    // }
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

void chiahet(List &l, List &l1, List &l2, int x)
{
    node *p = l.pHead;
    while (p != NULL)
    {

        if (p->info % x == 0)
        {
            node *r = CreateNode(p->info);
            AddTail(l1, r);
        }
        else
        {
            node *r = CreateNode(p->info);
            AddTail(l2, r);
        }

        p = p->pNext;
    }
}
int main()
{
    List l, l1, l2;
    CreateList(l);
    CreateList(l1);
    CreateList(l2);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        int x;
        cin >> x;
        chiahet(l, l1, l2, x);
        xuat(l1);
        xuat(l2);
    }
    return 0;
}