/*
Compute a topological ordering of a given directed acyclic graph (DAG)
with n vertices and m edges
*/
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
    for (int i = 0; i < adj[x].size(); i++){
        if(!used[adj[x][i]]){
            used[adj[x][i]] = 1;
            dfs(adj,used,order,adj[x][i]);
            order.push_back(adj[x][i]);
        }
    }
}

vector<int> toposort(vector<vector<int> > adj) {
    vector<int> used(adj.size(), 0);
    vector<int> order;
    for (int i = 0; i < adj.size(); i++){
        if(!used[i]){
            used[i] = 1;
            dfs(adj,used,order,i);
            order.push_back(i);
        }
    }
    return order;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    //Create a graph
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    //Topsort
    vector<int> order = toposort(adj);
    for (int i = order.size() - 1; i >= 0; i--) {
        std::cout << order[i] + 1 << " ";
    }
}
