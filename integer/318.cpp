#include <vector>
#include <iostream>
using namespace std;

int maxProduct(vector<string>& words) {
    vector<int> char_bool(words.size(), 0);
    for (int i = 0; i < words.size(); i++){
        for (auto c: words[i]){
        char_bool[i] |= (1 << (c - 'a'));  
        }
    }
    int res = 0;
    for (int i = 0; i < words.size(); i++){
        for (int j = i; j < words.size(); j++){
            bool overlap = false;
            if((char_bool[i] & char_bool[j]) != 0 ){
                overlap = true;
            }
            if (!overlap){
                res = max(res, int(words[i].size() * words[j].size()));
            }
        }
    }
    return res;
}