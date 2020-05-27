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

void sort(long long a[], int min, int max, vector<Res> &input)
{
    int p = a[(min + max) / 2];
    int i = min;
    int j = max;
    Res res;
    while (i <= j)
    {
        while (a[i] > p)
            i++;
        while (a[j] < p)
            j--;
        if (i <= j)
        {
            if (i != j)
            {
                res.i = i + 1;
                res.j = j + 1;
                input.push_back(res);
            }
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (min < j)
    {
        sort(a, min, j, input);
    }
    if (i < max)
    {
        sort(a, i, max, input);
    }
}
void heapDiv()
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
    sort(a, 0, n - 1, v);
    cout << endl
         << "Day sau khi sap xep: ";
    xuat(a, n);
    cout << endl
         << "Cac hoan vi duoc thuc hien trong Quick Sort: " << endl;
    xuatVec(v);
    return 0;
}