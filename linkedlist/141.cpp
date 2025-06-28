#include <vector>
#include <iostream>
// #include "utils.cpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head==nullptr ){
        return false;
    }
    ListNode* fast = head;
    ListNode* low = head;

    while(fast != nullptr && fast->next != nullptr){ //ATTENTION: 注意双指针结束位置
        fast = fast->next->next;
        low = low->next;
        if (fast == low){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> data = {3,2,0,-4};
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node4 = new ListNode(4);
    node3->next = node3;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2;
    // ListNode* head = generate(data);
    cout << hasCycle(node3) << endl;
}