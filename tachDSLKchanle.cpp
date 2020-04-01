#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int info;
    Node *pNext;
    Node *pNull = nullptr;
};
struct List
{
    Node *pHead;
    Node *pTail;
};

void CreateList(List &l);
void NhapList(List &l);
int DemSoPhanTu(List l);
void Split(List l, List &l1, List &l2);
void XuatList(List l);

int main()
{
    List l, l1, l2;
    CreateList(l);
    CreateList(l1);
    CreateList(l2);
    NhapList(l);

    cout << "Danh sach vua nhap la: ";
    XuatList(l);
    cout << endl;
    Split(l, l1, l2);
    cout << "Cac so chan trong danh sach la: ";
    XuatList(l1);
    cout << endl;
    cout << "Cac so le trong danh sach la: ";
    XuatList(l2);
    cout << endl;
    return 0;
}
int DemSoPhanTu(List l)
{
    int dem = 0;
    while (l.pHead != NULL)
    {
        dem++;
    }
    return dem;
}
void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
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

void NhapList(List &l)
{
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        Node *p = CreateNode(x);
        AddTail(l, p);
    }
}
bool Find(List L, int x)
{
    Node *p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
            return false;
        p = p->pNext;
    }
    return true;
}

void Split(List l, List& l1, List& l2)
{

    while (l.pHead != NULL)
    {

        if (l.pHead->info % 2 == 0)
        {
            if (Find(l1, l.pHead->info))
            {

                Node *p1 = CreateNode(l.pHead->info);
                AddTail(l1, p1);
            }
        }
        else
        {
            if (Find(l2, l.pHead->info))
            {
                Node *p1 = CreateNode(l.pHead->info);
                AddTail(l2, p1);
            }
        }
        l.pHead = l.pHead->pNext;
    }
}

void XuatList(List l)
{

    for (Node *i = l.pHead; i != NULL; i = i->pNext)
        cout << " " << i->info;
}