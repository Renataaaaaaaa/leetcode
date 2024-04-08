#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
#include <cstdlib>
//hashmap + double linkedlist
struct Node{
    int key;
    int value;
    Node* prev = nullptr; //ATTENTION: !!!
    Node* next = nullptr;
    // Node(int value): value(value){};
    Node(): key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int key, int value): key(key), value(value){
    };
};
class LRUCache {
public:
    Node* head ;
    Node* tail ;
    unordered_map<int, Node*> map;
    int capacity = 0;
    int nums = 0;
    LRUCache(int capacity): capacity(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->next = head;
    }
    void moveToHead(Node* node){
        Node* next_tmp = node->next;
        Node* prev_tmp = node->prev;
        prev_tmp->next = next_tmp;
        node->next->prev = prev_tmp;
        addToHead(node);
    }
    void addToHead(Node* node){
        Node* head_next_o = head->next;
        head->next = node;
        node->next = head_next_o;
        head_next_o->prev = node;
        node->prev = head;
    }
    void removeTail(){
        Node* tail_prev_o = tail->prev->prev;
        tail->prev = tail_prev_o;
        tail_prev_o->next = tail;
        //TODO
    }
    int get(int key) {
        if (map.find(key) != map.end()){
            Node* node = map.at(key);
            int res = node->value;
            moveToHead(node);
            // map[key] = tail; //TODO
            return res; 

        }else{
            return -1;
        }
    }
    
    void put(int key, int value) { //ATTENTION: how to delete and not affect other elements
        if (map.find(key) == map.end()){
            nums++;
            Node* node = new Node(key, value);
            addToHead(node);
            map[key] = node;
            if (nums > capacity){
                map.erase(tail->prev->key);
                removeTail();
            }
        }else{ //update
            Node* node = map.at(key);
            node->value = value;
            moveToHead(node);
        }
    }
};
int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl;
    obj->put(3,3);
    cout << obj->get(2) << endl;
    obj->put(4,4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
}