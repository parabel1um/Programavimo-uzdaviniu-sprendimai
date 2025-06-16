#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> createGraph(vector<tuple<string, string>> edges) {
  unordered_map<string, vector<string>> graph;
  for(auto [a, b]:edges) { // with tuples use [a, b]
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}

int shortestPath(vector<tuple<string, string>> edges, string nodeA, string nodeB) {
  if(nodeA==nodeB) return 0;
  unordered_map<string, vector<string>> graph = createGraph(edges);
  unordered_set<string> visited;
  int maxlength = 100005;
  queue<pair<string, int>> stack;
  stack.push({nodeA, 0});
  visited.insert(nodeA);
  while(!stack.empty()) {
    auto [current, distance] = stack.front();
    stack.pop();
    if(current==nodeB) {
      return distance;
    }
    
    for(string& a : graph[current]){
      if(!visited.count(a)){
        stack.push({a, distance+1});
        visited.insert(a); 
      }
    }
  }
  

  
  return -1;
}



void run() {
  vector<tuple<string, string>> edges {
    {"w", "x"},
    {"x", "y"},
    {"z", "y"},
    {"z", "v"},
    {"w", "v"}
  };
  shortestPath(edges, "w", "z");
}