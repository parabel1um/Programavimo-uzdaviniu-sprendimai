#include <bits/stdc++.h>
using namespace std;

int solve(string s, string iesk) {
    int n = s.length();
    int k = INT_MAX;
    //Pvz. 71345
    //pradedame nuo galo ir einame atgal
    for(int i=n-1;i>=0;i--) {
        if(s[i] == iesk[1]) { // pradedame nuo 5 pvz. likę yra 7134
            // Find rightmost occurrence of first digit before i
            for(int j=i-1;j>=0;j--) { // pradedame jau nuo kito, dėl to j-1
                if(s[j] == iesk[0]) {
                    // Skaičius jau yra rastas, beliko surasti skaitmenų kiekį tarp jų
                    k = min(k, n-j-2);
                }
            }
        }
    }
    return k;
}

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int ans = INT_MAX;
        ans = min(ans, solve(s, "00"));
        ans = min(ans, solve(s, "25"));
        ans = min(ans, solve(s, "50"));
        ans = min(ans, solve(s, "75"));
        cout << ans << endl;
    }
    return 0;
}