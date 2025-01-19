#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t; cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   vector<int>vec(n);
	   for(int i=0;i<n;i++) cin>>vec[i];
	   bool c=false;
	   for (int i= 0 ;i<n-1;i++) {
	       if(vec[i]>vec[i+1])
	       {
	           c=true;
	           break;
	       }
	       else
	       {
	           vec[i+1]-=vec[i];
	           vec[i]=0;
	           
	       }
	   }
	   
	   
	   if(c) cout<<"NO"<<endl;
       else cout<<"YES"<<endl;
	}
	return 0;

}
