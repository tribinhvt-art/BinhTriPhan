#include <iostream>
#include <vector>
using namespace std;

void combine(vector<int>& x, vector<int>& y, int p) {
    for (int i = 0; i < y.size(); i++) {
        x.insert(x.begin() + p + i, y[i]);
    }
}

int main() {
    vector<int> x = {4, 6, 8};
    vector<int> y = {2, 3};

    combine(x, y, 1);

    for (int n : x)
        cout << n << " ";

    return 0;
}