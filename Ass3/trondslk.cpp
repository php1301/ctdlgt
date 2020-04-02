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
void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
void SortIncrease(List &l);

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
}
node *merge(node *a, node *b)
{
    node *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->info <= b->info)
    {
        result = a;
        result->pNext = merge(a->pNext, b);
    }
    else
    {
        result = b;
        result->pNext = merge(a, b->pNext);
    }
    return (result);
}


int main()
{
    List l, l1, l2;
    CreateList(l);
    CreateList(l1);
    CreateList(l2);
    nhap(l1);
    nhap(l2);
    if (l1.pHead == NULL)
    {
        cout << "Danh sach l1 rong.";
    }
    else
    {
        cout << "Danh sach l1 la: ";
        xuat(l1);
    }
    if (l2.pHead == NULL)
    {
        cout << endl
             << "Danh sach l2 rong.";
    }
    else
    {
        cout << endl
             << "Danh sach l2 la: ";
        xuat(l2);
    }
    if (l1.pHead != NULL && l2.pHead != NULL)
    {
        cout << endl
             << "Danh sach l1 sau khi sap xep la: ";
        SortIncrease(l1);
        xuat(l1);
        cout << endl
             << "Danh sach l2 sau khi sap xep la: ";
        SortIncrease(l2);
        xuat(l2);
        cout << endl;
        l.pHead = merge(l1.pHead, l2.pHead);
        cout<<"Ket qua tron l1 voi l2 la: ";
        xuat(l);
    }
    else
        cout << endl
             << "Khong tron duoc.";
    return 0;
}