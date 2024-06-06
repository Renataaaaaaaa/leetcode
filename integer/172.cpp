#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;
 
//125为例 125/5 = 25 意味着 5 10 15 20每个，总共25个数，每个可以提供一个5因子
//125/25 = 5 25 50 75 这些数 每个可以提供两个5因子，再加一
int trailingZeroes(int n) {
    long divisor = 5;
    int res = 0;
    while(n >= divisor){
        res += n / divisor;
        divisor *= 5;
    }
    return res;
}
int main(){
    cout << trailingZeroes(5) << endl;
}