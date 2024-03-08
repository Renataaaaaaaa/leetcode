#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int p = 0;
    int q = numbers.size() - 1;
    vector<int> res;
    while(q > p){
        if ((numbers[p] + numbers[q]) > target){
            q--;
        }else if ((numbers[p] + numbers[q]) < target){
            p++;
        }else{
            res.push_back(p+1);
            res.push_back(q+1);
            break;
        }
    }
    return res;
}