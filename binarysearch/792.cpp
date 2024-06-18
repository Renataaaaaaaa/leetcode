#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int left_bound(vector<int> nums, int target){ //第一个比target大的数
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while( hi >= lo){
        mid = lo + (hi - lo) / 2;
        if (target == nums[mid]){
            lo = mid + 1;
        }else if (nums[mid] > target){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return lo;
}

bool isSubsequence(string s, string t, vector<vector<int>> chars){
    int left = -1;
    for(int i = 0; i < s.size(); i++){
        vector<int> nums = chars[s[i] - '0'];
        int index = left_bound(nums, left);
        // cout << s[i] << " " << index << " " << nums[index] << endl;
        if (index == nums.size()){
            return false;
        }else{
            left = nums[index];
        }
        
    }
    return true;
}
int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> chars(256);
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        cout << s[i] - '0' << endl;
        chars[s[i] - '0'].push_back(i);
    }
    for(auto word: words){
        if (isSubsequence(word, s, chars)){
            res++;
        }
    }
    return res;
}

int main(){
    // vector<string> words = {"abc"};
    // string s = "cacbhbc";

    // vector<string> words = {"a","bb","acd","ace"};
    // string s = "abcde";
    vector<string> words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    string s = "dsahjpjauf";
    cout << numMatchingSubseq(s, words) << endl;;
}