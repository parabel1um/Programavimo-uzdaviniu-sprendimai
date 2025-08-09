#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi  vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;cin>>n>>m;
    vector<int> A(n);
    vector<int> B(m);

    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<m;i++) cin>>B[i];
    // problem is asking for elements STARTING AT
    // when searching for distinct numbers - better ti traverse backwards
    unordered_set<int> visit;
    int c=0; // - number of distinct
    vector<int> C(n); // prefix sum of distinct number from the end
    for(int i=n-1;i>-1;i--){
        if(visit.find(A[i])==visit.end()) {
            visit.insert(A[i]);
            c++;
        }
        C[i]=c;
    }
    for(int l:B) {
        cout<<C[l-1]<<endl;
    }
}