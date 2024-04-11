#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <sstream>
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
class Trie {
public:
    TreeNodee* root;
    Trie() {
        root = new TreeNodee();
    }
    
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
    
    string isPrefix(string word){
        TreeNodee* root_move = root;
        string res = "";
        int i = 0;
        //word reachs end, tree reachs end, be different
        for(; i< word.size(); i++){
            if (root_move->children[word[i] - 'a'] != nullptr){
                root_move = root_move->children[word[i] - 'a'];
                if (root_move->isEnd){
                    break;
                }
            }else{
                break; //different or tree reach ends
            }
        }
        if (root_move->isEnd){
            return word.substr(0, i + 1);
        }else{
            return "";
        }
    }
};

string replaceWords(vector<string>& dictionary, string sentence) {
    Trie trie;
    for (auto prefix: dictionary){
        trie.insert(prefix);
    }
    istringstream ss(sentence);
    string word;
    ostringstream oss;
    while(ss >> word){
        string prefix = trie.isPrefix(word);
        if (prefix == ""){
            oss << word;
        }else{
            oss << prefix;
        }
        oss << " ";
    }
    return oss.str().substr(0, oss.str().size()-1);
}


int main(){
    vector<string> dictionary = {"a", "aa", "aaa", "aaaa"};
    cout << replaceWords(dictionary, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa") << endl;
}