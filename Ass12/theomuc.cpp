
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

int height(Tree T)
{
    if (T != NULL)
    {
        int a = height(T->pLeft);
        int b = height(T->pRight);
        if (a > b)
            return a + 1;
        else
            return b + 1;
    }
    return 0;
}
int traversalWithLevel(Tree T, int i, int &count, int level = 1)
{
    if (T != NULL)
    {
        if (level < i)
            traversalWithLevel(T->pLeft, i, count, level + 1);
        if (level == i)
        {
            count++;
            cout << T->key << " ";
        }
        if (level < i)
        {
            traversalWithLevel(T->pRight, i, count, level + 1);
        }
    }
    return 0;
}

void printWithLevel(Tree T)
{
    for (int i = 1; i <= height(T); i++)
    {
        int count = 0;
        cout << endl
             << "Deep " << i << ": ";
        traversalWithLevel(T, i, count);
        // cout << endl
        //      << "So node muc " << i - 1 << " cua cay la: " << count;
        // cout << endl;
    }
}
void nhap(Tree &T, int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     int x = 0;
    //     cin >> x;
    //     InsertNode(T, x);
    // }
    while (1)
    {
        double x;
        cin >> x;
        if (x == 0)
            break;
        InsertNode(T, x);
    }
}

int main()
{
    Tree T;
    CreateTree(T);
    int n = 0;
    // cin >> n;
    nhap(T, n);
    // cout << "Chieu cao cua cay la: " << height(T);
    printWithLevel(T);
}