#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v, int x) 
{
    int low = 0, high = v.size() - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == x)
            return mid;
        if (v[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() 
{
    vector<int> v = {1, 2, 3, 4, 5};
    int x = 3;
    int result = binarySearch(v, x);
    if (result == -1)
        cout << "Element not present in the vay" << endl;
    else
        cout << "Element found at index: " << result << endl;
    return 0;
}