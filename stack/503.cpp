
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
#include <cstdlib>
#include <list>
#include <stack>

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> stk; //存索引
    stk.push(0);
    int n = nums.size();
    for(int i = 1; i < nums.size() * 2; i++){
        while(!stk.empty() && nums[i % n] > nums[stk.top() % n]){
            res[stk.top()] = nums[i % n];
            stk.pop();
        }
        stk.push(i % n);
    }
    return res;
}

int main(){
    vector<int> nums = {1,2,1}; //4 2 4 -1 4
    for(auto item: nextGreaterElements(nums)){
        cout << item << endl;
    }
}