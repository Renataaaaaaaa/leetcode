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
        for (int j = i + 1; j < words.size(); j++){
            if ((char_bool[i] & char_bool[j]) == 0){
                res = max(res, int(words[i].size() * words[j].size()));
            }
        }
    }
    return res;
}

int main(){
    vector<string> data = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << maxProduct(data) << endl;
}