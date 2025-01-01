#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        
        long long cycle_distance = a + b + c;
        long long total_distance = 0;
        int day = 0;
        
        day = (n / cycle_distance) * 3;
        n %= cycle_distance;
        
        while (n > 0) {
            day++;
            if (day % 3 == 1) {
                n -= a;
            } else if (day % 3 == 2) {
                n -= b;
            } else {
                n -= c;
            }
        }
        
        cout << day << endl; 
    }
    return 0;
}
