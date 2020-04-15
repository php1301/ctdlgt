#include <string>
#include <iostream>
using namespace std;
struct node
{
    char info;
    node *pNext;
};
struct List
{
    node *pHead;
    node *pTail;
};
void CreateList(List &l);
node *CreateNode(char x);
void AddTail(List &l, node *p);
void Xuat(List l);
void enqueue(List &l, char x);
int dequeue(List &l);
bool isEmpty(List l);
int main()
{
    char c;
    cin >> c;
    string s = "";
    cin >> s;
    List queue;
    CreateList(queue);
    if (s.length() == 0)
    {
        cout << "Chuoi rong.";
    }
    c = toupper(c);
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
        if (s[i] == c)
        {
            if (i == 0)
            {
                dequeue(queue);
            }
            else
            {
                dequeue(queue);
            }
        }
        else
        {
            enqueue(queue, s[i]);
        }
    }
    node *P = queue.pHead;
    if (P == NULL)
        cout << "\nHang doi rong.";
    else
    {
        cout << "\nCac gia tri co trong hang doi la: ";
        while (P != NULL)
        {
            cout << P->info << "";
            P = P->pNext;
        }
    }
}
void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
bool isEmpty(List Q)
{
    if (Q.pHead == NULL)
        return 1;
    else
        return 0;
}
void enqueue(List &l, char x)
{
    if (isEmpty(l))
    {
        if (x != 0)
        {
            l.pHead = new node;
            l.pHead->info = x;
            l.pHead->pNext = l.pTail;
            l.pTail = l.pHead;
        }
        return;
    }
    l.pTail->pNext = new node;
    l.pTail = l.pTail->pNext;
    l.pTail->info = x;
    l.pTail->pNext = NULL;
}
int dequeue(List &l)
{

    node *p;

    if (isEmpty(l) != 1)

    {

        p = l.pHead;

        l.pHead = l.pHead->pNext;

        if (l.pHead == NULL)

            l.pTail = NULL;
        cout << p->info;
        delete p;
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
node *CreateNode(int x)
{
    node *pNew = new node;

    pNew->pNext = NULL;
    pNew->info = x;
    return pNew;
}