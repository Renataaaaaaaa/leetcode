#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
void permuteHelp(vector<int>& nums, int left, vector<bool>& picked, string& res){
    if (nums.size() == res.size()){
        return;
    }
    int permuteNum = factorial(nums.size() - res.size() - 1);
    int i;
    for (i = 0; i < nums.size(); i++){
        if (picked[i]){
            continue;
        }
        if (left > permuteNum){
            left -= permuteNum;
        }else{
            break;
        }
    }

    picked[i] = true;
    res += std::to_string(nums[i]);
    permuteHelp(nums, left, picked, res);

}


string getPermutation(int n, int k) {
    vector<int> nums;
    for(int i = 1; i <= n; i++){
        nums.push_back(i);
    }
    vector<bool> used(n, false);
    string res = "";
    permuteHelp(nums, k, used, res);
    return res;
}
int main(){
    cout << getPermutation(4, 10) << endl;
}