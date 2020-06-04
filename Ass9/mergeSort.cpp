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
    for (auto i = v.begin(); i != v.end(); i++)
    {
        if (*i == 69)
        {
            v.erase(i);
            i--;
        }
    }
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

void mergeSort(vector<long long int> &sortVector, int level = 0)
{
    if (level > k)
        k = level + 1;
    if (sortVector.size() <= 1)
    {
        return;
    }

    double middleElement = ceil((double)sortVector.size() / 2);
    vector<long long int> leftVector;
    vector<long long int> rightVector;

    for (int j = 0; j < middleElement; j++)
    {
        if ((int)middleElement != 1 && (sortVector.size() / 2) % 2 == 1)
        {
            sortVector.push_back(69);
        }
        leftVector.push_back(sortVector[j]);
    }

    for (int j = 0; j < (sortVector.size()) - middleElement; j++)
    {
        if (middleElement != 1 && (sortVector.size() / 2) % 2 == 1)
        {
            sortVector.push_back(69);
        }
        rightVector.push_back(sortVector[middleElement + j]);
    }
    vecs.push_back(make_pair(level, leftVector));
    mergeSort(leftVector, level + 1);

    vecs.push_back(make_pair(level, rightVector));
    mergeSort(rightVector, level + 1);
    merge(leftVector, rightVector, sortVector);
    vecs2.push_back(make_pair(k + 1 - level, sortVector));
}

int main()
{
    int n = 0;
    cin >> n;
    vector<long long int> v;
    // vector<long long int> v{56, 135, 15, 1, 9, 24, 17};
    nhap(v, n);
    mergeSort(v);
    cout << "k=1" << endl;
    // const auto &lastVecsKey = prev(vecs.end(), 1)->second;
    int i;
    for (i = 0; i < k; i++)
    {
        bool check = false;
        cout << "[";
        for (auto &e : vecs)
        {
            if (e.first == i)
            {
                xuat(e.second);
                cout << ",";
                check = true;
            }
        }
        cout << "]" << endl;
        if (check == true)
        {
            if (i + 1 == k)
                break;
            cout << "k=" << i + 2;
        }
        cout << endl;
    }
    cout << "k=" << k + 1 << endl;
    for (int j = i - 1; i < 2 * (k - 1); j++)
    {
        bool check = false;
        cout << "[";
        for (auto &e : vecs2)
        {
            if (e.first == j)
            {
                xuat(e.second);
                cout << ",";
                check = true;
            }
        }
        cout << "]" << endl;
        if (check == true)
        {
            if (j + 1 == 2 * (k - 1))
                break;
            cout << "k=" << k + j;
        }
        cout << endl;
    }

    return 0;
}