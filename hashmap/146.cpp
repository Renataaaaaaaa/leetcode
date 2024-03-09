#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
#include <cstdlib>
struct Node{
    int key;
    int value;
    Node* prev = nullptr; //ATTENTION: !!!
    Node* next = nullptr;
    // Node(int value): value(value){};
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
    void updateNode(Node* node){
        if (head == tail){
            return;
        }
        if (node == tail){
            return;
        }
        Node* next_tmp = node->next;
        Node* prev_tmp = node->prev;
        if (prev_tmp != nullptr){
            prev_tmp->next = next_tmp;
        }else{
            head = next_tmp;
        }
        if (next_tmp != nullptr){
            node->next->prev = prev_tmp;
        }
        node->prev = tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;
    }
    LRUCache(int capacity): capacity(capacity) {
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()){
            Node* node = map.at(key);
            
            int res = node->value;
            updateNode(node);
            map[key] = tail;
            return res;

        }else{
            return -1;
        }
    }
    
    void put(int key, int value) { //ATTENTION: how to delete and not affect other elements
        if (map.find(key) == map.end()){
            // add a new one
            nums++;
            if (nums > capacity){
                map.erase(head->key);
                if (head == tail){
                    head = nullptr;
                    tail = nullptr;
                }else{
                    head->next->prev = nullptr;
                    head = head->next;
                }

                
            }
            Node* new_node = new Node(key, value);
            map[key] = new_node;
            if (head == nullptr && tail == nullptr){              
                head = new_node;
                tail = new_node;
            }else{
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }

        }else{
            Node* node = map.at(key);
            node->value = value;
            updateNode(node);
            map[key] = tail;
        }
    }
};