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

bool tang(List l)
{

    for (node *t = l.pHead; t->pNext != NULL; t = t->pNext)
    {
        if (t->info > t->pNext->info)

            return false;
    }
    return true;
}
bool giam(List l)
{

    for (node *t = l.pHead; t->pNext != NULL; t = t->pNext)
    {
        if (t->info < t->pNext->info)

            return false;
    }
    return true;
}
bool checkDup(List l)
{
    for (node *t = l.pHead; t->pNext != NULL && t->pNext->pNext != NULL; t = t->pNext)
    {
        if (t->info != t->pNext->info)

            return false;
    }
    return true;
}

int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        if (tang(l) == true && checkDup(l) == false)
        {
            cout << endl
                 << "Danh sach tang.";
        }
        if (giam(l) == true && checkDup(l) == false)
        {
            cout << endl
                 << "Danh sach giam.";
        }
        if (tang(l) == false && giam(l) == false || checkDup(l) == true)
            cout << endl
                 << "Danh sach khong tang cung khong giam.";
    }
    return 0;
}