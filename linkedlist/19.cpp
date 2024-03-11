#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    while(fast->next != nullptr && n > 0){
        fast = fast->next;
        n--;
    }
    ListNode* slow = dummy;
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* next_tmp = slow->next;
    slow->next = slow->next->next; //Memory leak
    delete(next_tmp);
    return dummy->next;
}

int main(){
    vector<int> data = {1,2,3,4,5};
    ListNode* node = generate(data);
    cout << removeNthFromEnd(node, 4) << endl;
}