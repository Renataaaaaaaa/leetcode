#include "utils.cpp"
#include <queue>

int findLongestNode(int u, vector<int> & parent, vector<vector<int>>& adj) {
    int n = adj.size();
    queue<int> qu;
    vector<bool> visit(n);
    qu.emplace(u);
    visit[u] = true;
    int node = -1;

    while (!qu.empty()) {
        int curr = qu.front();
        qu.pop();
        node = curr;
        for (auto & v : adj[curr]) {
            if (!visit[v]) {
                visit[v] = true;
                parent[v] = curr;
                qu.emplace(v);
            }
        }
    }
    return node;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
        return {0};
    }
    vector<vector<int>> adj(n);
    for (auto & edge : edges) {
        adj[edge[0]].emplace_back(edge[1]);
        adj[edge[1]].emplace_back(edge[0]);
    }
    
    vector<int> parent(n, -1);
    int x = findLongestNode(0, parent, adj);
    int y = findLongestNode(x, parent, adj);
    vector<int> path;
    parent[x] = -1;
    while (y != -1) {
        path.emplace_back(y);
        y = parent[y];
    }
    int m = path.size();
    if (m % 2 == 0) {
        return {path[m / 2 - 1], path[m / 2]};
    } else {
        return {path[m / 2]};
    }
}


int main(){
    vector<vector<int>> data = {{1,0}, {1,2}, {1,3}};
    for(auto item: findMinHeightTrees(4, data)){
        cout << item << endl;
    }
}