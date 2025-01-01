#include <iostream>

using namespace std;

int main() {
    int n, X = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (a.find("++") != string::npos) {
            X++;
        } else if (a.find("--") != string::npos) {
            X--;
        }

    }

    cout << X << endl;
}