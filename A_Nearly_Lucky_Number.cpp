#include <bits/stdc++.h>
using namespace std;
int main() {
    string n;cin>>n;
    int c=0;
    for(char a: n){
        if (a=='4'||a=='7') c++;
    }
    string a = to_string(c);
    for(char k:a){
        if(k!='4' && k!='7') {cout<<"NO"; return 0;}
    }
    cout<<"YES";
    return 0;
}