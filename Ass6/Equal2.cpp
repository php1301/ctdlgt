
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int binary(int arr[], int l, int r, int x)
{
    if (r < l)
        return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
        return mid;

    if (arr[mid] > x)
        return binary(arr, l, mid - 1, x);

    return binary(arr, mid + 1, r, x);
}
void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu thu " << i + 1 << " " << a[i] << endl;
    }
}
void equal(int arr[], int n, int x)
{
    int des;
    if (arr[0] == x)
    {
        des = binary(arr, 0, n - 1, x);
    }
    else
    {
        des = binary(arr, 1, n, x);
    }
    if (des == -1)
        cout << -1;
    else
    {
        int count = 1;
        int left = des - 1;
        while (left >= 0 && arr[left] == x)
            count++, left--;

        int right = des + 1;
        while (right < n && arr[right] == x)
            count++, right++;
        int start;
        int end;
        if (count == 1)
        {
            start = right;
            end = right;
        }
        else
        {
            start = left + 2;
            end = start + count - 1;
        }
        cout << count << " " << start << " " << end;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *array = new int[n];
    int *k = new int[m];
    nhap(array, n);
    nhap(k, m);
    for (int i = 0; i < m; i++)
    {
        equal(array, n, k[i]);
        cout << endl;
    }
    delete[] array, k;
    return 0;
}