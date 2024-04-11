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
        for (auto& child : children) {
            child = nullptr;
        }
    }
};

class MagicDictionary {
public:
    TreeNodee* root;

    void insert(string word) {
        TreeNodee* root_move = root;
        for(auto c: word){
            bool find = false;
            if (root_move->children[c - 'a'] == nullptr){
                root_move->children[c - 'a'] = new TreeNodee();
            }
            root_move = root_move->children[c - 'a'];
        }
        root_move->isEnd = true;
    }
    MagicDictionary() {
        root = new TreeNodee();
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto item: dictionary){
            insert(item);
        }
    }
    bool searchHelp(string word, int index, TreeNodee* root_cur, bool Error) {
        TreeNodee* root_move = root_cur;

        if (root_move->isEnd && index == word.size() && Error){
            cout << "49 find it" << endl;
            return true;
        }

        //遍历所有子树，针对是否等于index的处理error
        cout << "index " << index << endl;
        for(int i = 0; i < 26; i++){
            bool find = false;
            cout << " i " << i << endl;
            if (root_move->children[i]){
                if (i == word[index] - 'a'){
                    cout << "same " << Error<< endl;
                    find = searchHelp(word, index + 1, root_move->children[i], Error);
                }else if (!Error){
                    cout << "doesn't same" << endl;
                    find = searchHelp(word, index + 1, root_move->children[i], true);
                }
            }
            if (find){
                cout << "68" << endl;
                return true;
            }
        }
        return false;
    }
    bool search(string searchWord) {
        return searchHelp(searchWord, 0, root, false);
    }
};

int main(){
    MagicDictionary magic;
    
    magic.buildDict({"hello", "leetcode"});
    cout << magic.search("leettode") << endl;
    // cout << magic.search("hhllo") << endl;
}