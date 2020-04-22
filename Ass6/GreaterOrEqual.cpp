
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int countGreater(int arr[], int n, int k)
{
    int l = 0;
    int r = n - 1;

    int leftGreater = n;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] >= k)
        {
            leftGreater = m;
            r = m - 1;
        }

        else
            l = m + 1;
    }

    return (n - leftGreater);
}
void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
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
        cout << countGreater(array, n, k[i]) << endl;
    }
    delete[] array, k;
    return 0;
}