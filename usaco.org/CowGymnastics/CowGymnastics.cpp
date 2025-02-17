#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int k, n;
	cin >> k >> n;
	set<pair<int,int> > cows, used;
	for (int i = 0; i < k; ++i){
		vector<int> tmp(n);
		for (int j = 0; j < n; ++j) cin >> tmp[j];
		for (int j = 0; j < n; ++j){
			for (int k = j + 1; k < n; ++k){
				int a = tmp[j];
				int b = tmp[k];
				if(cows.count({b, a})){
					used.insert({b, a});
					cows.erase({b, a});
				}
				if(!used.count({a, b}) && !used.count({b, a})) cows.insert({a, b});
			}
		}
	}
	cout << cows.size() << '\n';

	return 0;
}