#include <iostream>
#include <math.h>
using namespace std;
struct Node
{
    int info;
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
void tachDSLK(List &l1, List &l2, List *l3)
{
    Node head = l1;
    
}
Node *CreateNode(int newinfo)
{
    Node *p = new Node;
    if (p == NULL)
    {
        return NULL;
    }
    p->info = newinfo;
    p->pNext = NULL;
    return p;
}

bool prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    // if (n == 2)
    // {
    //     return true;
    // }
    // if (n % 2 == 0)
    // {
    //     return false;
    // }
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void AddTail(List &l, Node *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void NhapDuLieu(List &l, int &Dem)
{
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        Dem++;
        Node *p = CreateNode(x);
        AddTail(l, p);
    }
}

void XuatDuLieu(List &l, int Dem)
{
    int j;
    Node *i;
    int count = 0;
    if (Dem == 0)
    {
        cout << "Danh sach rong.";
    }
    else
    {
        cout << "Danh sach vua nhap la:";
        for (i = l.pHead, j = 1; i != NULL; i = i->pNext, j++)
        {
            if (j % 2 == 1 && prime(i->info) == true)
                count++;
            cout << " " << i->info;
        }
        cout << endl
             << "Danh sach co " << count << " so nguyen to o vi tri le.";
    }
}

int main()
{
    List l;
    int Dem = 0;
    CreateList(l);
    NhapDuLieu(l, Dem);
    XuatDuLieu(l, Dem);
    cout << endl;
    return 0;
}