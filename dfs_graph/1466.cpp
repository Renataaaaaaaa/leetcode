#include "utils.cpp"
#include <stack>


int res = 0;

void dfs(vector<vector<pair<int, int>>>& graph, int i, vector<bool>& visited){
    visited[i] = true;
    for(auto edge: graph[i]){
        if (!visited[edge.first]){
            res += edge.second;
            dfs(graph, edge.first, visited);
        }
    }
}

vector<vector<pair<int, int>>> buildGraph(vector<vector<int>>& roads){
    vector<vector<pair<int, int>>> graph(roads.size() + 1, {});
    for(auto road: roads){
        graph[road[0]].push_back({road[1], 1});
        graph[road[1]].push_back({road[0], 0});
    }
    return graph;
}

int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, int>>> graph = buildGraph(connections);
    vector<bool> visited(connections.size() + 1);
    dfs(graph, 0, visited);
    return res;
}
int main(){
    vector<vector<int>> roads = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    
    cout << minReorder(6, roads)<< endl;
}