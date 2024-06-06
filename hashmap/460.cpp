
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
#include <cstdlib>
#include <list>
struct Node{
    int key;
    int value;
    int freq;
    Node(int k, int v, int f): key(k), value(v), freq(f) {}
};

class LFUCache {
public:
    unordered_map<int, list<Node*>::iterator> keytable;
    unordered_map<int, list<Node*>> freqtokeys;
    int minFreq = 0;
    int capacity = 0;
    LFUCache(int capacity): capacity(capacity) {
    }
    
    void moveFreq(int key){ //从原来的删除（判断是否为空），在+1的使用频率上增加，设置迭代器
        list<Node*>::iterator iter = keytable[key];
        int freq = (*iter)->freq;
        int value = (*iter)->value;
        freqtokeys[freq].erase(iter);
        if (freqtokeys[freq].size() == 0){
            freqtokeys.erase(freq);
            if (minFreq == freq){
                minFreq += 1;
            }
        }
        freqtokeys[freq + 1].push_back(new Node(key, value, freq + 1));
        keytable[key] = --freqtokeys[freq + 1].end();
    }

    int get(int key) {
        if(keytable.find(key) != keytable.end()){ //存在 更新使用频率
            list<Node*>::iterator iter = keytable[key];
            int value = (*iter)->value;
            moveFreq(key);
            return value;
        }else{ //不存在
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(keytable.find(key) != keytable.end()){//存在 更新使用频率
            list<Node*>::iterator iter = keytable[key];
            (*iter)->value = value;
            moveFreq(key);
        }else{//不存在 使用频率为1的加上 设置迭代器

            if (keytable.size() == capacity){
                Node* deletenode = freqtokeys[minFreq].front();
                freqtokeys[minFreq].pop_front();
                keytable.erase(deletenode->key);

                if (freqtokeys[minFreq].size() == 0){
                    freqtokeys.erase(minFreq);
                }
            }
            freqtokeys[1].push_back(new Node(key, value, 1));
            keytable[key] = --freqtokeys[1].end();
            minFreq = 1;
        }
    }
};
int main(){
    LFUCache* obj = new LFUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl; //1
    obj->put(3,3);
    cout << obj->get(2) << endl; // -1
    cout << obj->get(3) << endl; //3

    obj->put(4,4);
    // cout << obj->get(3) << endl; // 3
    cout << obj->get(1) << endl; //-1
    cout << obj->get(3) << endl; // 3
    cout << obj->get(4) << endl; //4
    // obj->put(4,4);
    // cout << obj->get(1) << endl;
    // cout << obj->get(3) << endl;
    // cout << obj->get(4) << endl;
}

