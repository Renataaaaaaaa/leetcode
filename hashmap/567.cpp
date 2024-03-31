#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

bool allZero(vector<int> & str_char){
    bool all_zero = true;
    for (auto c: str_char){
        if (c != 0){
            all_zero = false;
        }
    }
    return all_zero;
}
bool checkInclusion(string s1, string s2) {
    vector<int> s1_char(26, 0);
    if (s2.size() < s1.size()){
        return false;
    }
    for (int i = 0; i < s1.size(); i++){
        s1_char[s1[i] - 'a']++;
        s1_char[s2[i] - 'a']--;
    }

    if (allZero(s1_char)){
        return true;
    }
    
    for (int i = 1; i < s2.size() - s1.size() + 1; i++){
        s1_char[s2[i - 1] - 'a']++;
        s1_char[s2[i + s1.size() - 1] - 'a']--;
        if (allZero(s1_char)){
            return true;
        }
    }
    return false;
}
int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
}