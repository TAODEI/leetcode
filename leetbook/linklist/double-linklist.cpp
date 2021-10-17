#include <iostream>
using namespace std;

struct Node {
    Node *next, *prev;
    Node(int x) : Data(x), next(NULL), prev(NULL) {}
    int Data;
};

void ErrorMessage(string s) {
    cout << s << endl;
}

class DoubleLinkedList {
  public:
    DoubleLinkedList() {
        head = new Node(0);
        Len = 0;
    }

    int get(int index) {
        if (index < 0 || index >= Len) {
            ErrorMessage("索引越界!");
            return -1;
        }

        Node *p = head->next;
        for (int j = 0; j < index && p != NULL; j++) {
            p = p->next;
        }
        return p->Data;
    }

    void addAtHead(int val) {
        auto pnew = new Node(val);
        if (Len == 0) {
            head->next = pnew;
            pnew->prev = head;
            Len++;
            return;
        }
        pnew->next = head->next;
        head->next->prev = pnew;
        head->next = pnew;
        Len++;
    }

    void addAtTail(int val) {
        auto pnew = new Node(val);
        Node *p = head;
        for (int j = 0; j < Len && p != NULL; j++) {
            p = p->next;
        }
        p->next = pnew;
        pnew->prev = p;
        Len++;
        return;
    }

    void addAtIndex(int index, int val) {
        if (Len == index) {
            auto pnew = new Node(val);
            Node *p = head;
            for (int j = 0; j < Len && p != NULL; j++) {
                p = p->next;
            }
            p->next = pnew;
            pnew->prev = p;
            Len++;
            return;
        }
        if (index > Len) {
            ErrorMessage("索引越界!");
            return;
        }
        Node *p = head;
        for (int j = 0; j < index && p != NULL; j++) {
            p = p->next;
        }

        auto pnew = new Node(val);
        pnew->prev = p;
        pnew->next = p->next;
        pnew->next->prev = pnew;
        p->next = pnew;
        Len++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= Len) {
            ErrorMessage("索引越界!");
            return;
        }
        Node *p = head;
        for (int j = 0; j < index && p != NULL; j++) {
            p = p->next;
        }
        if (index == Len - 1) {
            delete p->next;
            p->next = nullptr;
            Len--;
            return;
        }
        p->next = p->next->next;
        delete p->next->prev;
        p->next->prev = p;
        Len--;
    }

    void Display() {
        for (Node *p = head->next; p != NULL; p = p->next) {
            cout << p->Data << " ";
        }
        cout << endl;
    }

  private:
    Node *head;
    int Len;
};

int main() {
    DoubleLinkedList *linkedList = new DoubleLinkedList();

    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2); //链表变为1-> 2-> 3
    cout << linkedList->get(1) << endl; //返回2
    linkedList->deleteAtIndex(1);       //现在链表是1-> 3
    cout << linkedList->get(1) << endl; //返回3
}