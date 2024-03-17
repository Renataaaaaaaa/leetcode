#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> directions = {{0,1}, {0,-1}, {-1, 0}, {1, 0}};
void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
    queue<pair<int, int>> queue_1;
    queue_1.push({i, j}); 
    // int i = index / grid[0].size();
    // int j = index - i * grid[0].size();
    int i_n = 0, j_n = 0, index_n = 0;
    // int i = index / grid[0].size();
    // int j = index - i * grid[0].size();
    visited[i][j] = true;
    while(!queue_1.empty()){
        i = queue_1.front().first;
        j = queue_1.front().second;
        for (auto direction: directions){
            i_n = i + direction[0];
            j_n = j + direction[1];
            index_n = i_n * grid[0].size() + j_n;
            if (i_n >= 0 && j_n >= 0 && i_n < grid.size() && j_n < grid[0].size() && grid[i_n][j_n] == '1' && !visited[i_n][j_n]){
                queue_1.push({i_n, j_n});
                visited[i_n][j_n] = true;
            }
        }
        queue_1.pop();
    }

}

int numIslands(vector<vector<char>>& grid) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int res = 0;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            if (grid[i][j] == '1' && !visited[i][j]){
                bfs(grid, i, j, visited);
                res++;
            }
        }
    }
    return res;
}

int main(){
    vector<vector<char>> data = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
        };
    cout << numIslands(data) << endl;
}