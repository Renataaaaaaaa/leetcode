#include <vector>
#include <iostream>

using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int diff_abs = INT32_MAX;
    int res = 0;
    for (int i = 0; i < nums.size(); i++){
        int sub_target = target - nums[i];
        int p = i + 1;
        int q = nums.size() - 1;
        while(q > p){
            if (diff_abs > abs(sub_target - (nums[q] + nums[p]))){
                diff_abs = abs(sub_target - (nums[q] + nums[p]));
                res = nums[i] + nums[p] + nums[q];
            }
            if ((nums[p] + nums[q]) == sub_target){
                return target;
            }else if ((nums[p] + nums[q]) > sub_target){
                while(q > p && nums[q] == nums[q-1]){
                    q--;
                }
                q--;
            }else if ((nums[p] + nums[q]) < sub_target){
                while(q > p && nums[p] == nums[p+1]){
                    p++;
                }
                p++;
            }
        }
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
    }
    return res;      
}
int main(){
    vector<int> data = {-4,-1,1,2};
    // vector<int> data = {-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1};
    cout << threeSumClosest(data, 1) << endl;
}