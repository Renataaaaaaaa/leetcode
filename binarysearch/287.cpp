#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int num = nums.size() - 1;
    int lo = 1;
    int hi = num;
    int mid, less_num, larger_num;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        less_num = larger_num = 0;
        for (auto num: nums){
            if (num < mid){
                less_num++;
            }
            if (num > mid){
                larger_num++;
            }
        }
        if (less_num > mid - 1){
            hi = mid - 1;
        }else if (larger_num > num - mid){
            lo = mid + 1;
        }else{
            return mid;
        }
    }
    return lo;
}