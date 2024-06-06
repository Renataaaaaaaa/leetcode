#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;

int hammingWeight(int n) {
    int res = 0;
    while(n != 0){
        n = n & (n - 1);
        res ++;
    }
    return res;
}
int main(){
    cout << hammingWeight(11) << endl;
}