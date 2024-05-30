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

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> nums(n, 0);
    Diff diff(nums);
    for(auto record: bookings){
        diff.edit(record[0] - 1, record[1] - 1, record[2]);
    }
    return diff.getResult();
}
int main(){
    vector<vector<int>> data = {{1,2,10},{2,3,20},{2,5,25}};
    for(auto item: corpFlightBookings(data, 5)){
        cout << item << endl;
    }
}