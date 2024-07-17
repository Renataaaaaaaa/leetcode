
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;
#include <cmath>


// vector<string> func(int n){
//     int sqrt_result = static_cast<int>(std::ceil(n));
//     unordered_map<int, int> map;
//     int sum = 0;
//     vector<string> res;
//     for(int i = 1; i < sqrt_result; i++){
//         int sqr = i * i;
        
//         //sum 加完当前的 sqr
//         if (map.find((sqr + sum) - n) != map.end()){
//             // map[(sqr + sum) - n] 到 i

//         }
//         map[sqr + sum] = i;
//         sum = sqr + sum;

//     }
//     return {};
// }

unordered_set<int> contains7;

bool isContains7(int a){
    while (a > 0) {
        if (a % 10 == 7) {
            return true;
        }
        a /= 10;
    }
    return false;
}

void init(int a){
    for(int i = 1; i < a; i++){
        if (isContains7(i) ){
            contains7.insert(i);
        }
    }
}
int func(int a){
    int i;
    init(a);
    for(i = a + 1; ;i++){
        bool skip = false;
        for(auto item: contains7){
            if (i % item == 0){
                skip = true;
            }
        }
        if (skip){
            continue;
        }
        if (isContains7(i)){
            contains7.insert(i);
            continue;
        }
        break;
    }
    return i;
}


int main(){
    int n = 33;
    cout << func(n) << endl;
}