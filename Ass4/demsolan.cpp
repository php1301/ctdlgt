#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int info;
    node *pNext;
    int count = 1;
    bool check = true;
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
void nhap(List &L)
{
    while (1)
    {
        int x;
        cin >> x;
        if (x == 0)
            break;
        node *P = CreateNode(x);
        AddHead(L, P);
    }
}
void xuatMax(List L)
{
    node *P = L.pHead;
    while (P != NULL)
    {
        if (P->check == false)
        {
            P = P->pNext;
        }
        else
        {
            cout
                << endl
                << P->info << ": " << P->count;
            P = P->pNext;
        }
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

void dem(List &l)
{
    node *p = l.pHead;
    while (p != NULL)
    {
        if (p->check == true)
        {
            node *q = p->pNext;
            while (q != NULL)
            {
                if (p->info == q->info)
                {
                    p->count++;
                    q->check = false;
                }
                q = q->pNext;
            }
        }
        p = p->pNext;
    }
}
int main()
{
    List l, l1;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        dem(l);
        cout << endl
             << "So lan xuat hien cua tung phan tu trong danh sach la:";
        xuatMax(l);
    }
    return 0;
}