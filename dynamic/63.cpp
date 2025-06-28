#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int>> dp (row + 1, vector<int>(col + 1, 0));
    for(int i = 1; i < row + 1; i++){
        for(int j = 1; j < col + 1; j++){
            if (i == 1 && j == 1 && obstacleGrid[0][0] != 1){
                dp[i][j] = 1;
            }
            if (obstacleGrid[i-1][j-1] != 1){
                if (i-2 >= 0 && obstacleGrid[i-2][j-1] != 1){
                    dp[i][j] += dp[i-1][j];
                }
                if (j-2 >= 0 && obstacleGrid[i-1][j-2] != 1){
                    dp[i][j] += dp[i][j-1];
                }
            }
            
        }
    }
    return dp[row][col];
}

int main(){
    vector<vector<int>> obs = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(obs) << endl;
}