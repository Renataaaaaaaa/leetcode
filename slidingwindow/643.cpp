#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++){
        sum += nums[i];
    }
    double average = double(sum) / k;
    double last_average = double(sum) / k;
    cout << "average" << average << endl;
    for (int i = k; i < nums.size(); i++){
        cout << (double(nums[i] - nums[i - k]) / k + average) << endl;
        last_average = (double(nums[i] - nums[i - k]) / k + last_average);
        average = max(last_average, average);
        // last_average = average_tmp;

    }
    return average;
}
int main(){
    vector<int> data = {0,4,0,3,2};
    cout << findMaxAverage(data, 1) << endl;;
}