#include <iostream>
using namespace std;
void nhap(long long int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void xuat(long long int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void merge(long long int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long int leftArr[n1], rightArr[n2];
    for (i = 0; i < n1; i++)
    {
        leftArr[i] = a[left + i];
    }
    // cout << endl
    //      << "Left array" << endl;
    // xuat(leftArr, n1);
    for (j = 0; j < n2; j++)
    {
        rightArr[j] = a[mid + 1 + j];
    }
    // cout << endl
    //      << "Right array" << endl;
    // xuat(rightArr, n2);
    cout << "Left arr" << endl;
    xuat(leftArr, n1);
    cout << "Right arr" << endl;
    xuat(rightArr, n2);
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] >= rightArr[j])
        {
            a[k] = leftArr[i];
            i++;
        }
        else
        {
            a[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(long long int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge(a, left, mid, right);
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
    }
}

int main()
{
    int n = 0;
    cin >> n;
    long long int *a = new long long int[n];
    nhap(a, n);
    xuat(a, n);
    mergeSort(a, 0, n - 1);
    cout << endl;
    xuat(a, n);
    return 0;
}
