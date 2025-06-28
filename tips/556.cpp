#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

int nextGreaterElement(int n) {
    if (n < 10){
        return -1;
    }
    string str = to_string(n);
    int i = str.size() - 2;
    for(; i >= 0; i--){
        if (str[i] >= str[i+1]){
            continue;
        }else{
            for(int j = str.size() - 1; j > i; j--){
                if (str[j] > str[i]){
                    char tmp = str[j];
                    str[j] = str[i];
                    str[i] = tmp;
                    break;
                }
            }
            break;
        }
    }

    if (i == -1){
        return -1;
    }else{
        reverse(str.begin() + i + 1, str.end());
        try{
            return stoi(str);
        }catch (const std::out_of_range& e){
            return -1;
        }
    }
}
int main(){
    cout << nextGreaterElement(11) << endl;
}