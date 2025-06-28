
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

pair<string, int> decodeStringHelp(string& s, int index){
    int cur_num = 0;
    string res = "";
    int i = index;
    for(; i < s.size(); i++){
        if (s[i] == '['){
            pair<string, int> repeat = decodeStringHelp(s, i + 1);
            i = repeat.second;
            for(int j = 0; j < cur_num; j++){
                res += repeat.first;
            }
            cur_num = 0;
        }else if (s[i] == ']'){
            break;
        }else if (s[i] >= '0' && s[i] <= '9'){ //遇到新数字的时候清空
            cur_num = cur_num * 10 + (s[i] - '0');
        }else{
            res += s[i];
        }
    }
    return {res, i};
}

string decodeString(string s) {
    return decodeStringHelp(s, 0).first;
}

int main(){
    string s = "2[abc]3[cd]ef";
    // string s = "11a2b";
    cout << decodeString(s) << endl;
}




