#include <iostream>
using namespace std;

class MyCircularQueue {
  public:
    MyCircularQueue(int k) {
        size = k+1;
        elem = new int[size];
    }
    
    bool enQueue(int value) {
        if (!isFull()) {
            if (head == -1) {
                head++;
                tail++;
            }
            tail = (tail + 1) % size;
            elem[tail] = value;
            return true;
        } else {
            cout << "queue is full" << endl;
            return false;
        }
    }
    
    bool deQueue() {
        if (!isEmpty()) {
            head = (head + 1) % size;
            return true;
        } else {
            cout << "queue is empty" << endl;
            return false;
        }
    }
    
    int Front() {
        if (!isEmpty()) {
            return elem[(head+1) % size];
        } else {
            cout << "queue is empty" << endl;
            return -1;
        }
    }
    
    int Rear() {
        if (!isEmpty()) {
            return elem[tail];
        } else {
            cout << "queue is empty" << endl;
            return -1;
        }
    }
    
    bool isEmpty() {
        return head == tail; 
    }
    
    bool isFull() {
        return (tail+1) % size == head;
    }
    private:
    int size;
    int head = -1;
    int tail = -1;
    int *elem;
};


// Your MyCircularQueue object will be instantiated and called as such:
int main() {

    MyCircularQueue *circularQueue = new MyCircularQueue(6); // 设置长度为 3
    cout << circularQueue->enQueue(6) << endl; // 返回 true
    // cout << circularQueue->enQueue(2) << endl; // 返回 true
    // cout << circularQueue->enQueue(3) << endl; // 返回 true
    // cout << circularQueue->enQueue(4) << endl; // 返回 false，队列已满
    cout << circularQueue->Rear() << endl; // 返回 3
    cout << circularQueue->Rear() << endl; // 返回 3
    // cout << circularQueue->isFull() << endl; // 返回 true
    cout << circularQueue->deQueue() << endl; // 返回 true
    cout << circularQueue->enQueue(4) << endl; // 返回 true
    cout << circularQueue->Rear() << endl; // 返回 4

}
