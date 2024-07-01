#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int, vector<pair<int, int>>> map;
    vector<vector<int>> dp(n, vector<int>(k + 2, INT32_MAX));

    for(auto flight: flights){
        map[flight[1]].push_back(make_pair(flight[0], flight[2]));
    }
    dp[src][0] = 0;
    for(int i = 1; i < k + 2; i++){
        for(int j = 0; j < dp.size(); j++){
            dp[j][i] = dp[j][i-1];
            for(auto f: map[j]){ //上游
                if (dp[f.first][i-1] != INT32_MAX){
                    dp[j][i] = min((dp[f.first][i-1] + f.second), dp[j][i]);
                }
            }
        }
    }
    if (dp[dst][k + 1] == INT32_MAX){
        return -1;
    }
    return dp[dst][k + 1];
}
int main(){
    // vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    // cout << findCheapestPrice(4, flights, 0, 3, 1) << endl;

    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << findCheapestPrice(3, flights, 0, 2, 0) << endl;
}