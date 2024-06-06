#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;
//1337

int base = 1337;
int myPow(int a, int b){
    if (b == 0){
        return 1;
    }
    // int res = 1;
    // a = a % 1337;
    // for(int i = 0; i < b; i++){
    //     res = res * a;
    //     res = res % 1337;
    // }

    int halfPow = myPow(a, b/2);
    if (b % 2 == 0){
        return (halfPow % base) * (halfPow % base) % base;
    }else{
        return ((halfPow % base) * (halfPow % base) % base) * (a % base) % base;
    }
    // return res;
}
int superPow(int a, vector<int>& b) {
    if (b.size() == 0){
        return 1;
    }
    int last_digit = b[b.size() - 1];
    b.pop_back();
    int pow_1 = pow(a, last_digit);
    int pow_2 = pow(superPow(a, b), 10);
    return (pow_1 * pow_2) % base;
}
int main(){
    int a = 2;
    vector<int> nums = {3};
    cout << superPow(a, nums) << endl;
}