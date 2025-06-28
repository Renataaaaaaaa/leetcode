#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    return a.second > b.second; //降序
}
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> data;
    for(int i = 0; i < nums1.size(); i++){
        data.push_back(make_pair(nums1[i], nums2[i]));
    }
    sort(data.begin(), data.end(), compare);
    priority_queue<int, vector<int>, greater<int>> que; //小顶堆
    int multi = 0;
    for(int i = 0; i < k; i++){
        multi += data[i].first;
        que.push(data[i].first);
    }
    int res = multi * data[k-1].second;

    for(int i = k; i < nums1.size(); i++){
        if (data[i].first > que.top()){
            multi = multi - que.top() + data[i].first;
            que.pop();
            que.push(data[i].first);
        }
        res = max(res, data[i].second * multi);
    }
    return res;
}
int main(){
    vector<int> nums1= {1,3,3,2}; // 最大的三个
    vector<int> nums2 = {2,1,3,4}; //min
    cout << maxScore(nums1, nums2, 3) << endl;
}