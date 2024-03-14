#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <numeric>
using namespace std;


int lengthOfLongestSubstring(string s) {
    if (s.size() == 0){
        return 0;
    }
    int left = 0;
    int right = 0;
    unordered_set<int> cur;
    int res = 0, res_max = 1;
    while(right < s.size()){
        while(cur.find(s[right]) != cur.end()){
            cur.erase(s[left]);
            left++;
        }
        res = right - left + 1;
        res_max = max(res, res_max);
        cur.insert(s[right]);
        right++;
    }
    return max(res_max, right - left);
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s)<<endl;
}