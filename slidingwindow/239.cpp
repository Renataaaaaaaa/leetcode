#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second < b.second; //min heap
    }
};
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>, std::vector<pair<int, int>>, Compare> queue;
    for(int i = 0; i < k; i++){
        queue.emplace(i, nums[i]);
    }
    vector<int> res;
    std::cout << queue.top().second << std::endl;
    res.push_back(queue.top().second);
    for(int i = k; i < nums.size(); i++){
        queue.emplace(i, nums[i]);
        while (queue.top().first <= i - k){
            queue.pop();
        }
        res.push_back(queue.top().second);
    }
    return res;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    for(auto res: maxSlidingWindow(nums, 3)){
        cout << res << endl;
    }
}