#include <vector>
#include <iostream>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto num: nums){
        res ^= num;
    }
    cout << res << endl;
    int i = 0;
    while((res & 1) != 1){
        res = res >> 1;
        i++;
    }
    cout << "i " << i << endl;
    int res_1 = 0, res_2 = 0;

    for (auto num: nums){
        if ((num >> i) & 1){
            res_1 ^= num;
        }else{
            res_2 ^= num;
        }
    }
    return {res_1, res_2};
}

int main(){
    // vector<int> data = {1,2,1,3,2,5};
    vector<int> data = {-1,0};
    for (auto item: singleNumber(data)){
        cout << item << endl;
    }
}