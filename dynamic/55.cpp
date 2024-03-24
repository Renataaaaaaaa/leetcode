#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= rightmost) {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= n - 1) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> data = {2,3,1,1,4};

}