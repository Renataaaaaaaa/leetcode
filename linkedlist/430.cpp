#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

Node* flattenHelp(Node* head) {
    while(( head!= nullptr) && (head->next != nullptr || head->child != nullptr)){
        cout << head->val <<endl;
        if (head->child != nullptr){
            
            Node* next_old = (head->next == nullptr) ? nullptr : head->next; //maybe nullptr
            head->next = head->child;
            head->child->prev = head;
            Node* next_new = flattenHelp(head->child);
            head->child = nullptr;
            if (next_old == nullptr){
                next_new->next = next_old;
                head = next_new;
            }else{
                next_new->next = next_old;
                next_old->prev = next_new;
                head = next_new;
            } 

        }else{
            head = head->next;
        }
    }
    cout << "45" << endl;
    return head;
}
Node* flatten(Node* head){
    Node* res = head;
    flattenHelp(head);
    return res;
}