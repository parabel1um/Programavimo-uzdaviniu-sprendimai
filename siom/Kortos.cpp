// array dydis turi siek tiek virsyti default, jeigu N=1000, A[1010]
//int S[15] = {0}; - nustato visas lygias 0
// for loop'e reikia pradeti nuo 1, kadangi kortos maziausia verte - 1
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lmio_2018_1et_kortos_vyr.in", "r", stdin);
    freopen("lmio_2018_1et_kortos_vyr.out", "w", stdout);
    
    int S[15] ={0};
    int B[15] = {0};
    int V[15]={0};
    int K[15]={0};
    
    for(int i =0;i<51;i++) {
        char c;
        int v; cin>>c>>v;
        
        switch(c) {
            case 'S': S[v]++; break;
            case 'B': B[v]++; break;
            case 'V': V[v]++; break;
            case 'K': K[v]++; break;
        }
    }

    for(int j=1;j<14;j++) {
        if(!S[j]) cout<<"S "<<j<<endl;
        if(!B[j]) cout<<"B "<<j<<endl;
        if(!V[j]) cout<<"V "<<j<<endl;
        if(!K[j]) cout<<"K "<<j<<endl;
    }
}