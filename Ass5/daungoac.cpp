
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

// struct node
// {
//     char info;
//     bool done = true;
//     node *pNext;
// };
// struct List
// {
//     node *pHead;
//     node *pTail;
// };
// void CreateList(List &l)
// {
//     l.pHead = NULL;
// }
// node *CreateNode(char x)
// {
//     node *pNew = new node;
//     pNew->info = x;
//     pNew->pNext = NULL;
//     return pNew;
// }
// void AddHead(List &l, node *p)
// {
//     if (l.pHead == NULL)
//     {
//         l.pHead = p;
//     }
//     else
//     {
//         p->pNext = l.pHead;
//         l.pHead = p;
//     }
// }
// bool isEmpty(List s)
// {
//     if (s.pHead == NULL)
//     {
//         return true;
//     }
//     return false;
// }
// void enstack(List &s, int x)
// {

//     node *p = CreateNode(x);
//     AddHead(s, p);
// }
// void destack(List &s)
// {

//     node *p = s.pHead;
//     s.pHead = s.pHead->pNext;
//     delete p;
// }
// void AddTail(List &l, node *p)
// {
//     if (l.pHead == NULL)
//     {
//         l.pHead = p;
//         l.pTail = l.pHead;
//     }
//     else
//     {
//         l.pTail->pNext = p;
//         l.pTail = p;
//     }
// }
// void xuat(List l)
// {
//     node *P = l.pHead;

//     while (P != NULL)
//     {
//         cout << P->info << " ";
//         P = P->pNext;
//     }
// }
// void checkNgoac(List l)
// {
//     int left = 0;
//     int right = 0;
//     bool check = true;
//     while (l.pHead != NULL)
//     {
//         if (l.pHead->info == '(')
//         {
//             left++;
//         }
//         if (l.pHead->info == ')')
//         {
//             right++;
//         }
//         l.pHead = l.pHead->pNext;
//     }
//     if (left == right)
//     {
//         cout << "So cap dau ngoac tron la: " << left;
//     }
//     if (left > right)
//     {
//         cout << "Thieu dau ngoac dong.";
//     }
//     if (left < right)
//     {
//         cout << "Thieu dau ngoac mo.";
//     }
// }
// int main()
// {
//     char c;
//     List l;
//     CreateList(l);
//     bool check = true;
//     while (c != '`')
//     {
//         cin >> c;
//         if (c == '(' || c == ')')
//         {
//             node *p = CreateNode(c);
//             AddTail(l, p);
//         }
//     }
//     if (l.pTail->info == '(')
//     {
//         cout << "Dat dau ngoac bi sai.";
//     }
//     else
//     {
//         cout << endl;
//         checkNgoac(l);
//     }
struct node
{
    char info;
    node *pNext;
    bool Ch = false;
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
node *CreateNode(char x)
{
    node *pNew = new node;
    pNew->info = x;
    pNew->pNext = NULL;
    return pNew;
}

void Output(List l)
{
    node *p = l.pHead;
    while (p != NULL)
    {
        cout << p->info;
        p = p->pNext;
    }
}
bool IsEmpty(List &l)
{
    if (l.pHead == NULL)
        return true;
    else
        return false;
}
void enqueue(List &l, char c)
{
    node *p = CreateNode(c);
    AddTail(l, p);
}
void dequeue(List &l)
{
    node *p = l.pHead;
    if (p == nullptr)
        return;
    l.pHead = p->pNext;
}
void Solve(List &l, char &x, int &dem)
{

    bool mo = false;
    bool dong = false;
    cin.get(x);
    while (x != '\n' && x != 0 && x != '\0')
    {
        if (x == '(')
        {
            enqueue(l, 1);
        }
        if (x == ')')
        {
            if (IsEmpty(l))
            {
                mo = true;
            }
            else
            {
                dequeue(l);
                dem++;
            }
        }
        x = '\n';
        cin.get(x);
    }
    if (!IsEmpty(l))
        dong = true;
    if (mo && dong)
    {
        cout << "Dat dau ngoac bi sai.";
    }
    else
    {
        if (mo)
        {
            cout << "Thieu dau ngoac mo.";
        }
        if (dong)
        {
            cout << "Thieu dau ngoac dong.";
        }
        if (!mo && !dong)
        {
            cout << "So cap dau ngoac tron la: " << dem;
        }
    }
}
int main()
{
    List l;
    CreateList(l);
    char c = '0';
    int dem = 0;
    char x;
    Solve(l, x, dem);
    return 0;
}