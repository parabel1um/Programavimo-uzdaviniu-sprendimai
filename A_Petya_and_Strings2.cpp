#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a, b, abc;
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < 26; i++) { // užpildome abecėlę
        abc += 'a' + i;
    }

    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        int n1 = find(abc.begin(), abc.end(), tolower(a[i])) - abc.begin(); 
        int n2 = find(abc.begin(), abc.end(), tolower(b[i])) - abc.begin();

        sum1 += n1;
        sum2 += n2;
    }

    if (sum1 > sum2) {
        cout << 1 << endl;
    } else if (sum1 < sum2) {
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
 
}