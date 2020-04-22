
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int binary(int A[], int N, int x, int search)
{
    int low = 0, high = N;

    int result = -1;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (x == A[mid])
        {
            result = mid;

            if (search)
                high = mid - 1;

            else
                low = mid + 1;
        }

        else if (x < A[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return result;
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
        int first = binary(array, n, k[i], 1);
        int last = binary(array, n, k[i], 0);
        int count = last - first + 1;
        if (first == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << count << " " << first + 1 << " " << last + 1 << endl;
        }
    }
    delete[] array, k;
    return 0;
}