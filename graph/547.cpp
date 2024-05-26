#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
    queue<int> queue_1;
    queue_1.push(i);
    visited[i] = true;
    while(queue_1.size() != 0){
        int front = queue_1.front();
        for (int j = 0; j < isConnected[front].size(); j++){
            if (!visited[j] && j != front && isConnected[front][j] == 1){
                queue_1.push(j);
                visited[j] = true;
            }
        }
        cout << queue_1.size() << endl;
        queue_1.pop();
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    vector<vector<int>> graph(isConnected.size(), vector<int>());
    // for (auto person: isConnected){

    // }
    vector<bool> visited(isConnected.size(), false);
    int circle_num = 0;
    for (int i = 0; i < isConnected.size(); i++){
        if (!visited[i]){
            bfs(isConnected, visited, i);
            circle_num++;
        }
    }
    return circle_num;
}
