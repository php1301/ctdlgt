
#include <iostream>
using namespace std;

struct TNode
{
    int key;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode *Tree;

void CreateTree(Tree &T)
{
    T = NULL;
}

int InsertNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (T->key == x)
            return 0;
        if (T->key > x)
            return InsertNode(T->pLeft, x);
        else
            return InsertNode(T->pRight, x);
    }
    T = new TNode;
    if (T == NULL)
        return -1;
    T->key = x;
    T->pLeft = NULL;
    T->pRight = NULL;
    return 1;
}

void nhap(Tree &T, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        InsertNode(T, x);
    }
}
int bac1(Tree T, int &dem)
{
    if (T != NULL)
    {
        bac1(T->pLeft, dem);
        bac1(T->pRight, dem);
        if ((T->pLeft == NULL && T->pRight) || (T->pLeft && T->pRight == NULL))
            dem++;
        return dem;
    }
}


int main()
{
    Tree T;
    CreateTree(T);
    int n;
    cin >> n;
    nhap(T, n);
    int dem = 0;
    cout << "So node bac 1 cua cay la: " << bac1(T, dem) << endl;
}