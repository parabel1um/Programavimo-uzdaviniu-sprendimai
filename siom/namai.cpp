// current_max, skaiciujant kiekvienam elementui didziausia, turi buti nustatytas 0, vidinio ciklo pradzioje
// optimaliausia yra pradeti eiti nuo galo i prieki, kadangi po paskutinio elemnto namu nera
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
    freopen("lmio_2017_1et_grazus_namai_vyr.in", "r", stdin);
    freopen("lmio_2017_1et_grazus_namai_vyr.out", "w", stdout);
    
    int N; cin>>N;
    vector<int> A(N), B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    int current_max=A[N-1];
    B[N-1]=0;
    for(int i=N-2;i>=0;i--) {
        if(A[i]<=current_max) B[i]=current_max-A[i]+1;
        else B[i]=0;
        current_max=max(current_max, A[i]);
    }
    for(int a:B) cout<<a<<" ";
    }