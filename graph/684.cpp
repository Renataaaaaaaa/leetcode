#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>

using namespace std;

bool hasCycle(vector<vector<int>>& graph){
    vector<int> inDegree(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++){
        // if (graph[i].size() > 0){
        inDegree[i] = graph[i].size();
        // }
        // inDegree[graph[i][1]]++;
    }
    queue<int> queue_1;
    for (int i = 0; i < inDegree.size(); i++){
        if (inDegree[i] <= 1){
            queue_1.push(i);
        }
    }
    while(queue_1.size() != 0){
        int front = queue_1.front();
        for (auto neighbor: graph[front]){
            if (inDegree[neighbor] <= 1){
                continue;
            }
            inDegree[neighbor]--;
            if (inDegree[neighbor] <= 1){
                queue_1.push(neighbor);
            }
        }
        queue_1.pop();
    }
    for (int i = 0; i < inDegree.size(); i++){
        if (inDegree[i] > 1){
            return true;
        }
    }
    return false;
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<vector<int>> graph(edges.size()); //TODO
    // vector<int> inDegree;
    for (auto edge: edges){
        graph[edge[0] - 1].push_back(edge[1] - 1);
        graph[edge[1] - 1].push_back(edge[0] - 1);
        // inDegree[]++;
        // inDegree[]++;
        if (hasCycle(graph)){
            return edge;
        }
    }
    return vector<int>();
}
