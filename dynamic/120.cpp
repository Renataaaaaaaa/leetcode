#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp;
    for (int i = 0; i <triangle.size(); i++){
        dp.push_back(vector<int>(triangle[i].size(), 0));
        for(int j = 0; j < triangle[i].size(); j++){
            if (i == 0 && j == 0){
                dp[0][0] = triangle[0][0];
            }else if (j == 0){
                dp[i][j] =  dp[i-1][j] + triangle[i][j];
            }else if (j == triangle[i].size() - 1){
                dp[i][j] =  dp[i-1][j-1] + triangle[i][j];
            }else{
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    return *(min_element(dp[dp.size()-1].begin(), dp[dp.size()-1].end()));
}
