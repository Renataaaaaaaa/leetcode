#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


class Solution {
public:
struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second > b.second; //min heap
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    vector<int> res;
    for (auto num: nums){
        map[num] += 1;
    }
    std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, Compare> minHeap;
    for (const auto & item: map){
        if (minHeap.size() < k){
            minHeap.push(make_pair(item.first, item.second));
        }else{
            if (item.second < minHeap.top().second){
                
            }else{
                minHeap.pop();
                minHeap.push(make_pair(item.first, item.second));
            }
        }
    }
    while(minHeap.size() != 0){
        res.push_back(minHeap.top().first);
        minHeap.pop();
    }
    return res;

}
};