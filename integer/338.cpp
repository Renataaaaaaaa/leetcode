#include <vector>
#include <iostream>
using namespace std;

//注意位运算的优先级，记得加括号
//判断奇偶用i&1
vector<int> countBits(int n) {
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++){
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}
int main(){
    for (auto item: countBits(2)){
        cout << item << endl;
    }
    
}