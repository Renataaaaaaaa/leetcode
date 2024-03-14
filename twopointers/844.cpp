#include <vector>
#include <iostream>
using namespace std;


int backspaceString(string & s, int i){
    int back_num = 0;
    while(i >= 0){
        if (s[i] == '#'){
            back_num++;
        }else if (back_num > 0){
            back_num--;
        }else{
            break;
        }
        i--;
    }
    return i;
}

bool backspaceCompare(string s, string t) {
    int i = s.size() - 1;
    int j = t.size() - 1;
    while( i >= 0 || j >= 0){
        
        i = backspaceString(s, i);
        j = backspaceString(t, j);
        cout << i << "x x" << j << endl;
        // cout << s[i] << "x x" << t[j] << endl;
        if(i != -1 && j != -1){
            if (s[i] != t[j]){
                return false;
            }
        }else if (i >= 0 || j >= 0){
            return false;
        }
        i--;
        j--;
    }
    return true;
}

int main(){
    string a = "bxj##tw";
    string b = "bxj###tw";
    cout << backspaceCompare(a, b) << endl;
    // cout << backspaceString(b, 2) << endl;
}