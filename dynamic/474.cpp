#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int count1 (string& a){
    int res = 0;
    for(auto ch: a){
        if (ch == '1'){
            res++;
        }
    }
    return res;
}
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    // dp[0][0][0] = 1;
    for(int i = 1; i < strs.size() + 1; i++){
        for(int j = 0; j < m + 1; j++){
            for(int k = 0; k < n + 1; k++){
                dp[i][j][k] = dp[i-1][j][k];
                int number_1 = count1(strs[i-1]);
                int number_0 = strs[i-1].size() - number_1;
                if (j-number_0 >= 0 && k-number_1 >= 0){
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-number_0][k-number_1] + 1);
                }
            }
        }
    }
    return dp[strs.size()][m][n];
}

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    // vector<string> strs = {"10", "0", "1"};
    cout << findMaxForm(strs, 5, 3) << endl;
}