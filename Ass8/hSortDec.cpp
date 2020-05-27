#include <iostream>
#include <vector>
using namespace std;
struct Res
{
    int i = 0;
    int j = 0;
};
void nhap(long long a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void divide(long long a[], int n, int i, vector<Res> &input, bool check)
{
    int goc = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    Res res;
    if (l < n && a[l] < a[goc])
    {
        goc = l;
    }
    if (r < n && a[r] < a[goc])
    {
        goc = r;
    }
    if (goc != i)
    {
        if (check == true)
        {
            res.i = i;
            res.j = goc;
            input.push_back(res);
        }
        swap(a[goc], a[i]);
        divide(a, n, goc, input, check);
    }
}
void heap(long long a[], int n, vector<Res> &input)
{
    bool check = true;
    for (int i = n / 2 - 1; i >= 0; i--)
        divide(a, n, i, input, check);
    for (int i = n - 1; i > 0; i--)
    {
        check = false;
        swap(a[0], a[i]);
        divide(a, i, 0, input, check);
    }
}
void xuat(long long a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void xuatVec(vector<Res> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input.at(i).i << " " << input.at(i).j << endl;
    }
}
int main()
{
    // v.push_back(2);
    // cout<<v[1];
    int n = 0;
    cin >> n;
    long long *a = new long long[n];
    vector<Res> v;
    nhap(a, n);
    cout << "Day truoc khi sap xep: ";
    xuat(a, n);
    heap(a, n, v);
    cout << endl
         << "Day sau khi sap xep: ";
    xuat(a, n);
    cout << endl
         << "Cac hoan vi duoc thuc hien trong heap: " << endl;
    xuatVec(v);
    return 0;
}