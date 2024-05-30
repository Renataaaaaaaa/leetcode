#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

class Diff{
    vector<int> diff;
    public:
        Diff(vector<int>& nums){
            diff.push_back(nums[0]);
            for(int i = 1; i < nums.size(); i++){
                diff.push_back(nums[i] - nums[i-1]);
            }
        }
        void edit(int i, int j, int val){
            diff[i] += val;
            if (j + 1 < diff.size()){
                diff[j+1] -= val;
            }
            
        }
        vector<int> getResult(){
            vector<int> res;
            res.push_back(diff[0]);
            for(int i = 1; i < diff.size(); i++){
                res.push_back(diff[i] + res[i-1]);
            }
            return res;
        }
};

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> stops(1001, 0);
    Diff diff(stops);
    for(auto trip: trips){
        diff.edit(trip[1], trip[2]-1, trip[0]);
    }
    for (auto num: diff.getResult()){
        if (num > capacity){
            return false;
        }
    }
    return true;
}
int main(){
    vector<vector<int>> trips = {{2,1,5},{3,5,7}};
    cout << carPooling(trips, 5) << endl;
}
