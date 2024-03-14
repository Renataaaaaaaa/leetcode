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
    bool searchHelp(string word, int index, TreeNodee* root_cur, int Error) {
        TreeNodee* root_move = root_cur;
        if (root_cur == nullptr){
            return false;
        }
        if (root_move->isEnd && Error == 1 && index == word.size()){
            return true;
        }

        if (index < word.size() && Error <= 1){
            bool find = false;
            for (int j = 0; j < 26; j++){
                int next =  j == word[index] - 'a' ? Error : Error + 1;
                    // 0 1
                find = find || searchHelp(word, index + 1, root_move->children[j], next);
            }
            return find;
        }
        return false;
    }
    bool search(string searchWord) {
        return searchHelp(searchWord, 0, root, false);
    }
};