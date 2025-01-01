#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a, b;
    double priceMin;
    int kaina;

    cin >> n >> m >> a >> b;

    priceMin = min((double)a, (double)b / m);

    if (priceMin == a) {
        kaina = n * a;
    } else {
        int kiek = n / m;
        int lik = n % m;
        kaina = kiek * b + lik * a;
        
        kaina = min(kaina, (kiek + 1) * b);
    }

    cout << kaina << endl;

    return 0;
}
