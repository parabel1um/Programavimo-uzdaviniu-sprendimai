#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A[6][6], m, n;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                m = i;
                n = j;
            } else {
                A[i][j] = a;
            }
        }
    }
    cout << abs(3 - m) + abs(3 - n) << endl;

}