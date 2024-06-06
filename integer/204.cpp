#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;

int countPrimes(int n) {
    vector<bool> isPrim(n, true);

    for (int i = 2; i < n; i++) 
        if (isPrim[i]) 
            // i 的倍数不可能是素数了
            for (int j = 2 * i; j < n; j += i) 
                    isPrim[j] = false;

    int count = 0;
    for (int i = 2; i < n; i++)
        if (isPrim[i]) count++;

    return count;
}
int main(){
    cout << countPrimes(10) << endl;   
}