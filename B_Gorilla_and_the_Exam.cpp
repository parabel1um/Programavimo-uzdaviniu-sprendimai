#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    
    cin>>t;

    while(t--){
        int n, k, j=0; 
        
        cin >> n >> k;

        vector<int>a(n),freq; 
        map<int,int>mp;


        for(int i=0; i<n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }

        for(auto it:mp) freq.push_back(it.second);

        sort(freq.begin(), freq.end());

        int idx=0;

        for(int i=0; i<freq.size(); i++){
            if(freq[i] > k) break;
            j++;
            k-=freq[i];
        }
        int laikin =freq.size() - j;

        cout << max(1, laikin) << endl;
    }
    return 0;
}