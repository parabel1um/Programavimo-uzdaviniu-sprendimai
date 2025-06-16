#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <deque>
using namespace std;

int connectedComponentsCount(unordered_map<int, vector<int>> graph) {
  int k=0;
  unordered_set<int> visited;
  for(auto& pair: graph) {
      if(visited.count(pair.first)) continue;
      deque<int> stack;
      stack.push_back(pair.first);
      while(!stack.empty()) {
        int current = stack.back();
        stack.pop_back();

        if(visited.count(current)) continue;
        else visited.insert(current);

        for(int i=graph[current].size()-1;i>=0;i--){
          stack.push_back(graph[current][i]);
        }
    }
    k++;
  }

  return k;
}



void run() {
  unordered_map<int, vector<int>> graph {
    { 0, { 8, 1, 5 } },
    { 1, { 0 } },
    { 5, { 0, 8 } },
    { 8, { 0, 5 } },
    { 2, { 3, 4 } },
    { 3, { 2, 4 } },
    { 4, { 3, 2 } }
  };
  connectedComponentsCount(graph); 
}