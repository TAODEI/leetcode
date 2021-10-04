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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *newHead = new ListNode(0, head);
        ListNode *slow = newHead, *fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (!fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return newHead->next;
    }
};