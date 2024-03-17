#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    if (node == nullptr){
        return nullptr;
    }
    queue<Node* > queue_1;
    queue_1.push(node);
    Node* node_copy = new Node(node->val);
    unordered_map<Node*, Node*> visited;
    visited[node] = node_copy;

    Node* neighbor_copy = nullptr, *node_front_copy = nullptr;
    while(!queue_1.empty()){
        Node* node_front = queue_1.front();
        Node* node_front_copy = visited[node_front];
        for (auto neighbor: node_front->neighbors){
            if (visited.find(neighbor) == visited.end()){
                queue_1.push(neighbor);
                neighbor_copy = new Node(neighbor->val);
                visited[neighbor] = neighbor_copy;
                node_front_copy->neighbors.push_back(neighbor_copy);
            }else{
                node_front_copy->neighbors.push_back(visited[neighbor]);
            }
        }
        queue_1.pop();
    }
    return node_copy;
    
}
int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Node* res = cloneGraph(node1);
    cout << res->neighbors[0]->val << endl;
    cout << res->neighbors[1]->val << endl;
    cout << res->neighbors[0]->neighbors[0]->val << endl;
    cout << res->neighbors[0]->neighbors[1]->val << endl;
    cout << res->neighbors[0]->neighbors[1]->neighbors[0]->val << endl;
    cout << res->neighbors[0]->neighbors[1]->neighbors[1]->val << endl;
    cout << res->neighbors[1]->neighbors[0]->val << endl;
    cout << res->neighbors[1]->neighbors[1]->val << endl;
}