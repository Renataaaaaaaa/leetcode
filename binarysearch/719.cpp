#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;




int smallestDistancePairOver(vector<int>& nums, int k) {
    auto cmp = [&nums](const pair<int, int> & a, const pair<int, int> & b) {
        return abs(nums[a.first] - nums[a.second]) < abs(nums[b.first] - nums[b.second]);
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); //maxHeap
    // for (int i = 1; i < nums.size(); i++){
    //     pq.emplace(0, i);
    // }
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            if (pq.size() == k){
                pair<int, int> top_one = pq.top();
                if (abs(nums[i] - nums[j]) < abs(nums[top_one.first] - nums[top_one.second])){
                    pq.pop();
                    pq.emplace(i, j);
                }
            }else{
                pq.emplace(i, j);
            }
        }
    }
    return abs(nums[pq.top().first] - nums[pq.top().second]);
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = 0, right = nums.back() - nums.front();
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        // for (int j = 0; j < n; j++) {
        //     int i = lower_bound(nums.begin(), nums.begin() + j, nums[j] - mid) - nums.begin();
        //     cnt += j - i;
        // }
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (nums[j] - nums[i] <= mid){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        if (cnt >= k) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> data = {1,6,1};
    cout << smallestDistancePair(data, 3) << endl;
}