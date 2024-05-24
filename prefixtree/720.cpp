#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;
class TreeNodee{
    public:
        TreeNodee* children[26];
        bool isEnd = false;
        TreeNodee(){
            for (int i = 0; i< 26; i++){
                children[i] = nullptr;
            }
            isEnd = false;
        }
};
class PrefixTree{
    public:
        TreeNodee* root;
        PrefixTree(){
            root = new TreeNodee();
        }
        void insert(string word){
            TreeNodee* root_move = root;
            for (auto c: word){
                if (root_move->children[c - 'a'] == nullptr){
                    root_move->children[c - 'a'] = new TreeNodee();
                }
                root_move = root_move->children[c - 'a'];
            }
            root_move->isEnd = true;
        }

};

int maxNum = INT32_MIN;
void findLongestWord(TreeNodee* root, int num, string& cur_str, string &str){
    TreeNodee* root_move = root;
    for(int i = 0; i < 26; i++){
        if (root_move->children[i] != nullptr && root_move->children[i]->isEnd){
            cur_str = cur_str + static_cast<char>('a' + i );
            findLongestWord(root->children[i], ++num, cur_str, str);
            num--;
            cur_str = cur_str.substr(0, cur_str.size() - 1);
        }
    }
    if (num > maxNum){
        cout << "50" << endl;
        cur_str = str;
        maxNum = num;
    }

}
string longestWord(vector<string>& words) {
    PrefixTree prefixtree;
    for (auto word: words){
        prefixtree.insert(word);
    }
    string cur_res = "";
    string res = "";
    findLongestWord(prefixtree.root, 0, cur_res, res);
    return res;
}
int main(){
    // vector<string> words = {"w","wo","wor","worl","world"};
    vector<string> words = {"a","banana","app","appl","ap","apply","apple"};
    cout << longestWord(words) << endl;
}