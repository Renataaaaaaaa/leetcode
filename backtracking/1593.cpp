#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
#include <unordered_set>
using namespace std;

void backtrack(string &s, int index, int split, int & splitMax, unordered_set<string> &us) {
    if (index == s.size()) {
        splitMax = max(splitMax, split);
        return;
    }
    for (int i = index; i < s.size(); i++) {
        string substr = s.substr(index, i - index + 1);
        if (us.find(substr) == us.end()) {
            us.insert(substr);
            backtrack(s, i + 1, split + 1, splitMax, us);
            us.erase(substr);
        }
    }
    
}

int maxUniqueSplit(string s) {
    int maxSplit = 1;
    unordered_set<string> us;
    backtrack(s, 0, 0, maxSplit, us);
    return maxSplit;
}
int main(){
    string s = "abab";
    cout << maxUniqueSplit(s) << endl;
}