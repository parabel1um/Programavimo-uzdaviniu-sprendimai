#include <bits/stdc++.h>
using namespace std;

int dp[10][2][2]; // memoization table
string l,r;

int solve(int u, bool Lres, bool Rres) {
    if (u==(int)l.size()) return 0;
    int &res=dp[u][Lres][Rres];
    if (res!=-1) return res;
    int zem=Lres ? (l[u] -'0') : 0;
    int aukst=Rres?(r[u] - '0') :9;

    res = INT_MAX;
    for (int d=zem;d<=aukst;d++) {
        int k=0;
        if (d==(l[u] - '0')) k++;
        if (d==(r[u] - '0')) k++;
        bool kitLres = Lres && (d== zem);
        bool kitRres = Rres && (d ==aukst);
        res = min(res, k + solve(u + 1, kitLres, kitRres));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while (t--) {
        cin>>l>>r;
        // while((int)l.size()<(int)r.size()) l='0'+l;
        if (l.size()<r.size()) l=string(r.size() - l.size(), '0') + l;

        // for (int i=0;i<10;i++){
        //     for (int j=0;j<2;j++) {
        //         for (int k=0;k<2;k++) {
        //             dp[i][j][k] = -1;
        //         }
        //     }
        // }
        memset(dp, -1, sizeof(dp));
        cout<<solve(0, true, true)<<'\n';
    }
}
