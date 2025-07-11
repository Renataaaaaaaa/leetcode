#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

// pair<ListNode*, ListNode*> reverseList(ListNode* head, int range){


//     ListNode* prev = nullptr;
//     ListNode* next_tmp = nullptr;

//     for (int i = 0; i < range; i++){
//         next_tmp = head->next;
//         head->next = prev;
//         prev = head;
//         head = next_tmp;
//     }
//     return make_pair(prev, head);
// }
// ListNode* reverseBetween(ListNode* head, int left, int right) {
//     ListNode dummy(0);
//     dummy.next = head;
//     ListNode* move = &dummy;
//     for (int i = 0; i < left - 1; i++){
//         move = move->next;
//     }
//     pair<ListNode*, ListNode*> reverseRes = reverseList(move->next, right - left + 1);
//     move->next->next = reverseRes.second;
//     move->next = reverseRes.first;
//     return dummy.next;
// }
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *pre = dummyNode;
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    ListNode *cur = pre->next;
    ListNode *next;
    for (int i = 0; i < right - left; i++) {
        next = cur->next; //把next头插进来
        cur->next = next->next;
        next->next = pre->next; //重点
        pre->next = next;
    }
    return dummyNode->next;
}
int main(){
    vector<int> data = {1,2,3,4,5};
    ListNode* node = generate(data);
    printLinkedList(reverseBetween(node, 2,4));
}