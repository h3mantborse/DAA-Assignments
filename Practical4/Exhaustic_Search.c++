#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

bool check(vector<int> &numbers, int target) {
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return sum == target;
}

void exhaustiveSearch(vector<int> &numbers, int target) {
    int n = numbers.size();
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(numbers[j]);
            }
        }
        if (check(subset, target)) {
            cout << "A subset with the target sum was found: { ";
            for (int j = 0; j < subset.size(); j++) {
                cout << subset[j] << " ";
            }
            cout << "}" << endl;
            return;
        }
    }
    cout << "No subset with the target sum was found." << endl;
}

int main() {
    vector<int> numbers;
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    cout << "Enter the target sum: ";
    cin >> target;

    exhaustiveSearch(numbers, target);

    return 0;
}
