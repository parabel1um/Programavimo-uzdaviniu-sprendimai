#include <bits/stdc++.h>
using namespace std;

struct Karv {
	int start, end;
};

int main() {
	freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
	int n;cin>>n;
	vector<Karv> M(n);
	int max_time=0;
	for (Karv &a : M) {
		cin>>a.start>>a.end;
		max_time = max(max_time, a.end);
	}

	/*
	Bandome kiekvieną atleisti, ir apskaičiuoti likusį kitų karvių laiką
	 */
	int max_cover = 0;
	for (int i = 0; i < n; i++) {
		int covered = 0;
		for (int t = 1; t <= max_time; t++) {
			for (int j = 0; j < n; j++) {
				if (j != i) {
					if (M[j].start <= t && t < M[j].end) {
						covered++;
						break;
					}
				}
			}
		}
		max_cover = max(max_cover, covered);
	}
    cout<<max_cover<<endl;
}