#include "utils.cpp"
#include <stack>


void dfs(vector<vector<int>>& graph, int i, vector<bool>& visited){
    visited[i] = true;
    for(auto n: graph[i]){
        if (!visited[n]){
            dfs(graph, n, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size(), false);
    dfs(rooms, 0, visited);
    for(auto item: visited){
        if (!item){
            return false;
        }
    }
    return true;
}

int main(){
    // vector<vector<int>> rooms = {{1},{2},{3},{}};
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    cout << canVisitAllRooms(rooms) << endl;
}