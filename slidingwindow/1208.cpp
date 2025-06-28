#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {

    int left = 0, right = 0;
    int cost = 0;
    int res = 0;
    while(right < s.size()){
        cost += abs(t[right] - s[right]);
        while(cost > maxCost){
            cost -= abs(t[left] - s[left]);
            left++;
        }
        res = max(res, right - left + 1);
        right++;
    }
    return res;
}

int main(){
    string s = "abcd";
    string t = "cdef";
    cout << equalSubstring(s, t, 3) << endl;
}