#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--){
        int n, c1=0, c2=0, sum=0;cin>>n;
        for(int i=0;i<n;i++) {
            int x;cin>>x;
            if(x==1) c1++;
            else c2+=2;
            sum+=x;
        }
        if(sum%2!=0) {
            cout<<"NO\n";
            continue;
        }
        if((sum/2)%2==0) {// lyginis lyginis = lyginis, žinome, jog suma jau lyginė
            cout<<"YES\n";
            continue;
        } else {
            if(c1>0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}