#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
using namespace std;

void f(vector<int>& x, vector<int>& y, vector<int>& z, vector<int>& d, int s, int e) {
    for (int i = s; i < e; i++) {
        d[i] = sqrt(x[i] * x[i] + y[i] * y[i] + z[i] * z[i]);
    }
}

int main() {
    int n = 6;
    int k = 2;
    vector<int> x = {1, 2, 3, 4, 5, 6};
    vector<int> y = {1, 2, 3, 4, 5, 6};
    vector<int> z = {1, 2, 3, 4, 5, 6};
    vector<int> d(n, 0);

    int r = n / k;
    vector<thread> t;
    for (int i = 0; i < k; i++) {
        t.push_back(thread(f, ref(x), ref(y), ref(z), ref(d), i * r, (i + 1) * r));
    }
    for (int i = 0; i < k; i++) {
        t[i].join();
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
}
