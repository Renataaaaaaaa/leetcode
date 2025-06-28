#include <vector>
#include <iostream>
using namespace std;


bool dfs(vector<vector<char>>& board, int i, int j ,int index, string& word){
    if ( i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]){
        return false;
    }

    if (index == word.size() - 1){
        return true;
    }
    char tmp = board[i][j];
    board[i][j] = '\0';
    bool res = dfs(board, i + 1, j, index + 1, word) 
             || dfs(board, i - 1, j, index + 1, word) 
             || dfs(board, i, j+1, index + 1, word) 
             || dfs(board, i, j-1, index + 1, word);

    board[i][j] = tmp;
    return res;
}


bool exist(vector<vector<char>>& board, string word) {
    bool res = false;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            bool flag =  dfs(board, i, j, 0, word);
            if (flag){
                return true;
            }
        }
    }
    return res;
}
int main(){
    // vector<vector<char>> chars = {{'A', 'A','A', 'A'}, {'A', 'A','A', 'A'},{'A', 'A','A', 'A'}, {'A', 'A','A', 'A'}};
    vector<vector<char>> chars= {{'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}};
    // string word = "ABCCED";
    string word = "AAAAAAAAAAAAAAB";
    cout << exist(chars, word) << endl;
}