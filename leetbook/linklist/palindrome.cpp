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
        // 快慢指针找出中点
        auto fast = head->next, slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto middle = slow->next;

        // 将前一半倒序
        slow->next = nullptr;

        ListNode *newTail = head;

        while (newTail->next) {
            auto newHead = newTail->next;
            newTail->next = newHead->next;
            newHead->next = head;
            head = newHead;
        }

        if (fast->next) { // 节点个数为奇数
            middle = middle->next;
        }
        
        // 比较
        while (head->val == middle->val) {
            head = head->next;
            middle = middle->next;
            if (!slow) {
                return true;
            }
        }
        return false;
    }
};