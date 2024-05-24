#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
using namespace std;



class Solution {

bool valid = false;
public:
void solveSudokuHelp(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& line, vector<vector<bool>>& column, vector< vector <vector<bool> > >& block){
    if (i == 9){
        cout << "suceess" << endl;
        valid = true;
        return;
    }
    if (board[i][j] == '.'){
        for (int t = 1; t <= 9; t++){
            if (!line[i][t - 1] && !column[j][t - 1] && !block[i/3][j/3][t - 1]){
                //update
                line[i][t - 1] = true;
                column[j][t - 1] = true;
                block[i/3][j/3][t - 1] = true;
                board[i][j] = t + '0';
                if (j == 8){
                    solveSudokuHelp(board, i + 1, 0, line, column, block);
                }else{
                    solveSudokuHelp(board, i, j + 1, line, column, block);
                }
                if (!valid){
                    line[i][t - 1] = false;
                    column[j][t - 1] = false;
                    block[i/3][j/3][t - 1] = false;
                    board[i][j] = '.';
                }

                //recover
            }
        }
    }else{
        if (j == 8){
            solveSudokuHelp(board, i + 1, 0, line, column, block);
        }else{
            solveSudokuHelp(board, i, j + 1, line, column, block);
        }
    }
}

void solveSudoku(vector<vector<char>>& board) {
    // bool nine [][3][3];
    vector<vector<bool>> line(9, vector<bool>(9, false));
    vector<vector<bool>> column(9, vector<bool>(9, false));
    vector< vector <vector<bool> > > block(3, vector<vector<bool>>(3, vector<bool>(9, false)));
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if (board[i][j] != '.'){
                line[i][board[i][j] - '1'] = true;
                column[j][board[i][j] - '1'] = true;
                block[i/3][j/3][board[i][j] - '1'] = true;
            }
        }
    }
    solveSudokuHelp(board, 0, 0, line, column, block);
}
};

int main(){
    vector<vector<char>> content = {{'.','.','9','7','4','8','.','.','.'},
                                    {'7','.','.','.','.','.','.','.','.'},
                                    {'.','2','.','1','.','9','.','.','.'},
                                    {'.','.','7','.','.','.','2','4','.'},
                                    {'.','6','4','.','1','.','5','9','.'},
                                    {'.','9','8','.','.','.','3','.','.'},
                                    {'.','.','.','8','.','3','.','2','.'},
                                    {'.','.','.','.','.','.','.','.','6'},
                                    {'.','.','.','2','7','5','9','.','.'}};
    solveSudoku(content);
    for(auto line: content){
        for(auto c: line){
            cout << c << " ";
        }
        cout << endl;
    }
}