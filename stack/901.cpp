#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<int> stk;
    vector<int> prices;
    StockSpanner() {
    }
    
    int next(int price) {
        if (stk.empty() || price < prices[stk.top()]){
            stk.push(prices.size());
            prices.push_back(price);
            return 1;
        }
        while(!stk.empty() && (price >= prices[stk.top()])){
            stk.pop();
        }
        int res = prices.size() - (stk.empty() ? (-1) : stk.top());
        stk.push(prices.size());
        prices.push_back(price);
        return res;
    }
};
int main(){
    StockSpanner* obj = new StockSpanner();
    cout << obj->next(1) << endl;
    cout << obj->next(2) << endl;
    cout << obj->next(3) << endl;
    // cout << obj->next(70) << endl;
    // cout << obj->next(60) << endl;
    // cout << obj->next(75) << endl;
    // cout << obj->next(85) << endl;
}