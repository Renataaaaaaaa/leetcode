
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

void dfs(vector<vector<int>>& graph, int source, int target, vector<int>& path, vector<vector<int>>& res){
    path.push_back(source);
    if (source == target){
        res.push_back(path);
        return;
    }
    for (auto neighbor: graph[source]){
        dfs(graph, neighbor, target, path, res);
        path.pop_back();
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(graph, 0, graph.size() - 1, path, res);
    return res;
}