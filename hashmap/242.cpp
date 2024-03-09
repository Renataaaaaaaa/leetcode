#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


bool isAnagram(string s, string t) {
    int char_list[26] = {0};
    if (s.size() != t.size()) {
        return false;
    }
    for (auto c: s){
        char_list[c - 'a']++;
    }
    for (auto c: t){
        if (char_list[c - 'a'] == 0){
            return false;
        }
        char_list[c - 'a']--;
    }
    return true;
}