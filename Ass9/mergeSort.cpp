#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<vector<int>> vecs;
vector<int> vecs2;
vector<pair<int, vector<int>>> vecs3;
int k = 0;
int levelCount = 0;
int maxLevel = 0;
int assignMax = 0;
void nhap(vector<int> &v, int n)
{
    int input = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
}
void xuat2(vector<int> &v)
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

void xuat(vector<vector<int>> &v, vector<int> v2, vector<int> &temp, int n)
{
    vector<vector<int>> temp2;
    cout << "k=1" << endl;
    int maxCount = 0;
    while (1)
    {
        for (auto i = v2.begin(); i != v2.end(); i++)
        {
            if (levelCount == *i)
            {
                // cout << "[";
                int index = distance(v2.begin(), i);
                if (!v.at(index).empty())
                {
                    maxCount++;
                    temp2.push_back(v.at(index));
                }
            }
        }
        xuatVecs(temp2, maxCount - 1);
        temp2.clear();
        temp2.shrink_to_fit();

        if (maxCount == n)
            break;
        temp.push_back(maxCount);
        cout << "k=" << levelCount + 2 << endl;
        maxCount = 0;
        levelCount++;
    }
}

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

void mergeSort(vector<int> &sortVector, int n, int level = 0)
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
        vecs.push_back(sortVector);
        vecs2.push_back(level);
        // vecs2.push_back(make_pair(k + 1 - level, sortVector));
        return;
    }

    int middleElement = ceil((double)sortVector.size() / 2);
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
    vecs.push_back(leftVector);
    vecs2.push_back(level);
    vecs.push_back(rightVector);
    vecs2.push_back(level);
    mergeSort(leftVector, n, level + 1);

    mergeSort(rightVector, n, level + 1);
}
void mergeSort2(vector<int> &sortVector, int n, int level = 0)
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
        vecs3.push_back(make_pair(k + 1 - level, sortVector));
        return;
    }

    int middleElement = ceil((double)sortVector.size() / 2);
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
    mergeSort2(leftVector, n, level + 1);

    mergeSort2(rightVector, n, level + 1);

    merge(leftVector, rightVector, sortVector);
    vecs3.push_back(make_pair(k + 1 - level, sortVector));
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v;
    vector<int> temp;
    nhap(v, n);
    mergeSort(v, n);
    xuat(vecs, vecs2, temp, n);
    vecs.clear();
    vecs.shrink_to_fit();
    vecs2.clear();
    vecs2.shrink_to_fit();
    mergeSort2(v, n);
    v.clear();
    v.shrink_to_fit();
    int i = 0;
    int maxCount = 0;
    bool loopCheck = true;
    cout << "k=" << levelCount + 2 << endl;
    int j = k + 1 - levelCount;
    loopCheck = true;
    int count = levelCount + 1;
    while (loopCheck)
    {
        maxCount = 0;
        bool check = false;
        cout
            << "[";
        for (auto &e : vecs3)
        {
            if (e.first == j)
            {
                if (!e.second.empty())
                {
                    int test = 0;
                    if (k - j < 0)
                    {
                        test = 1;
                    }
                    else
                    {
                        test = temp.at(k - j);
                    }
                    xuat2(e.second);
                    maxCount++;
                    if (maxCount != test)
                    {
                        cout << ",";
                    }
                    check = true;
                }
            }
        }
        if (check == true)
        {
            if (maxCount != 1)
                cout << "]" << endl;
            if (n == 2)
                break;
            if (maxCount == 1)
            {
                cout << "]";
                break;
            }
            {
                count++;
                cout << "k=" << count + 1;
            }
            cout << endl;
            check = false;
        }

        j++;
    }
    vecs3.clear();
    vecs3.shrink_to_fit();
    return 0;
}