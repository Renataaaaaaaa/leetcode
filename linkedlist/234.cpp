#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* reverseList(ListNode* l1){ //ATTENTION: remember to use this one
    ListNode* prev = nullptr;
    ListNode * next = nullptr;
    while(l1 != nullptr){
        ListNode* next = l1->next;
        l1->next = prev;
        prev = l1;
        l1 = next;
    }
    return prev;
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
    middleNode = reverseList(middleNode);

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