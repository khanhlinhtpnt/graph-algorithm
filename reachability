/*
Given an undirected graph and 2 distinct vertices u and v
Check if there is a path between u and v
Output 1 if there is a path and 0 if otherwise
*/
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;

void explore(vector<vector<int>> &adj, vector<int>& visisted, int n, int begin, int& is_cyclic){
    for (int i = 0; i < adj[n].size(); i++){
        if (adj[n][i] == begin)
            is_cyclic = 1;
        if (!visisted[adj[n][i]]){
            visisted[adj[n][i]] = 1;
            explore(adj, visisted, adj[n][i], begin, is_cyclic);
        }
    }
}

int acyclic(vector<vector<int> > &adj){
    int is_cyclic = 0;
    vector<int> visisted(adj.size(),0);
    for (int i = 0; i < adj.size() && !is_cyclic; i++){
        if(!visisted[i]){
            visisted[i] = 1;
            explore(adj, visisted, i, i, is_cyclic);
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
/*
Sample:
Input
4 4
1 2
3 2
4 3 
1 4
1 4
Output
1
*/
