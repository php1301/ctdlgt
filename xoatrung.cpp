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

//Your code
node *CreateNode(int x)
{
    node *pNew = new node;

    pNew->pNext = NULL;
    pNew->info = x;
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
int xuat(List L)
{
    node *P = L.pHead;
    while (P != NULL)
    {
        if (P->info == 0)
            break;
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
void xoaTrung(List &l)
{
    node *ptr1, *ptr2, *dup;
    ptr1 = l.pHead;

    while (ptr1 != NULL && ptr1->pNext != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->pNext != NULL)
        {
            if (ptr1->info == ptr2->pNext->info)
            {
                dup = ptr2->pNext;
                ptr2->pNext = ptr2->pNext->pNext;
                delete (dup);
            }
            else
                ptr2 = ptr2->pNext;
        }
        ptr1 = ptr1->pNext;
    }
}
void xoa(List &l, int x, int &count)
{
    node *tam = new node;
    tam->pNext = l.pHead;
    l.pHead = tam;
    node *q;
    for (node *p = l.pHead; p->pNext != NULL; p = p->pNext)
        if (p->pNext->info == x)
        {
            count++;
            q = p->pNext;
            p->pNext = q->pNext;
            if (p->pNext == NULL)
            {
                l.pHead == NULL;
                break;
            }
            delete q;
        }
    l.pHead = l.pHead->pNext;
    delete tam;
}
int main()
{
    int x;
    int count = 0;
    List l;
    CreateList(l);
    nhap(l);
    ReverseList(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        xuat(l);
        cout<<"\n";
        xoaTrung(l);
        xuat(l);
    }
    return 0;
}