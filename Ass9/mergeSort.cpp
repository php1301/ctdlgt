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
    vector<long long int> v;
    // vector<long long int> v{56, 135, 15, 1, 9, 24, 17};
    nhap(v, n);
    mergeSort(v, n);
    cout << "k=1" << endl;
    // const auto &lastVecsKey = prev(vecs.end(), 1)->second;
    int i;
    for (i = 0; i < k - 1; i++)
    {
        bool check = false;
        cout 
             << "[";
        for (auto &e : vecs)
        {
            if (e.first == i)
            {
                xuat(e.second);
                cout << ",";
                check = true;
            }
        }
        cout << "\b";
        cout << "]" << endl;
        // cout << endl;
        if (check == true)
        {
            if (i + 1 == k - 1)
                break;
            cout << "k=" << i + 2;
        }
        cout << endl;
        check = false;
    }
    cout << "k=" << i + 2 << endl;
    for (int j = k - 2; j >= 0; j--)
    {
        bool check = true;
        for (auto &e : vecs2)
        {
            if (e.first == k + 1 - j)
            {
                if (check == true)
                    cout 
                         << "[";
                xuat(e.second);
                cout << ",";
                check = false;
            }
        }
        cout << "\b";
        cout << "]" << endl;
        // cout << endl;
        if (j - 1 == -1)
            break;
        cout << "k=" << 2 * k - j - 1;
        cout << endl;
    }

    return 0;
}