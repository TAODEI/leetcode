struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        auto fast = head, low = head;
        while (fast && fast->next) {
            low = low->next;
            fast = fast->next->next;
        }

        ListNode *newTail = head;

        while (newTail->next != low) {
            auto newHead = newTail->next;
            newTail->next = newHead->next;
            newHead->next = head;
            head = newHead;
        }

    }
};