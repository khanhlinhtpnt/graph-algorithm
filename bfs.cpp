/*
 Task. Given an undirected graph with n vertices and m edges and two vertices u
 and v, compute the length of a shortest path between u and v
 (that is, the minimum number of edges in a path from u to v).
 Input Format. A graph is given in the standard format.
 The next line contains two vertices u and v.
 Constraints. 2 ≤ n ≤ 105, 0 ≤ m ≤ 105, u different from v, 1 ≤ u, v ≤ n.
 Output Format. Output the minimum number of edges in a path from u to v,
 or −1 if there is no path.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using std::vector;
using std::queue;
using std::stack;

vector<int> bfs(vector<vector<int>> &adj, int s){
    vector<int> dis(adj.size(),-1);
    // vector<int> prev(adj.size(),-1);
    dis[s] = 0;
    queue<int> visisted;
    visisted.push(s);
    while (!visisted.empty()){
        
        int n = visisted.front();
        visisted.pop();
        for (int i = 0; i < adj[n].size(); i++){
            if (dis[adj[n][i]] == -1){
                visisted.push(adj[n][i]);
                dis[adj[n][i]] = dis[n] + 1;
                // prev[adj[n][i]] = n;
            }
        }
    }
    return dis;
}

int distance(vector<vector<int> > &adj, int s, int t) {
    vector<int> dis = bfs(adj,s);
    return dis[t];
}
                
int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++){
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t) << endl;
}
