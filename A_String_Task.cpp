#include <bits/stdc++.h>
using namespace std;
int main() {
    string n; cin>>n;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
    for(auto x:n) {
        if(find(vowels.begin(), vowels.end(), tolower(x)) == vowels.end()) cout<<"."<<(char)tolower(x);
    }
}