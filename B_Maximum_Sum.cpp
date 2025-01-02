#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<long long> a(n);

        for(int i=0; i<n ;i++) 
        {
            cin>>a[i];
        }
        long long maxSum = 0;
        sort(a.begin(), a.end());

        long long sum = accumulate(a.begin(), a.end(), 0LL);
        vector<long long> b(n+1, 0);

        for(int i=0; i<n; i++) 
        {
            b[i+1] = b[i]+a[i];
        }


        for(int i=0; i<=k; i++) 
        {
            maxSum = max(maxSum, b[n-i]-b[2*(k-i)]);
        }

        cout<<maxSum<<endl;
    }
    return 0;
}