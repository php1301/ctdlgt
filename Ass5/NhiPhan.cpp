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
};
void CreateList(List &l)
{
    l.pHead = NULL;
}
node *CreateNode(int x);
void AddHead(List &l, node *p);
void enstack(List &l, int x);
void destack(List &l);
bool isEmpty(List l);
int main()
{
    List st;
    CreateList(st);
    long long x;
    cin >> x;
    while (x != 0)
    {
        int temp;
        temp = x % 2;
        x = (x / 2);
        enstack(st, temp);
    }
    node *P = st.pHead;

    while (P != NULL)
    {
        cout << P->info << "";
        P = P->pNext;
    }
}
node* CreateNode(int x)
{
    node* pNew = new node;
    pNew->info = x;
    pNew->pNext = NULL;
    return pNew;

}
void AddHead(List &l, node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
bool isEmpty(List s)
{
    if (s.pHead == NULL)
    {
        return true;
    }
    return false;
}
void enstack(List &s, int x)
{

    node *p = CreateNode(x);
    AddHead(s, p);
}
void destack(List &s)
{

    node *p = s.pHead;
    s.pHead = s.pHead->pNext;
    delete p;
}