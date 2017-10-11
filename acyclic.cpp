/*
Check whether if a given directed graph with n vertices and m edges contains a cycle
Output 1 if cyclic, 0 if acyclic
*/
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;

int explore(vector<vector<int>> &adj, vector<int>& visisted, int n, int begin){
	for (int i = 0; i < adj[n].size(); i++){
		if (!visisted[adj[n][i]]){
			visisted[adj[n][i]] = 1;
			explore(adj, visisted, i, begin);
		}
		if (adj[n][i] == begin)
			return 1;
		else
			return 0;
	}
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
	int is_cyclic = 0;
	vector<int> visisted(adj.size(),0);
	for (int i = 0; i < adj.size() && !is_cyclic; i++){
		if(!visisted[i]){
			visisted[i] = 1;
			is_cyclic = explore(adj, visisted, i, i);
		}
	}
	return is_cyclic;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
