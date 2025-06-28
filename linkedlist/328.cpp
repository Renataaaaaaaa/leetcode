#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

// fast的后一个插到low的后边
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr){
        return head;
    }

    ListNode* low = head;
    ListNode* fast = head->next;
    ListNode* after_fast = nullptr;
    while(fast != nullptr && fast->next != nullptr){
        after_fast = fast->next;
        fast->next = after_fast->next;

        after_fast->next = low->next;
        low->next = after_fast;

        low = low->next;
        fast = fast->next;
        // printLinkedList(head);
    }
    return head;

}
int main(){
    vector<int> data = {1,2,3,4,5};
    printLinkedList(oddEvenList(generate(data)));
}