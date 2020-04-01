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
void xoa(List &l, int x)
{
    node *tam = new node;
    tam->pNext = l.pHead;
    l.pHead = tam;
    node *q;
    int count = 0;
    for (node *p = l.pHead; p->pNext != NULL; p = p->pNext)
        if (p->pNext->info == x)
        {
            count++;
            q = p->pNext;
            p->pNext = q->pNext;
            delete q;
            break;
        }
    l.pHead = l.pHead->pNext;
    delete tam;
    if (count == 0)
    {
        cout << "Khong tim thay " << x << " trong danh sach:" << endl;
    }
}
int main()
{
    int x;
    List l;
    CreateList(l);
    nhap(l);
    ReverseList(l);
    cin >> x;
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {

        ReverseList(l);
        xoa(l, x);
        xuat(l);
    }
    return 0;
}