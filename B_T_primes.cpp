#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void sieve_of_eratosthenes(int limit, vector<bool>& sieve) {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int limit = 1000000;
    vector<bool> sieve(limit + 1, true);
    sieve_of_eratosthenes(limit, sieve);

    while (n--) {
        long long x;
        cin >> x;

        long long sqrta = sqrt(x);
        if (sqrta * sqrta == x && sieve[sqrta]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
