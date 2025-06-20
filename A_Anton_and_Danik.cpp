#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s;cin>>s;
    unordered_map<char, int> freq; // pirma reikšmė, po to kas už jos glūdi
    for(char a:s){
        freq[a]++;
    }
    if(freq['A']>freq['D']) cout<<"Anton\n";
    else if(freq['A']<freq['D']) cout<<"Danik\n";
    else cout<<"Friendship\n";
    
}