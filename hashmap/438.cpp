#include <vector>
#include <iostream>
using namespace std;

bool allZero(vector<int> & char_nums){
    for (auto num: char_nums){
        if (num != 0){
            return false;
        }
    }
    return true;
}
vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    vector<int> s2_char(26, 0);
    if (s.size() < p.size()){
        return res;
    }
    for (int i = 0; i < p.size(); i++){
        s2_char[p[i] - 'a']++;
        s2_char[s[i] - 'a']--;
    }

    if(allZero(s2_char)){
        res.push_back(0);
    }
    for (int i = 1; i < s.size() - p.size() + 1; i++){
        s2_char[s[i - 1] - 'a']++;
        s2_char[s[i + p.size() - 1] - 'a']--;
        if (allZero(s2_char)){
            res.push_back(i);
        }
    }
    return res;
}