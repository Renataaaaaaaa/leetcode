#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* middleNode(ListNode* head) {
    // if (head == nullptr || head->next == nullptr){
    //     return head;
    // }
    ListNode* fast = head;
    ListNode* low = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        low = low->next;
    }
    return low;
}
int main(){
    vector<int> data = {};
    ListNode* head = generate(data);
    cout << middleNode(nullptr) << endl;
}