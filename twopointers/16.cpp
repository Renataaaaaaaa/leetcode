#include <vector>
#include <iostream>

using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int diff_abs = INT32_MAX;
    int res = 0;
    for (int i = 0; i < nums.size(); i++){
        int sub_target = target - nums[i];
        // cout << "sub_target " << sub_target << endl;
        int p = i + 1;
        int q = nums.size() - 1;
        while(q > p){
            if (diff_abs > abs(sub_target - (nums[q] + nums[p]))){
                diff_abs = abs(sub_target - (nums[q] + nums[p]));
                res = nums[i] + nums[p] + nums[q];
            }
            // cout << "diff abs   " << diff_abs << endl;
            if ((nums[p] + nums[q]) == sub_target){
                return target;
            }else if ((nums[p] + nums[q]) > sub_target){
                // q--;
                while(q > p && q-1 >= 0 && nums[q] == nums[q-1]){
                    q--;
                }
                q--;
            }else if ((nums[p] + nums[q]) < sub_target){
                // p++;
                while(q > p && p+1 <= nums.size() && nums[p] == nums[p+1]){
                    p++;
                }
                p++;
            }
            // cout << p << " " << q << endl;
            // exit(0);
        }
        // diff_abs = min(diff_abs, abs(sub_target - (nums[q] + nums[p])));
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        // exit(0);
    }
    return res;      
}
int main(){
    vector<int> data = {-4,-1,1,2};
    // vector<int> data = {-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1};
    cout << threeSumClosest(data, 1) << endl;
}