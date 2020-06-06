#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
void nhap(vector<int> &v, int n)
{
    int input = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
}
void xuat(vector<int> &v)
{

    if (!v.empty())
    {
        cout << "[";
        for (auto i = v.begin(); i != v.end(); i++)
        {
            {
                (i == v.end() - 1) ? cout << *i : cout << *i << ",";
            }
        }
        cout << "]";
    }
}
void xuatSubVecs(vector<int> &v, int comma, int count)
{
    if (!v.empty())
    {
        cout << "[";
        for (auto i = v.begin(); i != v.end(); i++)
        {
            {
                (i == v.end() - 1) ? cout << *i : cout << *i << ",";
            }
        }
        if (count < comma)
            cout << "],";
        else
        {
            cout << "]";
        }
    }
}

void xuatVecs(vector<vector<int>> &v, int comma)
{
    int count = 0;
    if (!v.empty())
    {
        cout << "[";
        for (auto &i : v)
        {
            xuatSubVecs(i, comma, count);
            count++;
        }
        cout << "]" << endl;
    }
}

vector<pair<int, vector<int>>> vecs;
vector<pair<int, vector<int>>> vecs2;
int k = 0;
int maxLevel = 0;
int assignMax = 0;
void merge(vector<int> &leftVector, vector<int> &rightVector, vector<int> &vectortoMerge)
{

    int left = leftVector.size();
    int right = rightVector.size();
    int i = 0, j = 0, k = 0;

    while (j < left and k < right)
    {

        if (leftVector[j] > rightVector[k])
        {

            vectortoMerge[i] = leftVector[j];
            j++;
        }
        else
        {

            vectortoMerge[i] = rightVector[k];

            k++;
        }

        i++;
    }
    while (j < left)
    {

        vectortoMerge[i] = leftVector[j];
        j++;
        i++;
    }

    while (k < right)
    {

        vectortoMerge[i] = rightVector[k];
        k++;
        i++;
    }
}
void absoluteXuat(vector<pair<int, vector<int>>> &vecs, vector<vector<int>> &temp2, vector<int> temp, int n)
{
    int i = 0;
    int count = 0;
    int maxCount = 0;
    bool loopCheck = true;
    while (loopCheck)
    {
        count = i + 2;
        bool check = false;
        // cout
        //     << "[";
        for (auto &e : vecs)
        {
            if (e.first == i)
            {
                if (!e.second.empty())
                {

                    temp2.push_back(e.second);
                    maxCount++;
                    check = true;
                }
            }
        }
        xuatVecs(temp2, maxCount - 1);
        vector<vector<int>>().swap(temp2);
        if (check == true)
        {
            if (maxCount == n)
            {
                loopCheck = false;
                break;
            }
            {
                cout << "k=" << count;
                count++;
            }
            cout << endl;
            check = false;
            temp.push_back(maxCount);
            maxCount = 0;
        }
        if (i == 9)
        {
            break;
        }
        i++;
    }
    // vector<pair<int, vector<int>>>().swap(vecs);
}
void mergeSort(vector<int> &sortVector, int n, vector<vector<int>> &temp2, vector<int> temp, int level = 0)
{
    if (level > k)
    {
        k = level + 1;
    }
    if (sortVector.size() <= 1)
    {
        assignMax++;
        if (assignMax == n)
            maxLevel = level;
        vecs.push_back(make_pair(level, sortVector));
        vector<int>().swap(sortVector);
        vecs2.push_back(make_pair(k + 1 - level, sortVector));
        vector<int>().swap(sortVector);
        return;
    }

    double middleElement = ceil((double)sortVector.size() / 2);
    vector<int> leftVector;
    vector<int> rightVector;

    for (int j = 0; j < middleElement; j++)
    {
        leftVector.push_back(sortVector[j]);
    }

    for (int j = 0; j < (sortVector.size()) - middleElement; j++)
    {
        rightVector.push_back(sortVector[middleElement + j]);
    }
    vecs.push_back(make_pair(level, leftVector));
    mergeSort(leftVector, n, temp2, temp, level + 1);

    vecs.push_back(make_pair(level, rightVector));
    mergeSort(rightVector, n, temp2, temp, level + 1);

    absoluteXuat(vecs, temp2, temp, n);
    merge(leftVector, rightVector, sortVector);
    vector<int>().swap(leftVector);
    vector<int>().swap(rightVector);
    vector<pair<int, vector<int>>>().swap(vecs);
    vecs2.push_back(make_pair(k + 1 - level, sortVector));
    vector<int>().swap(sortVector);
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v;
    vector<int> temp;
    vector<vector<int>> temp2;
    nhap(v, n);
    mergeSort(v, n, temp2, temp);
    cout << "k=1" << endl;
    vector<int>().swap(v);

    // cout << "k=" << count << endl;
    // int j = k + 1 - i;
    // loopCheck = true;
    // while (loopCheck)
    // {
    //     maxCount = 0;
    //     bool check = false;
    //     cout
    //         << "[";
    //     for (auto &e : vecs2)
    //     {
    //         if (e.first == j)
    //         {
    //             if (!e.second.empty())
    //             {
    //                 int test = 0;
    //                 if (k - j < 0)
    //                 {
    //                     test = 1;
    //                 }
    //                 else
    //                 {
    //                     test = temp.at(k - j);
    //                 }
    //                 xuat(e.second);
    //                 maxCount++;
    //                 if (maxCount != test)
    //                 {
    //                     cout << ",";
    //                 }
    //                 check = true;
    //             }
    //         }
    //     }
    //     if (check == true)
    //     {
    //         if (maxCount != 1)
    //             cout << "]" << endl;
    //         if (n == 2)
    //             break;
    //         if (maxCount == 1)
    //         {
    //             cout << "]";
    //             break;
    //         }
    //         {
    //             cout << "k=" << count + 1;
    //             count++;
    //         }
    //         cout << endl;
    //         check = false;
    //     }
    //     j++;
    // }
    // vecs2.clear();
    // vecs2.shrink_to_fit();
    return 0;
}