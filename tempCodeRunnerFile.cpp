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
void xoa(List &l, int x, int &count)
{

    node *temp = l.pHead, *prev;

    while (temp != NULL && temp->info == x)
    {
        l.pHead = temp->pNext;
        free(temp);
        temp = l.pHead;
    }

    while (temp != NULL)
    {
        while (temp != NULL && temp->info != x)
        {
            prev = temp;
            temp = temp->pNext;
        }

        if (temp == NULL)
            return;
        count++;

        prev->pNext = temp->pNext;

        free(temp);

        temp = prev->pNext;
    }
}
int main()
{
    int x;
    int count = 0;
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        ReverseList(l);
        cin >> x;
        xoa(l, x, count);
        if (count == 0 && l.pHead != NULL)
        {
            cout << "Khong tim thay " << x << " trong danh sach:" << endl;
            xuat(l);
        }

        if (l.pHead == NULL)
        {
            cout << "Danh sach rong.";
        }
        else if (l.pHead->pNext != NULL && count != 0)
        {
            xuat(l);
        }
    }
    return 0;
}