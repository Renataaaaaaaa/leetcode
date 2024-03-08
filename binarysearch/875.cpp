#include <vector>
#include <iostream>
using namespace std;

bool timeExeed(vector<int>& piles, int speed, int quota){
    for (auto pile: piles){
        quota -= pile / speed + ((pile % speed) > 0);
        if (quota < 0){
            return true;
        }
    }
    return false;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int max = 0;
    for(auto item: piles){
        max = item > max ? item: max;
    }

    int lo = 1;
    int hi = max;
    int mid;
    while( hi >= lo){
        mid = (lo + hi) / 2;
        // cout << "mid " << mid << "timecost " << timeCost(piles, mid) << endl;
        if (timeExeed(piles, mid, h)){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    if (timeExeed(piles, mid, h)){
        return mid + 1;
    }else{
        return mid;
    }
}