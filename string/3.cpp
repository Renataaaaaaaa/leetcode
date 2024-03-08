#include <vector>
#include <iostream>
using namespace std;

bool isRepeated(vector<int> & nums){
    for (auto num: nums){
        if (num > 1){
            return true;
        }
    }
    return false;
}
int lengthOfLongestSubstring(string s) {
    vector<int> nums(128, 0);
    int maxLength = 0, left = 0;
    for(int right = 0; right < s.size(); right++){
        (nums[s[right]])++;
        while (left < right && isRepeated(nums)){
            (nums[s[left]])--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
    
}