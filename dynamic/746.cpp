#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
void minCost(vector<int>& cost, vector<int>& res, int i){
    res[i] = min(res[i-1] + cost[i-1], res[i- 2] + cost[i-2]);
    
}
int minCostClimbingStairs(vector<int>& cost) {
    vector<int> res(cost.size() + 2, 0);
    cost.insert(cost.begin() , 0);
    for(int i = 2; i < res.size(); i++){
        minCost(cost, res, i);
    }
    return res[res.size() - 1];
}
};