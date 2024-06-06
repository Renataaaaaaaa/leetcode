#include <vector>
#include <iostream>
#include <queue>
using namespace std;


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> inDegree(numCourses, 0);
    for (auto pre: prerequisites){
        graph[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    queue<int> queue_1;
    vector<int> res;
    for (int i = 0; i < inDegree.size(); i++){
        if (inDegree[i] == 0){
            queue_1.push(i);
            res.push_back(i);
        }
    }
    while(queue_1.size() != 0){
        int source = queue_1.front();
        for (auto neighbor: graph[source]){
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0){
                queue_1.push(neighbor);
                res.push_back(neighbor);
            }
        }
        queue_1.pop();
    }
    bool cycle = false;
    for (auto item: inDegree){
        if (item != 0){
            return vector<int>();
        }
    }
    return res;
}
int main(){
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    for (auto item: findOrder(4, prerequisites)){
        cout << item << endl;
    }
}