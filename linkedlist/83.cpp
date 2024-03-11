#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = head;
    while(head != nullptr && head->next != nullptr){
        while(head ->next != nullptr && head->val == head->next->val){
            ListNode* tmp = head->next->next;
            head->next = nullptr;
            head->next = tmp;
        }
        head = head->next;
    }
    return res;
}

int main(){
    vector<int> data = {1};
    ListNode* head = generate(data);
    cout << deleteDuplicates(head) << endl;
}