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
    unordered_set<char> cur;
    // cur.insert(s[0]);
    int res = 0;
    while(right < s.size()){
        while(cur.find(s[right]) != cur.end()){
            cur.erase(s[left]);
            left++;
        }
        cur.insert(s[right]);
        cout << left << " " << right << endl;
        res = max(res, right - left + 1);
        right++;
    }
    return res;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s)<<endl;
}