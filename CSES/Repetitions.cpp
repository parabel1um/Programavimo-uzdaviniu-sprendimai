#include <bits/stdc++.h>
using namespace std;
int main() {
    string n;cin>>n;
    long long k=1, maxx=1;
    char prev=n[0];
    for(int i=1;i<n.size();i++){
        if(n[i]==prev) k++;
        else k=1;
        maxx=max(maxx,k);
        prev=n[i];
    }
    cout<<maxx<<endl;
}