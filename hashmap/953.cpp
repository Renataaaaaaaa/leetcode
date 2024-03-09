#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> myMap;
    for (int i = 0; i<order.size(); i++){
        myMap[order[i]] = i;
    }
    for(int i = 0; i < words.size() - 1; i++){
        string a = words[i];
        string b = words[i+1];
        int m = 0;
        // a < b
        for(; m < a.size() && m < b.size() && a[m] == b[m]; m++){
        }

        if (m < a.size() && m < b.size() && myMap.at(a[m]) > myMap.at(b[m])){
            return false;
        }
        if (m == b.size() && m < a.size()){
            return false;
        }
    }
    return true;
}