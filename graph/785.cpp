#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
using namespace std;

bool paintColor(vector<vector<int>>& graph, int source, vector<int>& color){
    color[source] = 1;
    queue<int> past;
    past.push(source);
    while(past.size()!=0){
        int node = past.front();
        for (auto neighbor: graph[node]){
            if (color[neighbor] == -1){
                color[neighbor] = !color[node];
                past.push(neighbor);
            }else if (color[neighbor] == color[node]){
                return false;
            }
        }
        past.pop();
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++){
        if (color[i] == -1){
            if (!paintColor(graph, i, color)){
                return false;
            }
        }
    }
    return true;
}
