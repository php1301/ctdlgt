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
    int res, i, j;
    for (int i = 1; i < n; i++)
    {
        res = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < res)
        {
            a[j + 1] = a[j];
            j--;
        }
        cout << endl
             << "Vi tri chen cua "
             << "a[" << i << "]"
             << " la " << j + 1 << endl;
        a[j + 1] = res;
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