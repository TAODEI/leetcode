#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代
class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if(head == NULL){
            return head;
        }
        auto node = new ListNode(-1, head);
        auto tmp = node;
        while(tmp->next != NULL){
            if(tmp->next->val == val){
                tmp->next = tmp->next->next;
            }else{
                tmp = tmp->next;
            } 
        }
        return node->next;
    }
};

// 递归
class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if(head == NULL){
            return NULL;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
