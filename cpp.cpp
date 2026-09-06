#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void ym(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int q) {
    int n = A.size();
    int m = A[0].size();
    int k = B[0].size();
    
    for (int i = 0; i < k; i++) {
        C[q][i] = 0;
        for (int j = 0; j < m; j++) {
            C[q][i] += A[q][j] * B[j][i];
        }
    }
}

int main() {
    int n = 3;
    int m = 2;
    int k = 4;
    vector<vector<int>> A = {{1, 2}, {3, 4}, {5, 6}};
    vector<vector<int>> B = {{7, 8, 9, 10}, {11, 12, 13, 14}};
    vector<vector<int>> C(n, vector<int>(k, 0));

    vector<thread> a;
    a.reserve(n);

    for (int i = 0; i < n; i++) {
        a.push_back(thread(ym,ref(A), ref(B), ref(C), i));
    }
    for (int i = 0; i < a.size(); i++) {
        a[i].join();
    }

    cout << "a*b:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
