#include <vector>
#include <iostream>
using namespace std;
bool canShip(int capacity, int days, vector<int>& weights){
    int currentLoad = 0;
    int days_count = 1;
    for(int i = 0; i < weights.size(); i++){
        if (weights[i] > capacity){
            return false;
        }
        currentLoad += weights[i];
        if (currentLoad > capacity){
            days_count++;
            if (days_count > days){
                return false;
            }
            currentLoad = weights[i];
        }
    }
    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int sum_weight = 0;
    for(auto item: weights){
        sum_weight += item;
    }
    int lo = 1;
    int hi = sum_weight;
    int mid;
    while(hi >= lo){
        mid = lo + (hi - lo) / 2;
        if (!canShip(mid, days, weights)){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    //左边界
    return lo;
}
int main(){
    vector<int> weights = {1,2,3,1,1};
    cout << shipWithinDays(weights, 4) << endl;
}