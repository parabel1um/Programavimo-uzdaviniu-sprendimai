#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   vector<int>A(n);
	   for(int i=0;i<n;i++) cin>>A[i];
	   bool pos=false;
	   for (int i= 0;i<n-1;i++) {
	       if(A[i]>A[i+1])
	       {
	           pos=true;
	           break;
	       }else
	       {
	           A[i+1]-=A[i];
	           A[i]=0;
	           
	       }
	   }
	   if(!pos) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
	}
	return 0;
}
