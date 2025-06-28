
#include <vector>
#include <iostream>
// #include "utils.cpp"
using namespace std;
#include <unordered_set>

int getNext(int n){
    string str = to_string(n);
    int res = 0;
    for(auto ch: str){
        res += ((ch - '0') * (ch - '0'));
    }
    return res;
}
bool isHappy(int n) {
    unordered_set<int> set_seen;
    n = getNext(n);
    while(set_seen.find(n) == set_seen.end() && n != 1){
        set_seen.insert(n);
        n = getNext(n);

    }
    return n == 1;
}

int main(){
    cout << isHappy(19) << endl;
}