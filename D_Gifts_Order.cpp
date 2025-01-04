#include <bits/stdc++.h>
using namespace std;

string ckey(const vector<int>& dyd) {
    string key;
    for (int size : dyd) {
        key += to_string(size) + ",";
    }
    return key;
}

int solve(const vector<int>& dyd, unordered_map<string, int>& cache) {
    string key = ckey(dyd);
    
    if (cache.find(key) != cache.end()) {
        return cache[key];
    }

    int n = dyd.size();
    int maxxconv = numeric_limits<int>::min();
    deque<int> maxx, minn;

    for (int l = 0; l < n; ++l) {
        maxx.clear();
        minn.clear();

        for (int r = l; r < n; ++r) {
            while (!maxx.empty() && dyd[maxx.back()] <= dyd[r]) {
                maxx.pop_back();
            }
            maxx.push_back(r);

            while (!minn.empty() && dyd[minn.back()] >= dyd[r]) {
                minn.pop_back();
            }
            minn.push_back(r);

            int current_max = dyd[maxx.front()];
            int current_min = dyd[minn.front()];

            maxxconv = max(maxxconv, current_max - current_min - (r - l));
        }
    }

    cache[key] = maxxconv;
    return maxxconv;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> dyd(n);
        for (int i = 0; i < n; ++i) {
            cin >> dyd[i];
        }

        unordered_map<string, int> cache;
        cout << solve(dyd, cache) << endl;

        for (int i = 0; i < q; ++i) {
            int p, x;
            cin >> p >> x;
            dyd[p - 1] = x;

            cout << solve(dyd, cache) << endl;
        }
    }

    return 0;
}