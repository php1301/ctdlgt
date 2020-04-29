#include <iostream>

using namespace std;
struct PhanSo
{
    long long int tu = 0;
    long long int mau = 0;
};
struct node
{
    PhanSo info;
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
node *CreateNode(PhanSo x)
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
        PhanSo x;
        cin >> x.tu;
        cin >> x.mau;
        if (x.mau == 0)
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

        cout << P->info.tu << "/" << P->info.mau << " ";
        P = P->pNext;
    }
}
void xuatBang(List L, PhanSo x, int &count)
{
    node *P = L.pHead;
    while (P != NULL)
    // (ad - bc)/(bd)
    {
        if (((P->info.tu * x.mau - P->info.mau * x.tu)) == 0)
        {
            count++;
            if (count == 1)
            {
                cout << "Cac phan so bang " << x.tu << "/" << x.mau << " co trong danh sach la: ";
            }
            cout << P->info.tu << "/" << P->info.mau << " ";
        }
        P = P->pNext;
    }
}
int main()
{
    List l;
    int count = 0;
    CreateList(l);
    nhap(l);
    if (l.pHead==NULL)
        cout << "Danh sach rong.";
    else
    {
        PhanSo x;
        cin >> x.tu >> x.mau;
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        cout << endl;
        xuatBang(l, x, count);
        if (count == 0)
        {
            cout << "Khong co phan so nao bang " << x.tu << "/" << x.mau << " trong danh sach.";
        }
        return 0;
    }
}