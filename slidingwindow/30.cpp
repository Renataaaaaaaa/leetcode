#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <numeric>
using namespace std;

bool checkAllZero(unordered_map<string, int>& map){
    for(const auto pair: map){
        if (pair.second != 0){
            return false;
        }
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int m = words[0].size();
    for(int i = 0; i < m && (i + m * words.size() - 1 )< s.size(); i++){
        unordered_map<string, int> map;
        for(auto word: words){
            map[word]++;
        }
        int j = i;
        for(int k = 0; k < words.size(); k++){
            map[s.substr(j, m)]--;
            j += m;
        }
        if (checkAllZero(map)){
            res.push_back(i);
        }
        for(; (j + m - 1) < s.size(); j += m){
            map[s.substr(j, m )]--;
            map[s.substr(j - words.size() * m, m)]++;
            if (checkAllZero(map)){
                res.push_back(j - (words.size() - 1) * m);
            }
        }
    }
    return res;
}
int main(){
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"foo","bar","the"};
    for(auto item: findSubstring(s, words)){
        cout << item << endl;
    }
}