#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
using namespace std;

vector<string> generateBoard(vector<vector<bool>>& cur_res){
    vector<string> res_tmp;
    for(auto line: cur_res){
        string tmp = "";
        for(auto co: line){
            if (co){
                tmp += 'Q';
            }else{
                tmp += '.';
            }
        }
        res_tmp.push_back(tmp);
    }
    return res_tmp;
}
void solveNQueensHelp(int n, int i,  vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2, vector<vector<bool>>& cur_res, vector<vector<string>>& res){
    if (i == n){
        res.push_back(generateBoard(cur_res));
        return;
    }
    //try put or not put
    for(int j = 0; j < n; j++){
        if (!columns[j] && !diag1[j - i + n - 1] && !diag2[i + j]){
            columns[j] = diag1[j - i + n - 1] = diag2[i + j] = cur_res[i][j] = true;
            solveNQueensHelp(n, i + 1, columns, diag1, diag2, cur_res, res);
            columns[j] = diag1[j - i + n - 1] = diag2[i + j] = cur_res[i][j] = false;
        }
    }


}
vector<vector<string>> solveNQueens(int n) {
    vector<bool> columns(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);
    vector<vector<string>> res;
    vector<vector<bool>> cur_res(n, vector<bool>(n, false));
    solveNQueensHelp(n, 0, columns, diag1, diag2, cur_res, res);
    return res;
}

int main(){
    for(auto res: solveNQueens(4)){
        for(auto item: res){
            cout << item << endl;
        }
        cout << "one res" << endl;
        cout << endl;
    }
}