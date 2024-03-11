#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* hasCycle(ListNode *head) {
    if (head == nullptr ){
        return nullptr;
    }
    ListNode* fast = head;
    ListNode* low = head;

    while(fast != nullptr && fast->next != nullptr){ //ATTENTION: 注意双指针结束位置
        fast = fast->next->next;
        low = low->next;
        if (fast == low){
            return low;
        }
    }
    return nullptr;
}

ListNode *detectCycle(ListNode *head) {
    ListNode* first_meet = hasCycle(head);
    if (first_meet == nullptr) {
        return nullptr;
    }
    while(head != first_meet){
        head = head->next;
        first_meet = first_meet->next;
    }
    return head;
}

int main(){
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    // ListNode* node0 = new ListNode(0);
    // ListNode* node4 = new ListNode(4);
    node3->next = node2;
    node2->next = node3;
    // node0->next = node4;
    // node4->next = node2;
    cout << detectCycle(node3)->val << endl;
}