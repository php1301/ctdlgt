#include <iostream>
using namespace std;
struct Data
{
    int n;
};
struct NODE
{
    Data data;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
//craete node
NODE *CreateNode(Data data)
{
    NODE *node = new NODE;
    if (node == NULL)
    {
        return NULL;
    }
    node->data = data;  //gan data cho node
    node->pNext = NULL; //pNext tro toi null
}
//Khoi tao danh sach lien ket
void Init(LIST &lst)
{
    lst.pHead = lst.pTail = NULL;
}
bool isEmpty(LIST lst)
{
    if (lst.pHead == NULL)
    {
        return true;
    }
}
void AddHead(LIST &lst, NODE *pNode)
{
    if (isEmpty(lst))
    {
        lst.pHead = lst.pTail = pNode;
    }
    else
    {
        pNode->pNext = lst.pHead;
        lst.pHead = pNode;
    }
}
void AddTail(LIST &lst, NODE *p)
{
    if (lst.pHead == NULL)
    {
        lst.pHead = lst.pTail = p;
    }
    else
    {
        lst.pTail->pNext = p;
        lst.pTail = p;
    }
}
void Input(LIST &lst)
{
    Init(lst); // khoi tao node
    for (int i = 1;; i++)
    {
        Data x;
        cin >> x.n;
        if (x.n == 0 && i == 1)
        {
            cout << "Danh sach rong.";
            break;
        }
        if (x.n == 0)
        {
            break;
        }
        NODE *p = CreateNode(x);
        AddTail(lst, p);
    }
}
void Output(LIST lst)
{
    NODE *i;
    for (i = lst.pHead; i != NULL; i = i->pNext)
    {
        // if (i->data.n == 0)
        // {
        //     cout << "Danh sach rong.";
        //     break;
        // }
        cout << i->data.n << " ";
        // if (i->data.n == 0)
        // {
        //     break;
        // }
    }
}

int main()
{

    LIST lst;
    Input(lst);
    if (isEmpty(lst) == false)
        cout << "Danh sach vua nhap la: ";
    Output(lst);
}