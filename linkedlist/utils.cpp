#include <vector>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};


//{1,2,3,4,5,6}
ListNode* generate(vector<int> nodes){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (auto node_val: nodes){
        tail->next = new ListNode(node_val);;
        tail = tail->next;
    }
    return dummy.next;
}

void printLinkedList(ListNode* head){
    while(head != nullptr){
        cout << head->val << endl;
        head = head->next;
    }
}