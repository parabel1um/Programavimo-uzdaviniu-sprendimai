#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>
using namespace std;

int largestComponent(std::unordered_map<int, std::vector<int>> graph) {
  int maxx = 0;
  unordered_set<int> visited;
  for(auto pair: graph) {
    if(visited.count(pair.first)) continue;
    int u =0;
    deque<int> stack;
    stack.push_back(pair.first);

    while(!stack.empty()) {
      int current = stack.back();
      stack.pop_back();

      if(visited.count(current)) continue;
      visited.insert(current);
      u++;

      for(auto a : graph[current]) {
        stack.push_back(a);
      }
    }
   maxx=max(maxx, u);
  }
  return maxx;
}



void run() {
  unordered_map<int, vector<int>> graph {
    { 0, {8, 1, 5} },
    { 1, {0} },
    { 5, {0, 8} },
    { 8, {0, 5} },
    { 2, {3, 4} },
    { 3, {2, 4} },
    { 4, {3, 2} }
  };
  largestComponent(graph);
}