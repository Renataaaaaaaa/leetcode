#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
using namespace std;

//20000 $1000

int help(vector<vector<int>>& grid, int i_index, int j_index, vector<vector<int>>& visited){ //bfs
    queue<pair<int, int>> past;
    past.push(make_pair(i_index, j_index));
    visited[i_index][j_index] = true;
    int num = 0;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(past.size()!= 0){
        //上下左右
        for(auto direction: directions){
            int i_n = past.front().first + direction[0];
            int j_n = past.front().second + direction[1];
            if (i_n >= 0 && i_n < grid.size() && j_n >= 0 && j_n < grid[0].size() && !visited[i_n][j_n] && grid[i_n][j_n]){
                visited[i_n][j_n] = true;
                past.push(make_pair(i_n, j_n));
            }
        }
        past.pop();
        num++;
    }
    return num;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));  
    int maxArea = 0;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            if (!visited[i][j] && grid[i][j] == 1){
                maxArea = max(help(grid, i, j, visited), maxArea);
                cout << i << " " <<j << " " << maxArea << endl;
            }
        }
    }
    return maxArea;
}

int main(){
    vector<vector<int>> data = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland(data) << endl;
}