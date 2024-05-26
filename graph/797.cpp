#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

void dfs(vector<vector<int>>& graph, int source, int target, vector<int>& path, vector<vector<int>>& res){
    path.push_back(source);
    if (source == target){
        res.push_back(path);
        return;
    }
    for (auto neighbor: graph[source]){
        dfs(graph, neighbor, target, path, res);
        path.erase(path.end() - 1);
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(graph, 0, graph.size() - 1, path, res);
    return res;
}
