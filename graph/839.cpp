#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>

using namespace std;

bool isSimilar(string str1, string str2){
    if (str1.size() != str2.size()){
        return false;
    }
    vector<int> error;
    for (int i = 0; i < str1.size(); i++){
        if (str1[i] != str2[i]){
            error.push_back(i);
        }
        if (error.size() > 2){
            return false;
        }
    }
    if (error.size() == 1){
        return false;
    }
    if (error.size() == 0){
        return true;
    }
    if (str1[error[0]] == str2[error[1]] && str1[error[1]] == str2[error[0]]){
        return true;
    }else{
        return false;
    }
    
}
void bfs(vector<vector<int>>& graph, int i, vector<bool>& visited){
    queue<int> queue_1;
    queue_1.push(i);
    while(queue_1.size() != 0){
        int front = queue_1.front();

        for (auto neighbor: graph[front]){
            if (!visited[neighbor]){
                queue_1.push(neighbor);
                visited[neighbor] = true;
            }
        }
        queue_1.pop();
    }
}
int numSimilarGroups(vector<string>& strs) {
    vector<vector<int>> graph(strs.size(), vector<int>());
    for (int i = 0; i < strs.size(); i++){
        for (int j = i + 1; j < strs.size(); j++){
            if (isSimilar(strs[i], strs[j])){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    vector<bool> visited(strs.size(), false);
    int res = 0;
    for (int i = 0; i < strs.size(); i++){
        if (!visited[i]){
            bfs(graph, i, visited);
            res++;
        }
    }
    return res;
}
