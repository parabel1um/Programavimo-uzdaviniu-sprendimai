#include <iostream>
#include <vector>

using namespace std;

long long Skirstyti(vector<long long> a, int n, long long visa) {
    long long dabSuma = 0;
    long long gaunama = visa / 3;
    long long budai = 0;
    long long k = 0;

    if (visa % 3 != 0) {
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        dabSuma += a[i];
        
        if (dabSuma == 2 * gaunama) {
            budai += k;
        }

        if (dabSuma == gaunama) {
            k++;
        }
    }

    return budai;
}

int main() {
    long long n, visa = 0;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        visa += a[i];
    }

    cout << Skirstyti(a, n, visa) << endl;

}