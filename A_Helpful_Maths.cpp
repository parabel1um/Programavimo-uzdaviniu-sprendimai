#include <iostream>

using namespace std;
int main() {
    string a;
    cin >> a;

    if (a.length() == 1) {
        cout << a << endl;
        return 0;
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size() - 2; j++) {
            if (a[i] != '+' && a[j] > a[j+2]) {
                swap(a[j+2], a[j]);
            }
        }
    }

    cout << a << endl;
    return 0;
}