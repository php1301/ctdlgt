
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

int kiemTraNhanhTrai(node *root, int x);
int kiemTraNhanhPhai(node *root, int x);

void inDanhSachGiamDan(node *TREE);

string chuyenNhiPhan(int x);

bool kiemTraDoiXung(string s);
void demSoChuoiDoiXung(node *TREE, int &cnt);

node *themPhanTuVaoCay(node *&root, int x);

int main()
{
    node *TREE = NULL;
    int x, cnt = 0;
    while (scanf("%d", &x))
    {
        if (x == 0)
        {
            inDanhSachGiamDan(TREE);
            cout << endl;
            demSoChuoiDoiXung(TREE, cnt);
            cout << "Co " << cnt << " node thoa de bai." << endl;
            break;
        }
        else
            themPhanTuVaoCay(TREE, x);
    }
    // cout << kiemTraNhanhTrai(TREE, x);
    // cout << kiemTraNhanhPhai(TREE, x);
    // demSoChuoiDoiXung(TREE, cnt);
    // cout << cnt;
}

node *themPhanTuVaoCay(node *&T, int x)
{
    if (T != NULL)
    {
        if (T->data == x)
            return themPhanTuVaoCay(T->left, x);
        if (T->data > x)
            return themPhanTuVaoCay(T->left, x);
        else
            return themPhanTuVaoCay(T->right, x);
    }
    T = new node;
    if (T == NULL)
        return NULL;
    T->data = x;
    T->left = NULL;
    T->right = NULL;
    return T;
}

string chuyenNhiPhan(int x)
{
    string s = "";
    while (x > 0)
    {
        s += (x % 2 == 0) ? "1" : "0";
        x /= 2;
    }
    return s;
}

bool kiemTraDoiXung(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[s.length() - i - 1])
            return false;
    }
    return true;
}
int countTrai = 0;
int kiemTraNhanhTrai(node *root, int x)
{
    if (root != NULL)
    {
        kiemTraNhanhTrai(root->left, x);
        kiemTraNhanhPhai(root->left, x);
        if (kiemTraDoiXung(chuyenNhiPhan(root->data)))
        {
            // cout << root->data << " ";
            countTrai++;
        }
    }
    return countTrai;
}
int countPhai = 0;
int kiemTraNhanhPhai(node *root, int x)
{
    if (root != NULL)
    {
        kiemTraNhanhPhai(root->right, x);
        kiemTraNhanhPhai(root->left, x);
        if (kiemTraDoiXung(chuyenNhiPhan(root->data)))
        {
            // cout << root->data << " ";
            countPhai++;
        }
    }
    return countPhai;
}

void inDanhSachGiamDan(node *TREE)
{
    if (TREE != NULL)
    {
        inDanhSachGiamDan(TREE->right);
        cout << TREE->data << " ";
        inDanhSachGiamDan(TREE->left);
    }
}
void demSoChuoiDoiXung(node *TREE, int &cnt)
{
    cnt = kiemTraNhanhPhai(TREE, countPhai);
}