#include <vector>
#include <iostream>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1){
        return nums[0];
    }
    int lo = 1;
    int hi = nums.size() - 2;
    int mid = 0;
    int res = 0;
    while(hi >= lo){ //keep singular
        mid = (lo + hi ) / 2;
        cout << "mid " << mid << endl;
        if ((nums[mid] != nums[mid + 1]) &&  (nums[mid] != nums[mid - 1])){
            return nums[mid];
        }
        if ( mid % 2 == 0){
            if (nums[mid] == nums[mid + 1]){
                cout << "19" << endl;
                lo = mid;
            }else{
                hi = mid;
            }
        }else{
            if (nums[mid] == nums[mid + 1]){
                hi = mid - 1;
                res = hi;
            }else{
                cout << "31" << endl;
                lo = mid + 1;
                res = lo;
            }
        }

    }
    return nums[res];
}