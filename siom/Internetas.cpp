/*
unordedred_map netinka, kadangi duomenys sudėlioti didėjimo tvarka
//  pirmo ir paskutinio matavimo metu jis interneto ryšį turėjo., todėl iš karto prev=1
Ti<T(i+1), todėl nereikia sort
*/
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

    freopen("lmio_2018_1et_internetas_vyr.in", "r", stdin);
    freopen("lmio_2018_1et_internetas_vyr.out", "w", stdout);
    
    int N, T,M, maxi=0;cin>>N>>T>>M;
    int prev=T;
    for(int i=1;i<N;i++) {
        int T, M;cin>>T>>M;
        if(M==1){
            maxi=max(maxi, T-prev);
            prev=T;
        }
    }
    cout<<maxi<<endl;
    return 0;
}