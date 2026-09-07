#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void f(vector<vector<int>>& a, vector<int>& x, vector<int>& y, int s, int e) {
    for (int i = s; i < e; i++) {
        y[i] = 0;
        for (int j = 0; j < 3; j++) {
            y[i] += a[i][j] * x[j];
        }
    }
}

int main() {
    int n = 4;
    int m = 3;
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    vector<int> x = {1, 2, 3};
    vector<int> y(n, 0);

    vector<thread> t;
    t.push_back(thread(f, ref(a), ref(x), ref(y), 0, 2));
    t.push_back(thread(f, ref(a), ref(x), ref(y), 2, 4));

    for (int i = 0; i < 2; i++) {
        t[i].join();
    }
    for (int i = 0; i < n; i++) {
        cout << y[i] << " ";
    }
}