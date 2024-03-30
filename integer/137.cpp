#include <vector>
#include <iostream>
using namespace std;

//判断某一位是不是1: res_bits[i] += (num >> (31 - i)) & 1

int singleNumber(vector<int>& nums) {
    int res_bits [32] = {0};
    for(auto num: nums){
        for (int i = 0; i < 32; i++){
            res_bits[i] += (num >> (31 - i)) & 1;
        }
    }
    int res = 0;
    for (int i = 0; i < 32; i++){
        res += ((res_bits[i] % 3) << (31 - i));
    }
    return res;
}
int main(){
    vector<int> data = {2,2,3,2};
    cout << singleNumber(data) << endl;
}