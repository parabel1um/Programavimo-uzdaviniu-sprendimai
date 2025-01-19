#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxFibonacciness(int t, vector<vector<int>> &test_cases) {
    vector<int> results;

    for (int i = 0; i < t; i++) {
        int a1 = test_cases[i][0], a2 = test_cases[i][1];
        int a4 = test_cases[i][2], a5 = test_cases[i][3];

        int a3_1 = a1 + a2;
        int a3_2 = a4 - a2;
        int a3_3 = a5 - a4;

        int max_fib = 0;

        vector<int> possible_a3 = {a3_1, a3_2, a3_3};
        for (int a3 : possible_a3) {
            int fib = 0;
            if (a3 == a1 + a2) fib++;
            if (a4 == a2 + a3) fib++;
            if (a5 == a3 + a4) fib++;
            max_fib = max(max_fib, fib);
        }

        results.push_back(max_fib);
    }

    return results;
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> test_cases(t, vector<int>(4));

    for (int i = 0; i < t; i++) {
        cin >> test_cases[i][0] >> test_cases[i][1] >> test_cases[i][2] >> test_cases[i][3];
    }
    vector<int> results = maxFibonacciness(t, test_cases);

    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
