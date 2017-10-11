/*
Given an undirected graph with n vertices and m edges.
Compute the number of connected components in it
*/
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;

void explore(vector<vector<int> > &adj, std::vector<int> neighbor, std::vector<bool>& visisted){
	for (int i = 0; i < neighbor.size(); i++){
		if(!visisted[neighbor[i]]){
			visisted[neighbor[i]] = true;
			explore(adj,adj[neighbor[i]],visisted);
		}
	}
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
	vector<bool> visisted(adj.size(), false);
	for (int i = 0; i < adj.size(); i++){
		if(!visisted[i]){
			visisted[i] = true;
			explore(adj, adj[i], visisted);
		  res++;
		}
	}
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
