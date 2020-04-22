#include <iostream>
#include <string.h>
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
}
node *CreateNode(int x)
{
    node *pNew = new node;
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
void AddTail(List &l, node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
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
int firstDigit(int n)
{

    while (n >= 10)
        n /= 10;

    return n;
}

int lastDigit(int n)
{
    return (n % 10);
}
void destack(List &s, int x, List &l1)
{
    int a = 0;
    int b = 0;
    node *p = s.pHead;
    while (p != NULL)
    {
        if (p->info * x + b > 9 && p->pNext != NULL)
        {
            a = lastDigit(p->info * x + b);
            enstack(l1, a);
            b = firstDigit(p->info * x + b);
        }
        if (p->info * x + b <= 9 && p->pNext != NULL)
        {
            a = p->info * x + b;
            b = 0;
            enstack(l1, a);
        }
        if (p->pNext == NULL)
        {
            a = p->info * x + b;
            enstack(l1, a);
        }
        p = p->pNext;
    }
}
int main()
{
    List st, l;
    CreateList(st);
    CreateList(l);
    string s;
    int x;
    cin >> s;
    cin >> x;
    for (int i = 0; i < s.length(); i++)
    {
        int x = (int)s[i] - 48;
        enstack(st, x);
    }
    destack(st, x, l);
    while (l.pHead != NULL && x != 0)
    {
        cout << l.pHead->info << "";
        l.pHead = l.pHead->pNext;
    }
    if (x == 0)
    {
        cout << 0;
    }
}