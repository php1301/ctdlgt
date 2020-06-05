#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
void nhap(vector<long long int> &v, int n)
{
    int input = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
}
void xuat(vector<long long int> &v)
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

vector<pair<int, vector<long long int>>> vecs;
vector<pair<int, vector<long long int>>> vecs2;
int k = 0;
void merge(vector<long long int> &leftVector, vector<long long int> &rightVector, vector<long long int> &vectortoMerge)
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

void mergeSort(vector<long long int> &sortVector, int n, int level = 0)
{
    if (level > k)
        k = level + 1;
    if (sortVector.size() <= 1)
    {

        vecs.push_back(make_pair(level, sortVector));
        vecs2.push_back(make_pair(k + 1 - level, sortVector));
        return;
    }

    double middleElement = ceil((double)sortVector.size() / 2);
    vector<long long int> leftVector;
    vector<long long int> rightVector;

    for (int j = 0; j < middleElement; j++)
    {
        leftVector.push_back(sortVector[j]);
    }

    for (int j = 0; j < (sortVector.size()) - middleElement; j++)
    {
        rightVector.push_back(sortVector[middleElement + j]);
    }
    vecs.push_back(make_pair(level, leftVector));
    mergeSort(leftVector, n, level + 1);

    vecs.push_back(make_pair(level, rightVector));
    mergeSort(rightVector, n, level + 1);

    merge(leftVector, rightVector, sortVector);

    vecs2.push_back(make_pair(k + 1 - level, sortVector));
}

int main()
{
    int n = 0;
    cin >> n;
    double depth = ceil((double)n / 4);
    vector<long long int> v;
    // vector<long long int> v{56, 135, 15, 1, 9, 24, 17};
    nhap(v, n);
    mergeSort(v, n);
    cout << "k=1" << endl;
    // const auto &lastVecsKey = prev(vecs.end(), 1)->second;
    int i = 0;
    int count = 0;
    int maxCount = 0;
    bool loopCheck = true;
    while (loopCheck)
    {
        count = i + 2;
        bool check = false;
        cout
            << "[";
        for (auto &e : vecs)
        {
            if (e.first == i)
            {
                if (!e.second.empty())
                {
                    xuat(e.second);
                    maxCount++;
                    cout << ",";
                    check = true;
                }
            }
        }
        if (check == true)
        {
            cout << "\b";
            cout << "]" << endl;
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
            maxCount = 0;
        }
        i++;
    }
    cout << "k=" << count << endl;
    int j = k + 1 - i;
    loopCheck = true;
    while (loopCheck)
    {
        bool check = false;
        cout
            << "[";
        for (auto &e : vecs2)
        {
            if (e.first == j)
            {
                if (!e.second.empty())
                {
                    xuat(e.second);
                    maxCount++;
                    cout << ",";
                    check = true;
                }
            }
        }
        if (check == true)
        {
            cout << "\b";
            cout << "]" << endl;
            if (maxCount == 1)
                break;
            {
                cout << "k=" << count + 1;
                count++;
            }
            cout << endl;
            check = false;
            maxCount = 0;
        }
        j++;
    }

    return 0;
}