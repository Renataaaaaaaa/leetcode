#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* reverseList(ListNode* l1){ //ATTENTION: remember to use this one
    ListNode* last = nullptr;
    while(l1!=nullptr){
        ListNode* tmp = l1->next;
        l1->next = last;
        last = l1;
        l1 = tmp;
    }
    return last;
}

ListNode* getMiddleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* low = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        low = low->next;
    }
    return low;
}

bool isPalindrome(ListNode* head) {
    
    ListNode* middleNode = getMiddleNode(head);
    cout << middleNode->val << endl;
    middleNode = reverseList(middleNode);
    cout << middleNode->val << endl;
    while(middleNode != nullptr){
        if (head->val != middleNode->val){
            return false;
        }
        middleNode = middleNode->next;
        head = head->next;
    }
    return true;
}

int main(){
    vector<int> data = {1,2};
    // vector<int> data = {1,2,3,2,1};
    ListNode* head = generate(data);
    cout << isPalindrome(head) << endl;
}