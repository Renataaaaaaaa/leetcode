#include <vector>
#include <iostream>
using namespace std;


bool dfs(vector<vector<char>>& board, int i, int j ,int index, string& word, vector<vector<bool>>& visited){
    if ( i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || visited[i][j]){
        return false;
    }

    if (index == word.size() - 1){
        return true;
    }
    visited[i][j] = true;
    // char tmp = board[i][j];
    // board[i][j] = '\0';
    bool res = dfs(board, i + 1, j, index + 1, word, visited) || dfs(board, i - 1, j, index + 1, word, visited) || 
                      dfs(board, i, j+1, index + 1, word, visited) || dfs(board, i, j-1, index + 1, word, visited);

    // board[i][j] = tmp;
    visited[i][j] = false;
    return res;
}


bool exist(vector<vector<char>>& board, string word) {
    bool res = false;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
            bool flag =  dfs(board, i, j, 0, word, visited);
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