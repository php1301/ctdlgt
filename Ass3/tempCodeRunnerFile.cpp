struct node
{
    int info;
    node *pNext;
    int max;
    int count = 1;
    bool check = true;
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
node *CreateNodeMax(int x, int max)
{
    node *pNew = new node;

    pNew->pNext = NULL;
    pNew->info = x;
    pNew->max = max;
    return pNew;
}

void AddHead(List &l, node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
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
        AddHead(L, P);
    }
}
void xuatMax(List L, int max)
{
    node *P = L.pHead;
    while (P != NULL)
    {
        if (P->count == max)
            cout
                << endl
                << P->info << ": " << P->count;
        P = P->pNext;
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

void dem(List &l, int &max)
{
    node *p = l.pHead;
    max = 1;
    while (p != NULL)
    {
        if (p->check == true)
        {
            struct node *q = p->pNext;
            while (q != NULL)
            {
                if (p->info == q->info)
                {
                    p->count++;
                    q->check = false;
                }
                q = q->pNext;
            }

            if (p->count >= max)
            {
                max = p->count;
            }
            p = p->pNext;
        }
    }
}
int main()
{
    List l, l1;
    int max;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        xuat(l);
        dem(l, max);
        xuatMax(l, max);
    }
    return 0;
}