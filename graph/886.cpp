#include <vector>
#include <iostream>
#include <queue>
using namespace std;


//双向边
bool paintColor(vector<vector<int>>& graph, vector<int>& color,int i){
    color[i] = 1;
    queue<int> queue;
    queue.push(i);
    while(!queue.empty()){
        int node = queue.front();
        int topcolor = color[node];
        for(auto neighbor: graph[node]){
            if (color[neighbor] == -1){
                color[neighbor] = !topcolor;
                queue.push(neighbor);
            }
            else{
                if (color[neighbor] == topcolor){
                    return false;
                }
            }
            
        }
        queue.pop();
    }
    return true;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n, vector<int>());
    vector<int> color(n, -1);
    for(auto item: dislikes){
        graph[item[0]-1].push_back(item[1]-1);
        graph[item[1]-1].push_back(item[0]-1);
    }
    for(int i = 0; i < n; i++){
        if (color[i]==-1){
            bool res = paintColor(graph, color, i);
            if (!res){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> dislikes= {{1,2},{2,1}};
    cout << possibleBipartition(2, dislikes) << endl;
}