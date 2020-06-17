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

void nhap(Tree &T)
{
    while (1)
    {
        double x;
        cin >> x;
        if (x == 0)
            break;
        InsertNode(T, x);
    }
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
int countNode(int count = 0)
{
    count++;
}
int traversalWithLevel(Tree T, int i, int &count, int level = 1)
{
    if (T != NULL)
    {
        if (level == i)
        {
            count++;
            cout << T->key << " ";
        }
        else if (level < i)
        {
            traversalWithLevel(T->pLeft, i, count, level + 1);
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
             << "Muc " << i << ": ";
        traversalWithLevel(T, i, count);
        cout << endl
             << "So node muc " << i << ": " << count;
        cout << endl;
    }
}
int bac2(Tree T)
{
    if (T != NULL)
    {
        int a = bac2(T->pLeft);
        int b = bac2(T->pRight);
        if (T->pLeft && T->pRight)
            return 1 + a + b;
        return a + b;
    }
}

bool searchInTree(Tree T, int x)
{
    int level = 1;
    int distance = 0;
    if (T == NULL)
    {
        cout << "Khong tim thay x";
        return false;
    }
    while (T != NULL)
    {
        if (T->key == x)
        {
            cout<<endl;
            cout << "Tim thay x o muc: " << level << endl;
            if (T->pLeft == NULL && T->pRight == NULL)
            {
                cout << "X la node bac 0" << endl;
            }
            if ((T->pLeft == NULL && T->pRight != NULL) || (T->pLeft != NULL && T->pRight == NULL))
            {
                cout << "X la node bac 1" << endl;
            }
            if (T->pLeft != NULL && T->pRight != NULL)
            {
                cout << "X la node bac 2" << endl;
            }
            cout << "So node bac 2 ben phai cua key x kiem duoc " << bac2(T->pRight);
            return true;
        }
        if (T->key > x)
        {
            T = T->pLeft;
            if (T->key != x)
                cout << T->key << " ";
            level += 1;
        }
        else
        {
            T = T->pRight;
            if (T->key != x)
                cout << T->key << " ";
            level += 1;
        }
    }
    return false;
}

int main()
{
    Tree T;
    CreateTree(T);
    nhap(T);
    cout << "So node bac 2: " << bac2(T) << endl;
    cout << "Chieu Cao cay " << height(T) << endl;
    cout << "In cac node theo muc: ";
    printWithLevel(T);
    cout << "Duong di tim nut goc toi X: ";
    searchInTree(T, 11);
}