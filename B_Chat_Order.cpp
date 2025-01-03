#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> a(n+1);
    map<string, bool>m;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }


    for(int i=n-1; i>=0; i--)
    {
        if(m[a[i]] !=1 ){
            cout<<a[i] <<endl;
            m[a[i]]=1;
        }
    }


    return 0;
}