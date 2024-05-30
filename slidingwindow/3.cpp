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
        cur.insert(s[right]);
        while(cur.find(s[left]) != cur.end()){
            cur.erase(s[left]);
            left++;
        }
        cout << left << " " << right << endl;
        res = max(res, right - left);
        right++;
    }
    return res;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s)<<endl;
}