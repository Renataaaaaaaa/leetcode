#include <vector>
#include <iostream>
using namespace std;

int missingNumber(vector<int>& nums) {
    int num_size = nums.size();
    for(int i = 0; i <= num_size; i++){
        nums.push_back(i);
    }
    int res = 0;
    for (auto num: nums){
        res ^= num;
    }
    return res;
}

int main(){
    vector<int> data = {9,6,4,2,3,5,7,0,1};
    cout << missingNumber(data) << endl;
}