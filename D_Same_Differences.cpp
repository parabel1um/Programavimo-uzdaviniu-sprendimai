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
    
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        ll sum=0;
        vector<int> A(n);
        for(int i=0;i<n;i++) cin>>A[i];
        //  sj - si = j - i
        //sj-j=-i+si
        //sj-j=si-i
        //i< j
        // sj-j = si-i
        // skaiciavimas sutampa, tad galima bendrai is pradžių apskaičiuoti
        // kadangi lygu , tai i<j nebesvarbu, bet kokia tvarka
        
        unordered_map<int, int> freq;
        for(int i=0;i<n;i++) {
            int k = A[i]-i;
            sum+=freq[k]; // every single pair can form pair with every previous
            freq[k]++;
        }
        cout<<sum<<endl;
    }
}