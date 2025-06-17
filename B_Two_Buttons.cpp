#include <bits/stdc++.h>
using namespace std;

int ShortestPathBFS(int n, int m) {
    queue<pair<int, int>> A; // Naudojame pair, nes REIKIA SURASTI SHORTEST PATH - t.y. reikia skaičiuoti ėjimų kiekį
    unordered_set<int> visited;
    A.push({n, 0});
    visited.insert(n);

    while(!A.empty()) {
        auto [curr, k] = A.front(); A.pop();
        if(curr==m) return k;
        
        // sudarome grafiką ir visada tikriname visited masyvą
        // for(string& a : graph[current]){
        //   if(!visited.count(a)){
        //     stack.push({a, distance+1});
        //     visited.insert(a); 
        //   }
        // }

        if(2*curr<=2*m&&!visited.count(2*curr)) {
            A.push({2*curr, k+1});
            visited.insert(2*curr);
        }

        if(curr-1>0&&!visited.count(curr-1)) {
            A.push({curr-1, k+1});
            visited.insert(curr-1);
        }

    }
    return -1;
}

int main() {
    int n, m; cin>>n>>m;
    cout<<ShortestPathBFS(n, m)<<endl;
}