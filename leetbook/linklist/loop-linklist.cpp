#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        int tag = 0;

        while (fast->next != NULL && fast != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                tag = 1;
                break;
            }
        }
        if (tag == 0) {
            return NULL;
        }

        while (head != slow) { // fast速度是slow的两倍
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};