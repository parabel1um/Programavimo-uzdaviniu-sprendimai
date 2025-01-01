#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    vector<pair<int, int>> lenkimai;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = i+1;
    }

    for (int i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            int o = find(b.begin(), b.end(), a[i]) - b.begin();
            lenkimai.push_back({b[o], b[i]});
            swap(b[i], b[o]);
        }
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool already_overtaken = false;
            for (const auto& lenk : lenkimai) {
                if ((lenk.first == b[i] && lenk.second == b[j]) || 
                    (lenk.first == b[j] && lenk.second == b[i])) {
                    already_overtaken = true;
                    break;
                }
            }
            if (!already_overtaken) {
                lenkimai.push_back({b[j], b[i]});
                lenkimai.push_back({b[i], b[j]});
            }
        }
    }


    cout << lenkimai.size() << endl;
    for (const auto& lenk : lenkimai) {
        cout << lenk.first << " " << lenk.second << endl;
    }
}