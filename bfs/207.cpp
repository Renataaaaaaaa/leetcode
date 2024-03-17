#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDegrees(numCourses, 0);

    vector<vector<int>> graph(numCourses, vector<int>());
    for (auto item: prerequisites){
        graph[item[1]].push_back(item[0]);
        inDegrees[item[0]]++;
    }
    queue<int> queue_1;
    for (int i = 0; i < inDegrees.size(); i++){
        if (inDegrees[i] == 0){
            queue_1.push(i);
        }
    }
    // queue_1.push(0);

    while(!queue_1.empty()){ //degree is 0
        int front = queue_1.front();
        for (auto neighbor: graph[front]){
            inDegrees[neighbor]--;
            if (inDegrees[neighbor] == 0){
                queue_1.push(neighbor);
            }
        }
        queue_1.pop();
    }

    for (auto item: inDegrees){
        if (item != 0){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> data = {{1,0}};
    cout << canFinish(2, data) << endl;
}