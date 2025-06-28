#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int maximalSquare(vector<vector<char>>& matrix) {
    int res = 0;
    vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
    for(int i = 1; i < matrix.size() + 1; i++){
        for(int j = 1; j < matrix[0].size() + 1; j++){
            if (matrix[i-1][j-1] == '1'){
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    return res * res;
}

int main(){
    vector<vector<char>> matirx = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maximalSquare(matirx) << endl;
}