#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

double dfs(unordered_map<string, unordered_map<string, double>>& graph, string begin, string end, unordered_set<string> visited){
    double res = 1.0;
    if (begin == end){
        return 1.0;
    }
    visited.insert(begin);
    for (auto & pair: graph[begin]){
        if (visited.find(pair.first) != visited.end()){
            continue;
        }
        res = dfs(graph, pair.first, end, visited);
        if (res > 0){
            return pair.second * res;
        }
    }
    return -1;
}
void buildGraph(vector<vector<string>>& equations, vector<double>& values,  unordered_map<string, unordered_map<string, double>>& graph){
    for (int i = 0; i < equations.size(); i++){
        string start = equations[i][0];
        string end = equations[i][1];
        graph[start][end] = values[i];
        graph[end][start] = 1.0 / values[i];
    }
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> graph;
    buildGraph(equations, values, graph);
    vector<double> res;
    for (auto query: queries){
        unordered_set<string> visited = unordered_set<string>();
        if (graph.find(query[0]) == graph.end() || graph.find(query[1]) == graph.end()){
            res.push_back(-1);
        }else{
            res.push_back(dfs(graph, query[0], query[1], visited));
        }
    }
    return res;
}
