#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
	int n;cin>>n;
	vector<pair<int, int>> M(n);
	int max_time=0;
	for (auto& a : M) {
		cin>>a.first>>a.second;
		max_time = max(max_time, a.second);
	}

	int max_cover = 0;
	for (int i = 0; i < n; i++) {
		int covered = 0;
		for (int t = 1; t <= max_time; t++) { // pereiname per didziausia galima laika
			for (int j = 0; j < n; j++) { // pereiname per visas karves ir tikriname ar musu isrinktoji nera atmesta
				if (j != i) { // nera atmesta karve
					if (M[j].first <= t && t < M[j].second) { // tikriname ar t yra kurios nors kitos karves intervale 
						covered++; // pridedame 1 prie viso galimo laiko, laikai nebutinai turi eiti paeiliui, gali buti tarpas tarp ju
						break;
					}
				}
			}
		}
		max_cover = max(max_cover, covered);
	}
    cout<<max_cover<<endl;
}