#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k=0; cin>>n;
    vector<int> managers;
    unordered_map<int, vector<int>> M; // immediate(kas virsuje bus)
    bool u=false;
    for(int i=0;i<n;i++) {
        int emp;cin>>emp;
        if(emp==-1) managers.push_back(i); // negalime A[-1] nes bus kelios reiksmes tada
        else M[emp-1].push_back(i); // pvz 2(3)=A[2]
    }
    int maxxgroup=0;
    for(auto complete:managers) {
        queue<pair<int, int>> q; // nenaudojame visited, nes visi turės tik vieną manager
        q.push({complete, 1});

        while(!q.empty()) {
            auto [curr, dep] = q.front();
            q.pop();

            maxxgroup = max(maxxgroup, dep);

            for(auto emp:M[curr]) {
                q.push({emp, dep+1});
            }
        }
    }
    cout<<maxxgroup<<endl;
    return 0;
}