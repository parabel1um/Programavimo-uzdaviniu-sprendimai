#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin>>s;
    int up=0, low=0;
    for(char a:s) {
        if(a>='A' && a<='Z') up++; else low++;
    }
    if(low>=up) transform(s.begin(), s.end(), s.begin(), ::tolower); else transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout<<s<<endl;
}