#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;



class Solution {
public:
struct Compare { //ATTENTION
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return accumulate(a.begin(), a.end(), 0) < accumulate(b.begin(), b.end(), 0); //min heap
    }
};
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue< vector<int>, vector<vector<int>>, Compare> heap;

    for(int i = 0; i < min(k, int(nums1.size())); i++){
        heap.push(vector<int> {nums1[i], nums2[0]});
    }
    for(int j = 1; j < min(k, int(nums2.size())); j++){
        for (int i = 0; i < min(k, int(nums1.size())); i ++){
            if (heap.size() < k){
                // cout << nums1[i] <<" " << nums2[j] << endl;
                heap.push(vector<int>{nums1[i], nums2[j]});
            }else{
                if (nums1[i] + nums2[j] < heap.top()[0] + heap.top()[1]){
                    heap.pop();
                    heap.push(vector<int>{nums1[i], nums2[j]});
                }else{
                    break;
                }
            }
        }
    }
    vector <vector<int>> res; 
    while(heap.size() != 0){
        res.push_back(heap.top());
        heap.pop();
    }
    return res;
}
};