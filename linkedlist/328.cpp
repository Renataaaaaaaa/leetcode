#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;


ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr){
        return head;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode* low = &dummy;
    ListNode* fast = dummy.next;
    ListNode* after_fast = nullptr;
    while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
        fast = fast->next;
        low = low->next;

        cout << "fast val" << fast->val << endl;

        after_fast = fast->next;

        fast->next = fast->next->next;
        after_fast->next = low->next;
        low->next = after_fast;
        cout << "after on iteration" << endl;
        printLinkedList(head);
    }
    return head;

}
int main(){
    vector<int> data = {2,1,3,5,6,4,7};
    printLinkedList(oddEvenList(generate(data)));
}