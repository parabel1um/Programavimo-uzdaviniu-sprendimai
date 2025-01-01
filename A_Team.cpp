#include <iostream>

using namespace std;

int main() {
    int n, X = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (a.find("++")) {
            X++;
        } else if (a.find("--")) {
            X--;
        }

    }

    cout << X << endl;
}