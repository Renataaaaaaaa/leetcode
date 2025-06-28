
#include <vector>
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;


string convert(string s, int numRows) {
    string res = "";
    for(int i = 0; i < numRows; i++){
        bool down = true;
        int index = i;
        res += s[index];
        while(index < s.size()){
            if (down && i != (numRows - 1)){
                down = false;
                int gap = (2 * (numRows - i) - 1);
                index = index + gap - 1;
                if (index >= s.size()){
                    break;
                }
                res += s[index];
                
            }else if (!down && i != 0){
                int gap = (2 * (i + 1) - 1);
                down = true;
                index = index + gap - 1;
                if (index >= s.size()){
                    break;
                }
                res += s[index];
                
            }else{
                break;
            }
        }
    }
    return res;
}

int main(){
    string s = "PAYPALISHIRING";
    cout << convert (s, 4) << endl;
}