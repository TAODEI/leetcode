#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }

        auto q = head;
        while(q->next) {
            auto newHead = q->next;
            q->next = newHead->next;
            newHead->next = head;
            head = newHead;
        }
        return head;
    
    }
    
};