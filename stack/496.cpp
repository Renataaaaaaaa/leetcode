
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
#include <cstdlib>
#include <list>
#include <stack>

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nums2_nextgreater;
    stack<int> stk;
    stk.push(nums2[0]);
    for(int i = 1; i < nums2.size(); i++){
        while(!stk.empty() && stk.top() < nums2[i]){ //右边第一个比他大的
            nums2_nextgreater[stk.top()] = nums2[i];
            stk.pop();
        }
        stk.push(nums2[i]);
    }
    vector<int> res;
    for(auto item: nums1){
        if(nums2_nextgreater.find(item) != nums2_nextgreater.end()){
            res.push_back(nums2_nextgreater[item]);
        }else{
            res.push_back(-1);
        }
        
    }
    return res;
}

int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    for(auto item: nextGreaterElement(nums1, nums2)){
        cout << item << endl;
    }
}