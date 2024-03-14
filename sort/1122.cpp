#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;
class Solution {
public:
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> assist(1001, 0);
    for (auto num: arr1){
        assist[num - 0]++;
    }
    vector<int> res;
    for (auto num: arr2){
        while(assist[num - 0] != 0){
            res.push_back(num);
            assist[num - 0]--;
        }
    }
    for (int i = 0; i < assist.size(); i++){
        if (assist[i] != 0){
            res.insert(res.end(), assist[i], i);
        }
    }
    return res;
}
};