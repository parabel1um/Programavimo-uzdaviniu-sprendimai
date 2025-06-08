

    #include<bits/stdc++.h>
    using namespace std;
    int main(){
      int t;cin>>t;
      while(t--){
      	int n, k, c=0; // c - lyginių skaičių kiekis
      	cin>>n>>k;
      	int ans=k; // ans - kiek kartų reikia padidinti kažkurį iš skaičių
      	for(int i=0;i<n;i++){
      		int x;
      		cin>>x;
     
      		if(x%2==0)c++;
      		if(x%k==0)ans=0;
      		
      		ans=min(ans,k-x%k); // jeigu pirminis, 
      	}
      	if(k==4){ // jei skaičius yra pirminis: 2, 3, 5, tai galima prie kiekvieno pridėti nulį ir tikrinti ar dalinasi iš k, nes neturi kitų dalklių
            //4 yra special numeris, nes nėra pirminis
            // 1 1 -> 1 4 = 3
            // 1 1 -> 2 2 = 2
      		if(c>=2)ans=0;
      		else if(c==1)ans=min(ans,1);
      		else ans=min(ans,2);
      	}
      	cout<<ans<<endl;
      }
    }