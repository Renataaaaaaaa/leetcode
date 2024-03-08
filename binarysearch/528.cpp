#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> weights;
    int sum = 0;
    Solution(vector<int>& w) {
        for (auto num: w){
            sum += num;
        }
        for (auto num: w){
            if (weights.size() == 0){
                weights.push_back(num);
            }else{
                weights.push_back(num + weights[weights.size() - 1]);
            }
        }
        for (auto num: weights){
            cout << num << endl;
        }
    }
    
    int pickIndex() {
        int random_index = rand() % sum + 1;
        int lo = 0;
        int hi = weights.size() - 1;
        int mid = 0;
        while (hi >= lo){ //ATTENTION: remember this method to find number in a range
            mid = (lo + hi ) / 2;
            if (weights[mid] == random_index){
                break;
            }else if (weights[mid] > random_index){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        if (weights[mid] < random_index){ //ATTENTION
            return mid + 1;
        }else{
            return mid;
        }
    }
};