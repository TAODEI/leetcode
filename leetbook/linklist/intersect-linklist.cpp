#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution { // Solution1 violent
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }

        while (1) {
            ListNode *q = headB;
            while (1) {
                if (headA == q) {
                    return headA;
                }
                if (!q->next) {
                    break;
                }
                q = q->next;
            }
            if (!headA->next) {
                break;
            }
            headA = headA->next;
        }
        return NULL;
    }
};

// typedef ListNode Node;
// class Solution { // Solution2 wrong
//   public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if (!headA || !headB) {
//             return NULL;
//         }
//         ListNode *q = headA, *p = headB;
//         while (q->next != NULL) {
//             q = q->next;
//         }
//         while (p->next != NULL) {
//             p = p->next;
//         }
//         if (p == q) {
//             Node *_1, *_2;
//             while (_1 == _2) {
//                 GetPriorElem(headA, *q, *_1);
//                 GetPriorElem(headB, *p, *_2);
//             }
//             return _1->next;
//         }
//         return NULL;
//     }

//     // get 前驱, return state code
//     int GetPriorElem(ListNode *head, Node cut_e, Node &pre_e) {
//         if (head->next == NULL) {
//             return 1;
//         }

//         Node *p = head;
//         while (p->next != NULL) {
//             if (cut_e.val == p->next->val) {
//                 pre_e = *p;
//                 return 0;
//             }
//             p = p->next;
//         }
//         return 1;
//     }
// };