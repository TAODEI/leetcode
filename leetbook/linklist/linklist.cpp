#include <iostream>
using namespace std;

class MyLinkedList {
  public:
    struct node {
        int val;
        node *next;
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new node;
        len = 0;
        head->next = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= len || index < 0) {
            return -1;
        }
        node *tmp = head->next;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *newNode = new node;
        newNode->val = val;
        newNode->next = head->next;
        head->next = newNode;
        len++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *tailNode = head;

        for (int i = 0; i < len; i++) {
            tailNode = tailNode->next;
        }

        node *newNode = new node;
        newNode->val = val;
        newNode->next = tailNode->next;
        
        tailNode->next = newNode;
        
        len++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If
     * index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node *preNode = head, *newNode = new node;
        if (index > len) {
            cout << 22222;
            return;
        } else if (index < 0) {
            cout << 1111111;
            addAtHead(val);
        } else if (index == len) {
            addAtTail(val);
            cout << 22222;
        } else {
            for (int i = 0; i < index; i++) {
                preNode = preNode->next;
            }
            newNode->val = val;
            newNode->next = preNode->next;
            preNode->next = newNode;
            len++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index > len) {
            return;
        }
        node *Node = head;
        for (int i = 0; i < index; i++) {
            Node = Node->next;
        }
        // node *next = Node;
        // Node->next = next->next;
        Node->next = Node->next->next;
    }
    void show() {
        node *Node = head;
        while (Node->next != NULL) {
            Node = Node->next;
            cout << Node->val << " ";
        }
        cout << "len:" << len << endl;
    }

  private:
    int len;
    node *head;
};
int main() {
    MyLinkedList linkedList = MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);
    linkedList.show();
    // linkedList.deleteAtIndex(1);
    // linkedList.show();
}