#include <vector>
#include <iostream>
using namespace std;

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