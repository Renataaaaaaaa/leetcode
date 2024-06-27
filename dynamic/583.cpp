#include <vector>
#include <iostream>
using namespace std;


int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
    for(int j = 0; j < word2.size() + 1; j++){
        dp[0][j] = j;
    }
    for(int i = 0; i < word1.size() + 1; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i < word1.size()+1; i++){
        for(int j = 1; j < word2.size()+1; j++){
            if (word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + 1;
            }
        }
    }
    return dp[word1.size()][word2.size()];
}
int main(){
    string word1 = "a";
    string word2 = "b";
    cout << minDistance(word1, word2) << endl;
}