#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void reverse(Node* root){

    Node* last = nullptr;
    while(root != nullptr){
        Node* tmp = root->next;
        root->next = last;
        last = root;
        root = tmp;
    }
}
Node* connect(Node* root) {
    if (root == nullptr){
        return nullptr;
    }
    queue<Node* > queue_1;
    queue_1.push(root);
    Node* front = nullptr;
    root->next = nullptr;
    int level_size = 0;

    while(!queue_1.empty()){
        level_size = queue_1.size();
        Node* last = nullptr;
        for (int i = 0; i < level_size; i++){
            front = queue_1.front();
            if (front->left != nullptr){
                queue_1.push(front->left);
                front->left->next = last;
                last = front->left;
            }
            if (front->right != nullptr){
                queue_1.push(front->right);
                front->right->next = last;
                last = front->right;
            }
            queue_1.pop();
        }
        if (last != nullptr){
            cout << last->val << endl;
            reverse(last);    
            cout << last->next << endl;

        }
        cout << "58 " << endl;
    }
    // cout << index << " " << height << endl;
    return root;
}
int main(){
    Node* node_1 = new Node(1);
    Node* node_2 = new Node(2);
    Node* node_3 = new Node(3);
    node_1->left = node_2;
    node_1->right = node_3;
    cout << connect(node_1)->left->next->val << endl;
}