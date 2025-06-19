#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> coins = {100, 20, 10, 5, 1};
unordered_map<ll, ll> memo;

ll minCoins(ll n) { // suma, kurią reikia sudaryti
    if (n == 0) return 0;
    if (memo.count(n)) return memo[n];

    ll ans = LLONG_MAX;
    for (int coin : coins) {
        if (n >= coin) {
            ans = min(ans, 1+minCoins(n-coin)); // pridedame vieną, nes jau jį padanaudojome, n-coin- kiek dar rejmja likučiui
        } // kai pasiekiame 0 grąžina 0, pavyzdžiui {1,3,4} kai n=3 jau turi memo išsaugojęs 3, tačiau bando su 3, nes lygu, tada callina minCoins(0);
    }
    memo[n] = ans;
    return ans;
}

ll greedyMinCoins(ll n) {
    vector<int> coins = {100, 20, 10, 5, 1};
    ll count = 0;
    for (int coin : coins) {
        count += n / coin;
        n %= coin;
    }
    return count;
}

int main() {
    ll n;
    cin >> n;
    cout << greedyMinCoins(n) << endl;
}
