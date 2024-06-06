#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;

long trailingZeroes(long n) {
    long divisor = 5;
    long res = 0;
    while(n >= divisor){
        res += n / divisor;
        divisor *= 5;
    }
    return res;
}
//lo = hi + 1 一定存在
long leftbbound(long k){
    long lo = 0;
    long hi = INT64_MAX;
    while(lo <= hi){
        long mid = lo + (hi - lo) / 2;
        if (trailingZeroes(mid) == k){
            hi = mid - 1;
        }else if (trailingZeroes(mid) < k){
            lo = mid + 1;
        }else if (trailingZeroes(mid) > k){
            hi = mid - 1;
        }
    }
    return lo;
}

//lo = hi + 1 一定存在
long rightbound(int k){
    long lo = 0;
    long hi = INT64_MAX;
    while(lo <= hi){
        long mid = lo + (hi - lo) / 2;
        if (trailingZeroes(mid) == k){
            lo = mid + 1;
        }else if (trailingZeroes(mid) < k){
            lo = mid + 1;
        }else if (trailingZeroes(mid) > k){
            hi = mid - 1;
        }
    }
    return hi;
}
int preimageSizeFZF(int k) {
    // cout << rightbound(k) << endl;
    // cout << leftbbound(k) << endl;
    return rightbound(k) - leftbbound(k) + 1;
}
int main(){
    cout << preimageSizeFZF(0) << endl;
    cout << preimageSizeFZF(5) << endl;
    cout << preimageSizeFZF(3) << endl;
}