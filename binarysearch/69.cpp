#include <vector>
#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x == 0){
        return 0;
    }
    int lo = 1;
    int hi = x;
    int mid;
    while(hi >= lo){
        mid = lo + (hi - lo) / 2;
        // cout << "mid " << mid << endl;
        if (x / mid == mid){
            return mid;
        }else if (x / mid > mid){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return hi;
}