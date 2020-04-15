// #include <iostream>
// using namespace std;

// int ls(int arr[], int n, int x)
// {
//     int i = 0;
//     arr[n] = x;
//     while (arr[i] != x)
//         i++;
//     if (i < n)
//         return i;
//     else
//         return -1;
// }
// void nhap(int a[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << "Nhap vao phan tu a[" << i << "] : ";
//         cin >> a[i];
//     }
// }
// int main(void)
// {

//     int a[100];
//     int n;
//     cin >> n;
//     int x;
//     cin >> x;
//     nhap(a, n);
//     int result = ls(a, n, x);
//     (result == -1) ? cout << "Khong tim thay"
//                    : cout << "Tim thay o " << result;
//     return 0;
// }
x = 9
n = 8
1 2 4 6 7 9 10 12
L=0, R=n-1=7 M = (7+0)/2 = int(3,5)
a[3] = 6 < x => phải
L=m+1 R=n-1 => M= (4+7)/2 = int(5,5)
a[5] = 9< x => phải
L=m+1 R=n-1 => M= (6+7)/2 = int(6,5)
a[6] = 10 < x => phải
L=m+1 R=n-1 => M =(7+7)/2 = int 7
&& l<=r => return true;