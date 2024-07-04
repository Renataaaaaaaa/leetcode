#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int abss(int i, int j, int size){
    if (abs(j - i) <= size / 2){
        return abs(j - i);
    }else{
        return size - (abs(j - i));
    }
}

int findRotateSteps(string ring, string key) {
    unordered_map<char, vector<int>> map;
    for(int i = 0; i < ring.size(); i++){
        map[ring[i]].push_back(i);
    }
    vector<vector<int>> dp(ring.size(), vector<int>(key.size(), 1000));
    

    for(int i = 0; i < ring.size(); i++){
        if (ring[i] == key[key.size() - 1]){
            dp[i][key.size() - 1] = 1;
        }else{
            for(auto j: map[key[key.size() - 1]]){
                dp[i][key.size() - 1] = min(dp[i][key.size() - 1], abss(i, j, ring.size()) + 1);  
            }
        }
    }
    for(int j = key.size() - 2; j >= 0; j--){
        for(int i = 0; i < ring.size(); i++){
            for(auto k: map[key[j]]){
                dp[i][j] = min(dp[i][j], dp[k][j+1] + (abss(k, i, ring.size())) + 1);
            }
        }
    }
    return dp[0][0];
}
int main(){
    string ring = "abcde";
    string key = "ade";
    cout << findRotateSteps(ring, key) << endl;
}