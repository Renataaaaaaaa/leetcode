#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

int minKBitFlips(vector<int>& nums, int k) {
    vector<int> diff(nums.size() + 2, 0);
    int sumDiff = 0;
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
        sumDiff += diff[i+1];
        if ((sumDiff + nums[i]) % 2 == 0){
            if (i + k > nums.size()){
                return -1;
            }
            diff[i + 1]++;
            sumDiff++; //ATTENTION
            diff[i + k - 1 + 1 + 1]--;
            res++;
        }

    }
    return res;
}
int main(){
    vector<int> nums = {0,0,0,1,0,1,1,0};
    cout << minKBitFlips(nums, 3) << endl;
}