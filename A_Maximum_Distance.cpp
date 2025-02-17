#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);

	for (int &t : x) cin >> t;
	for (int &t : y) cin >> t;

	int max_squared = 0;                  
	for (int i = 0; i < n; i++) {         
		for (int j = i + 1; j < n; j++) { 
			int square = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
			max_squared = max(max_squared, square);
		}
	}

	cout << max_squared << endl;
}