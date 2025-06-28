#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int res = 0;
int square_num = 0;
vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1},{-1,0}};
void backtrack(vector<vector<int>>& grid, int i, int j, int pass){
    if (grid[i][j] == 2 && (pass - 2) == square_num){
        res += 1;
    }
    int old_value = grid[i][j];
    grid[i][j] = -1; //
    for(auto direction: directions){
        int i_n = i + direction[0];
        int j_n = j + direction[1];
        if (i_n >= 0 && i_n <grid.size() && j_n >= 0 && j_n < grid[0].size() && grid[i_n][j_n] != -1){
            backtrack(grid, i_n, j_n, pass + 1);
        }
    }
    grid[i][j] = old_value; //
    
}
int uniquePathsIII(vector<vector<int>>& grid) {
    int b_i = 0, b_j = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if (grid[i][j] == 0){
                square_num++;
            }
            if (grid[i][j] == 1){
                b_i = i;
                b_j = j;
            }
        }
    }
    backtrack(grid, b_i, b_j, 1);
    return res;
}

int main(){
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << uniquePathsIII(grid) << endl;
}