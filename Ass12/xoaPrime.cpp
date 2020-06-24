#include <iostream>
using namespace std;

struct TNode
{
    int x;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode *Tree;

void CreateTree(Tree &T)
{
    T = NULL;
}
int count = 0;
bool snt(int x)
{
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if (x > 2)
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
                return false;
        }
    return true;
}
int InsertNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (T->x == x)
            return 0;
        if (T->x > x)
            return InsertNode(T->pLeft, x);
        else
            return InsertNode(T->pRight, x);
    }
    // if (snt(x))
    //     count++;
    T = new TNode;
    if (T == NULL)
        return -1;
    T->x = x;
    T->pLeft = NULL;
    T->pRight = NULL;
    return 1;
}
int countOutput = 0;
void delNode(Tree &t, int data)
{
    if (t == NULL)
    {
        return;
    }
    if (t->x < data)
    {
        delNode(t->pRight, data);
    }
    else if (t->x > data)
    {
        delNode(t->pLeft, data);
    }
    else
    {
        if (t->pLeft == NULL)
        {

            t = t->pRight;
        }
        else if (t->pRight == NULL)
        {
            t = t->pLeft;
        }

        else
        {
            TNode *x = t->pLeft;
            while (x->pRight != NULL)
            {
                x = x->pRight;
            }
            t->x = x->x;
            delNode(t->pLeft, x->x);
        }
    }
}
void duyet(Tree &T, int &x)
{
    if (T != NULL)
    {
        duyet(T->pLeft, x);
        if (snt(T->x)==true && x==0)
        {
            x = T->x;
        }
        duyet(T->pRight, x);
    }
}

void duyetCay(Tree T)
{

    if (T != NULL)
    {
        duyetCay(T->pLeft);
        cout << T->x << " ";
        duyetCay(T->pRight);
    }
}
void nhap(Tree &T)
{
    while (1)
    {
        double x;
        cin >> x;
        if (x == 0)
            break;
        count++;
        InsertNode(T, x);
    }
}

int main()
{
    int n;
    Tree T;
    CreateTree(T);
    nhap(T);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        duyet(T, x);
        delNode(T, x);
    }
    if (T == NULL)
        cout << "Not found tree!";
    else
    {
        duyetCay(T);
    }
}