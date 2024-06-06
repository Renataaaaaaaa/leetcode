#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;

double myPowHelp(double x, int n){
    if (n == 1){
        return x;
    }
    double halfPow = myPowHelp(x, n/2);
    if (n % 2 == 0){
        return halfPow * halfPow;
    }else{
        return halfPow * halfPow * x;
    }
}

double myPow(double x, int n) {
    if (n < 0){
        return 1 / myPowHelp(x,  -long(n));
    }else{
        return myPowHelp(x, n);
    }
}

int main(){
    cout << myPow(2.1,0) << endl;
}