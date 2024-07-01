#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;


int calculateMinimumHP(vector<vector<int>>& dungeon) {
    vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 1));
    //走到i,j，平安到达
    int row = dungeon.size();
    int col = dungeon[0].size();
    dp[row-1][col-1] = dungeon[row-1][col-1] > 0 ? 1 : (-dungeon[row-1][col-1] + 1);
    for(int i = row - 2; i >= 0 ; i--){
        dp[i][col-1] = max(dp[i+1][col-1] - dungeon[i][col-1], dp[i][col-1]);
    }
    for(int j = col - 2; j >= 0; j--){
        dp[row-1][j] = max(dp[row-1][j-1] - dungeon[row-1][j], dp[row-1][j]);
    }
    for(int i = row - 2; i >= 0; i--){
        for(int j = col - 2; j >= 0 ; j--){
            int cur = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1);
            dp[i][j] = cur;
        }
    }
    cout << dp[0][0] << endl;
    return dp[0][0];
}

int main(){
    vector<vector<int>> dungeion = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout << calculateMinimumHP(dungeion) << endl;
}