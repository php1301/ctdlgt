#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *pNext;
};
struct Stack
{
    Node *pTop;
};
void CreateStack(Stack &s)
{
    s.pTop = NULL;
}
Node *CreateNode(int x)
{
    Node *pNew = new Node;

    pNew->pNext = NULL;
    pNew->data = x;
    return pNew;
}
bool IsEmpty(Stack s)
{
    if (s.pTop == NULL)
    {
        return true;
    }
    return false;
}
bool Push(Stack &s, Node *p)
{
    if (p == NULL)
    {
        return false;
    }

    if (IsEmpty(s) == true)
    {
        s.pTop = p;
    }
    else

    {
        p->pNext = s.pTop;

        s.pTop = p;
    }
    return true;
}
bool Pop(Stack &s)
{

    if (IsEmpty(s) == true)
    {
        return false;
    }
    else
    {
        Node *p = s.pTop;
        s.pTop = s.pTop->pNext;
        delete p;
    }
    return true; 
}
bool Top(Stack &s, int &x)
{
    if (IsEmpty(s) == true)
    {
        return false;
    }
    x = s.pTop->data;
    return true;
}
void XuatStack(Stack s)
{
    while (IsEmpty(s) == false)
    {
        cout << s.pTop->data << " ";
        s.pTop = s.pTop->pNext;
    }
}
void NhapStack(Stack &s, int x)
{
    while (1)
    {

        int m;
        if (x == 0)
        {
            break;
        }
        else
        {
            cin >> m;
            if (m == 0)
                break;
            else if (m != x)
            {

                Node *p = CreateNode(m);
                Push(s, p);
            }
            else
            {
                Pop(s);
                if (IsEmpty(s) == true)
                {
                    cout << "Stack rong.";
                }
            }
        }
    }
}

int main()
{
    int x;
    cin >> x;
    Stack s;
    CreateStack(s);

    NhapStack(s, x);
    if (IsEmpty(s) == true)
    {
        cout << "Stack rong.";
    }
    else
    {
        cout << "Cac gia tri co trong stack la: ";
        XuatStack(s);
    }
    return 0;
}