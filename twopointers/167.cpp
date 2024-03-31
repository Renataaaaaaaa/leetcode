#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int p = 0;
    int q = numbers.size() - 1;
    while(q > p){
        if ((numbers[p] + numbers[q]) > target){
            q--;
        }else if ((numbers[p] + numbers[q]) < target){
            p++;
        }else{
            return {p+1, q+1};
        }
    }
    return {};
}