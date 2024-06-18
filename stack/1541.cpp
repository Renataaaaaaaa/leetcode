#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int minInsertions(string s) {
    int need_right = 0;
    int res = 0;
    for(auto c: s){
        if (c == '('){
            need_right += 2;
            if (need_right % 2 == 1){ //若对右括号需求为奇数，应该需要插入一个右括号和一个左括号
                need_right -= 1;
                res += 1;
            }
        }else{ //')'
            need_right -= 1;
            if (need_right == -1){ //只有一个有括号), 应该需要())
                res += 1;
                need_right = 1;
            }
        }
    }//1 2 2 1 3 3 4 2
    return res + need_right;
}

int main(){
    string s = "(()))";
    // string s = ")())(";
    string s2 = "))";
    string s3 = "))())(";
    cout << minInsertions(s) << endl;
    cout << minInsertions(s2) << endl;
    cout << minInsertions(s3) << endl;
}