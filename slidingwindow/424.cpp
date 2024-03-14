#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;



int characterReplacement(string s, int k) {
    vector<int> num(26);
    int n = s.length();
    int maxn = 0;
    int left = 0, right = 0;
    while (right < n) {
        num[s[right] - 'A']++;
        maxn = max(maxn, num[s[right] - 'A']);
        if (right - left + 1 - maxn > k) { //ATTENION: (right - left + 1 - maxn) 被替换过的数量
            num[s[left] - 'A']--;
            left++;
        }
        right++;
    }
    return right - left;
}


int main(){
    string s = "AABABBA";
    cout << characterReplacement(s, 1) << endl;
}