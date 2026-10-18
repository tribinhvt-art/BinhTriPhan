#include <iostream>
#include <vector>
using namespace std;

void insertArray(vector<int>& a, vector<int>& b) {
    a.insert(a.begin() + 2, b.begin(), b.end());
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {9, 9};

    insertArray(a, b);

    for (int x : a) {
        cout << x << " ";
    }

    return 0;
}