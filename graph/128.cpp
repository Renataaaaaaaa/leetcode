#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

int bfs(int num, unordered_set<int>& nums_set){
    queue<int> queue_1;
    queue_1.push(num);

    nums_set.erase(num);
    int res = 1;
    while(queue_1.size() != 0){
        int front = queue_1.front();
        cout << front << endl;
        if (nums_set.find(front + 1) != nums_set.end()){
            nums_set.erase(front + 1);
            queue_1.push(front + 1);
            res++;
        }
        if (nums_set.find(front - 1) != nums_set.end() ){
            nums_set.erase(front - 1);
            queue_1.push(front - 1);
            res++;
        }
        queue_1.pop();
    }
    return  res;
}

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> nums_set;
    for (auto num: nums){
        nums_set.insert(num);
    }
    int res_max = INT32_MIN;
    // vector<bool> visited(nums.size(), false);
    for (int i = 0; i < nums.size(); i++){
        if (nums_set.find(nums[i]) != nums_set.end()){
            res_max = max(res_max, bfs(nums[i], nums_set));
        }
    }
    if (res_max == INT32_MIN){
        return 0;
    }
    return res_max;
}
