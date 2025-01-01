#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    string a;
    vector<char> v;
    int k = 0;
    cin >> a;

    for (int i = 0; i < a.size(); i++) {
        if (find(v.begin(), v.end(), a[i]) == v.end()) { // jeigu negali surasti The std::find function always returns an iterator, and it will never return a "number" like a boolean or an integer directly
            v.push_back(a[i]);
            k++;
        }
    }

    if (k % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else cout << "IGNORE HIM!" << endl;
    return 0;
}