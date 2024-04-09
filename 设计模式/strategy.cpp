#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 抽象策略类*/
class Sort
{
public:
    virtual void sort(vector<int>& v) = 0;
};

class BubbleSort : public Sort
{
public:
    virtual void sort(vector<int>& v)
    {
        cout << "bubble sort" << endl;
        for (int idx = 0; idx < v.size(); ++idx)
        {
            for (int jdx = idx + 1; jdx < v.size(); ++jdx)
            {
                if (v[idx] > v[jdx])
                {
                    swap(v[idx], v[jdx]);
                }
            }
        }
    }
};

class QuickSort : public Sort
{
public:
    virtual void sort(vector<int>& v)
    {
        cout << "quick sort" << endl;
        std::sort(v.begin(), v.end());
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    random_shuffle(v.begin(), v.end());
    
    cout << "before sort:" << endl;
    for_each(v.begin(), v.end(), [](int i){cout << i << " ";});
    cout << endl;
    
    // Sort* sort = new BubbleSort();
    Sort* sort = new QuickSort();
    sort->sort(v);
    cout << "after sort:" << endl;
    for_each(v.begin(), v.end(), [](int i){cout << i << " ";});
    cout << endl;
    return 0;
}