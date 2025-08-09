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
        int n, sum=0;cin>>n;
        string s;cin>>s;
        set<char> freq; // count doesnt matter
        for(char a:s) {
            if(!freq.count(a))sum++;
            freq.insert(a);
            sum++;
        }
        cout<<sum<<endl;
    }
}