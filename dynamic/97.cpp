

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

//f(i, j) s1 0..i, s2 0..j 形成s3 0...i+j
bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()){
        return false;
    }
    vector<vector<bool>> dp (s1.size() + 1, vector<bool>(s2.size() + 1, false));
    for(int i = 0; i< s1.size() + 1; i++){  //ATTENTION: 注意遍历对象是什么
        for(int j = 0; j < s2.size() + 1; j++){
            if (i == 0 && j == 0){
                dp[0][0] = true;
            }else{
                bool res = false;
                if (i != 0 && s3[i + j - 1] == s1[i-1]){
                    res = res | (dp[i-1][j]);
                }
                if (j != 0 && s3[i + j - 1] == s2[j-1]){
                    res = res | (dp[i][j-1]);
                }
                dp[i][j] = res;
            }      

        }
    }
    return dp[s1.size()][s2.size()];
}
