#include <vector>
#include <iostream>
using namespace std;

vector<int> countBits(int n) {
    vector<int> res(n + 1);

    for (int i = 1; i <= n; i++){
        res[i] = res[i >> 1] + (i & 1); //ATTENTION: & has a lower priority than add
    }
    return res;
}