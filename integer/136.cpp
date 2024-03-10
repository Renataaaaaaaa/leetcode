#include <vector>
#include <iostream>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto item: nums){
        res = res ^ item;
    }
    return res;
}