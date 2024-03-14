#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;


int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int num = 0; 
    int max_num = 0;
    for (int right = 0; right < nums.size(); right++){
        if (nums[right] == 1){
            num++;
        }
        if (right - left + 1 - num > k){
            if (nums[left] == 1){
                num--;
            }
            left++;
        }
        cout << "right " << right << " " << num << endl;
        max_num = max(right - left + 1, max_num);
    }
    return max_num;
}

int main(){
    vector<int> data = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << longestOnes(data, 3) << endl;;
}