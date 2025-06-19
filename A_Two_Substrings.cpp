#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    string s;cin>>s;
    int n=s.size();
    //AB...BA
    for(int i=0;i<n-1;i++){
        if(s[i]=='A'&&s[i+1]=='B') {
            for(int j=i+2;j<n;j++){ //jeigu rastas AB 2 vietas praleidžiame ir einame iki galo
                if(s[j]=='B'&&s[j+1]=='A'){
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    //BA..AB
    for(int i=0;i<n-1;i++) {
        if(s[i]=='B'&&s[i+1]=='A'){
            for(int j=i+2;j<n;j++){
                if(s[j]=='A'&&s[j+1]=='B'){
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;
}