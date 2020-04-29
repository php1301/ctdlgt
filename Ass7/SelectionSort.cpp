#include <iostream>
using namespace std;

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void sort(int a[], int n)
{
    int i, j, max;
    for (int i = 0; i < n - 1; i++)
    {
        cout << endl
             << "i=" << i << ":" << endl;
        max = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[max])
            {
                max = j;
            }
        cout << "Max = "
             << "a[" << max << "] "
             << "= " << a[max] << endl;
        swap(a[max], a[i]);
        cout << "Mang sau khi sap xep " << i + 1 << " phan tu dau tien la: ";
        xuat(a, n);
    }
}
int main()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << "Mang rong.";
    else
    {
        int *a = new int[n];
        nhap(a, n);
        cout << "Mang truoc khi sap xep la: ";
        xuat(a, n);
        sort(a, n);
        cout << endl;
        cout << "Mang sau khi sap xep la: ";
        xuat(a, n);
        delete[] a;
    }
}