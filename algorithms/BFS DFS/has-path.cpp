#include <unordered_map>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

bool hasPath(unordered_map<string, vector<string>>A, string a, string b) {
  if(a==b) return false;
  deque<string> stack;
  stack.push_back(a);

  while(!stack.empty()) {
    string current = stack.back(); //nes reikia rasti to elemneto kaimynus, front būtų praeito 
    stack.pop_back();

    if(current == b) return true;

    for(int i = A[current].size()-1;i>=0;i--){
      stack.push_back(A[current][i]);
    }
  }
  return false;
};

int main() {
  unordered_map<string, vector<string>> graph {
    { "f", {"g", "i"} },
    { "g", {"h"} },
    { "h", {} },
    { "i", {"g", "k"} },
    { "j", {"i"} },
    { "k", {} }
  };

  
    hasPath(graph, "f", "k");
}
