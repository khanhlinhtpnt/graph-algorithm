/*
 An undirected graph is called bipartite if its vertices can be split into two parts
 such that each edge of the
 graph joins to vertices from different parts.
 Bipartite graphs arise naturally in applications where a graph is used to model
 connections between objects of two different types (say, boys and girls;
 or students and dormitories).
 An alternative definition is the following: a graph is bipartite if its vertices
 can be colored with two colors (say, black and white) such that the endpoints of
 each edge have different colors.
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::vector;
using std::queue;

int bfs(vector<vector<int>> &adj, int s){
    vector<int> dis(adj.size(),-1);
    vector<int> color(adj.size());
    dis[s] = 0;
    color[s] = 0;
    queue<int> visisted;
    visisted.push(s);
    while (!visisted.empty()){
        int n = visisted.front();
        visisted.pop();
        for (int i = 0; i < adj[n].size(); i++){
            if (dis[adj[n][i]] == -1){
                visisted.push(adj[n][i]);
                dis[adj[n][i]] = dis[n] + 1;
                switch (color[n]){
                    case 0:
                        color[adj[n][i]] = 1;
                        break;
                    case 1:
                        color[adj[n][i]] = 0;
                        break;
                }
            }
            else if (color[adj[n][i]] == color[n]){
                return 0;
            }
        }
    }
    return 1;
}

int bipartite(vector<vector<int> > &adj) {
    int maxSize = 0;
    for (int i = 0; i < adj.size(); i++){
        if (adj[i].size() > adj[maxSize].size())
            maxSize = i;
    }
    return bfs(adj,maxSize);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << bipartite(adj) << endl;
}
