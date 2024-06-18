#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;


void pancakeSortHelp(vector<int>& arr, int end_index, vector<int>& res){
    vector<int>::iterator end_iter = arr.end() - end_index;
    if (end_iter == arr.begin()){
        return;
    }
    vector<int>::iterator max_iter = max_element(arr.begin(), end_iter);
    if (*max_iter == *(end_iter-1)){
        pancakeSortHelp(arr, ++end_index, res);
    }else{
        reverse(arr.begin(), ++max_iter);
        res.push_back(max_iter - arr.begin());
        reverse(arr.begin(), end_iter);
        res.push_back(arr.size() - end_index);
        pancakeSortHelp(arr, ++end_index, res);
    }
}

vector<int> pancakeSort(vector<int>& arr) {
    vector<int> res;
    pancakeSortHelp(arr, 0, res);
    return res;
}

int main(){
    // vector<int> nums = {1,2,3};
    vector<int> nums = {3,2,4,1};
    for(auto item: pancakeSort(nums)){
        cout << item << endl;
    }
}