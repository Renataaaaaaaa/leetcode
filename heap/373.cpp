#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;



// class Solution {
// public:
// struct Compare { //ATTENTION
//     bool operator()(const vector<int>& a, const vector<int>& b) const {
//         return accumulate(a.begin(), a.end(), 0) < accumulate(b.begin(), b.end(), 0); //min heap
//     }
// };
// vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//     priority_queue< vector<int>, vector<vector<int>>, Compare> heap;

//     for(int i = 0; i < min(k, int(nums1.size())); i++){
//         heap.push(vector<int> {nums1[i], nums2[0]});
//     }
//     for(int j = 1; j < min(k, int(nums2.size())); j++){
//         for (int i = 0; i < min(k, int(nums1.size())); i++){
//             if (heap.size() < k){
//                 // cout << nums1[i] <<" " << nums2[j] << endl;
//                 heap.push(vector<int>{nums1[i], nums2[j]});
//             }else{
//                 if (nums1[i] + nums2[j] < heap.top()[0] + heap.top()[1]){
//                     heap.pop();
//                     heap.push(vector<int>{nums1[i], nums2[j]});
//                 }else{
//                     break;
//                 }
//             }
//         }
//     }
//     vector <vector<int>> res; 
//     while(heap.size() != 0){
//         res.push_back(heap.top());
//         heap.pop();
//     }
//     return res;
// }
// };

// class Solution {
// public:
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };

    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> ans;   
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < min(k, m); i++) {
        pq.emplace(i, 0);
    }
    while (k-- > 0 && !pq.empty()) {
        pair<int, int> pair = pq.top(); 
        int x = pair.first;
        int y = pair.second;
        pq.pop();
        ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
        if (y + 1 < n) { //为什么只需要增加y就可以了？还是说，会可能移动到的？
            pq.emplace(x, y + 1);
        }
    }

    return ans;
}
// };


int main(){
    vector<int> data_1 = {1,7,11};
    vector<int> data_2 = {2,4,6};
    for (auto list: kSmallestPairs(data_1, data_2, 3)){
        for (auto item: list){
            cout << item << endl;
        }
    }
}