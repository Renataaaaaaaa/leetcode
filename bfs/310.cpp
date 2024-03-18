#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int getHeight(vector<vector<int>> &graph, int index){
    queue<int> queue_1;
    queue_1.push(index);
    int front = 0;
    int height = 0;
    int level_size = 0;
    vector<bool> visited (graph.size(), false);
    visited[index] = true;
    while(!queue_1.empty()){
        level_size = queue_1.size();
        for (int i = 0; i < level_size; i++){
            front = queue_1.front();
            for (auto neighbor: graph[front]){
                if (!visited[neighbor]){
                    queue_1.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            queue_1.pop();
        }
        height++;
    }
    cout << index << " " << height << endl;
    return height;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n, vector<int>());

    for (auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    int min_height = INT32_MAX;
    int height = 0;
    vector<int> res;

    for (int i = 0; i < n; i++){
        height = getHeight(graph, i);
        if (height == min_height){
            res.push_back(i);
        }else if (height < min_height){
            min_height = height;
            res = {i};
        }
    }
    return res;
}

int main(){
    vector<vector<int>> data = {};
    for (auto item: findMinHeightTrees(1, data)){
        cout << item << endl;
    }
}