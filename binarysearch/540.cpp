#include <vector>
#include <iostream>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1){
        return nums[0];
    }
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;
    while(hi > lo){ //keep singular
        mid = (lo + hi ) / 2;
        if ( mid % 2 == 0){ 
            if (nums[mid] == nums[mid + 1]){ //正常情况下，前边没有被插入的情况下，不等于的时候mid有可能是答案，所以要hi = mid
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }else{ 
            if (nums[mid] == nums[mid - 1]){ //正常情况下，前边没有被插入的情况下
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
    }
    return nums[lo];
}

int main(){
    vector<int> data = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(data) << endl;
}