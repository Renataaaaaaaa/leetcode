#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int minPrice = INT32_MAX;
    for(int i = 0; i < prices.size(); i++){
        profit = max(prices[i] - minPrice, profit);
        minPrice = min(prices[i], minPrice);
    }
    return profit;
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
}