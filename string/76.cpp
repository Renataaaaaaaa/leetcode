#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool allZero(unordered_map<char, int> nums){
    for (auto pair: nums){
        if (pair.second > 0){
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    if (s.size() < t.size()){
        return "";
    }
    // vector<int> t_nums(256, 0);
    unordered_map<char, int> t_nums;

    for (auto c: t){
        t_nums[c]++;
    }
    int left = 0;
    int i = 0, j = 0, length = INT32_MAX;
    for (int right = 0; right < s.size(); right++){
        cout << right << endl;
        if (t_nums.find(s[right]) != t_nums.end()){
            t_nums[s[right]]--;
        }
        while (allZero(t_nums) && left <= right){
        cout << left << endl;

            if (t_nums.find(s[left]) != t_nums.end()) {
                t_nums[s[left]]++;
            }
            if ((right - left + 1 ) < length){
                i = left;
                j = right;
                length = right - left + 1;
            }
            left++;

        }
    }
    if (length != INT32_MAX){
        return s.substr(i, length);
    }else{
        return "";
    }
}