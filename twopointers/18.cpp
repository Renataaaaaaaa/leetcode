#include <vector>
#include <iostream>

using namespace std;

int skipRight(vector<int>& nums, int i){
    while(i + 1 < nums.size() && nums[i+1] == nums[i]){
        i++;
    }
    return i;
}
int skipLeft(vector<int>& nums, int i){
    while(i - 1 > 0 && nums[i-1] == nums[i]){
        i--;
    }
    return i;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i < nums.size(); i++){

        for(int j = i + 1; j < nums.size(); j++){
            long local_target = long(target - nums[i]) - nums[j];
            int p = j + 1;
            int q = nums.size() - 1;
            while(q > p){
                if (nums[p] + nums[q] == local_target){
                    res.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p = skipRight(nums, p);
                    p++;
                    q = skipLeft(nums, q);
                    q--;
                }else if (nums[p] + nums[q] > local_target){
                    q = skipLeft(nums, q);
                    q--;
                }else{
                    p = skipRight(nums, p);
                    p++;
                }
            }
            j = skipRight(nums, j);
        }
        i = skipRight(nums, i);
    }
    return res;
}

int main(){
    vector<int> nums = {-2,-1,-1,1,1,2,2};
    // vector<int> nums = {2,2,2,2,2};
    for(auto vec: fourSum(nums, 0)){
        for(auto item: vec){
            cout << item << " ";
        }
        cout << endl;;
    }
}