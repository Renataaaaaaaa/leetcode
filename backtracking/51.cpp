#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
using namespace std;
int n_num = 0;

void solveNQueensHelp(int i,  vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2, vector<vector<bool>>& cur_res, vector<vector<string>>& res){
    if (i == n_num){
        bool column_true = true;
        for(auto column: columns){
            if (!column){
                column_true = false;
            }
        }
        // cout << line_true << " " << column_true << endl;
        if (column_true){
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
            res.push_back(res_tmp);
        }
        
        return;
    }
    //try put or not put
    for(int j = 0; j < n_num; j++){
        //update
        if (!columns[j] && !diag1[j - i + n_num - 1] && !diag2[i + j]){
            columns[j] = true;
            diag1[j - i + n_num - 1] = true;
            diag2[i + j] = true;
            cur_res[i][j] = true;
            cout << "53 " << endl;
            solveNQueensHelp(i + 1, columns, diag1, diag2, cur_res, res);
            
            columns[j] = false;
            diag1[j - i + n_num - 1] = false;
            diag2[i + j] = false;
            cur_res[i][j] = false;
            //recover
        }
    }


}
vector<vector<string>> solveNQueens(int n) {
    n_num = n;
    vector<bool> columns(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);
    vector<vector<string>> res;
    vector<vector<bool>> cur_res(n, vector<bool>(n, false));
    solveNQueensHelp(0, columns, diag1, diag2, cur_res, res);
    return res;
}

int main(){
    for(auto res: solveNQueens(5)){
        for(auto item: res){
            cout << item << endl;
        }
        cout << "one res" << endl;
        cout << endl;
    }
}