/*
Compute the number of strongly connected components of a given directed graph
with n vertices and m edges
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> reverse_graph(vector<vector<int>> adj){
    vector<vector<int>> adj_rev(adj.size(), vector<int>());
    for (int i = 0; i < adj.size(); i++){
        for (int j = 0; j < adj[i].size(); j++){
            adj_rev[adj[i][j]].push_back(i);
        }
    }
    return adj_rev;
}

void preorder(vector<int>& pre_order, int i, int& clock){
    pre_order[i] = clock;
    clock++;
}

void postorder(vector<int>& post_order, int i, int& clock){
    post_order[i] = clock;
    clock++;
}

void dfs(vector<vector<int> > &adj, vector<int> &visisted, int x, vector<int>& pre_order, vector<int>& post_order, int& clock ) {
    for (int i = 0; i < adj[x].size(); i++){
        if(!visisted[adj[x][i]]){
            visisted[adj[x][i]] = 1;
            preorder(pre_order, adj[x][i], clock);
            dfs(adj,visisted,adj[x][i],pre_order,post_order, clock);
            postorder(post_order,adj[x][i],clock);
        }
    }
}

int maxIndex(vector<int> v){
    int maxIndex = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i] > v[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

void sort_order(vector<int>& post_order){
    vector<int> new_order(post_order.size());
    for (int i = 0; i < post_order.size(); i++){
        int index = maxIndex(post_order);
        post_order[index] = 0;
        new_order[i] = index;
    }
    post_order = new_order;
}
void explore(vector<vector<int> > &adj, vector<int> &visisted, int x){
    for (int i = 0; i < adj[x].size(); i++){
        if(!visisted[adj[x][i]]){
            visisted[adj[x][i]] = 1;
            explore(adj,visisted,adj[x][i]);
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
    int scc = 0;
    vector<vector<int>> adj_rev = reverse_graph(adj);
    std::vector<int> pre_order(adj.size());
    std::vector<int> post_order(adj.size());
    std::vector<int> visisted(adj.size(),0);

    int clock = 1;
    // DFS reverse graph to find post order:
    for (int i = 0; i < adj_rev.size(); i++){
        if(!visisted[i]){
            visisted[i] = 1;
            preorder(pre_order, i, clock);
            dfs(adj_rev,visisted,i,pre_order,post_order, clock);
            postorder(post_order,i,clock);
        }
    }
    // sort post order:
    sort_order(post_order);
    // DFS in reverse order;
    visisted = vector<int> (adj.size(), 0);
    for (int i = 0; i < post_order.size(); i++){
        if(!visisted[post_order[i]]){
            visisted[post_order[i]] = 1;
            explore(adj, visisted, post_order[i]);
            scc++;
        }
    }
    return scc;
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
    std::cout << number_of_strongly_connected_components(adj);
}
