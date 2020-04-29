#include <iostream>
using namespace std;
struct PhanSo
{
    int tu = 0;
    int mau = 0;
};
void xuat(PhanSo a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].tu << "/" << a[i].mau << " ";
    }
}
void nhap(PhanSo a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].tu >> a[i].mau;
    }
}
void sort(PhanSo a[], int n)
{
    int i, j, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if ((a[j].tu * a[min].mau - a[j].mau * a[min].tu) < 0)
            {
                min = j;
            }
        swap(a[min], a[i]);
        cout << endl
             << "#STEP " << i + 1 << ":" << endl;
        xuat(a, n);
    }
}
void search(PhanSo a[], int n, PhanSo k)
{
    int l = 0;
    int r = n - 1;
    int m;
    int res = -1;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        cout << "[Left=" << l + 1 << ", Mid=" << m + 1 << ", Right=" << r + 1 << "]" << endl;
        if ((a[m].tu * k.mau - a[m].mau * k.tu) == 0)
        {
            res = m;
            r = m - 1;
        }
        else if ((a[m].tu * k.mau - a[m].mau * k.tu) > 0)

            r = m - 1;
        else
        {
            l = m + 1;
        }
    }
    if (res == -1)
        cout << "Khong tim thay phan so bang X";
    else
        cout
            << "Tim thay phan so bang X tai vi tri be nhat la: "
            << res + 1;
}
int main()
{
    int n;
    PhanSo k;
    cin >> n;
    if (n == 0)
        cout << "Mang rong.";
    else
    {
        PhanSo *a = new PhanSo[n];
        nhap(a, n);
        cin >> k.tu >> k.mau;
        // xuat(a, n);
        sort(a, n);
        cout << endl;
        search(a, n, k);
        delete[] a;
    }
}