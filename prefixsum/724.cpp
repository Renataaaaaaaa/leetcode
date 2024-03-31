#include <vector>
#include <iostream>
using namespace std;


int pivotIndex(vector<int>& nums) {
    int total_sum = 0;
    for(vector<int>::size_type i = 0; i < nums.size(); i++){
        total_sum += nums[i];
    }
    int sum = 0;
    for(vector<int>::size_type i = 0; i < nums.size(); i++){
        sum += nums[i];
        if (sum - nums[i] == total_sum - sum){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> data = {2,-1,1};
    cout << pivotIndex(data) << endl;
}