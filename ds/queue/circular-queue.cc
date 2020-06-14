#include <iostream>

using namespace std;

class CQueue {
    int *arr;
    int front, rear;
    int capacity;
    // main trick in circular queue is to rely on maintain size whenever you
    // insert or delete element. Use this to figure out if queue is empty or full.
    int size;

   public:
    CQueue(int cap) : front(0), rear(-1), size(0), capacity(cap) {
        arr = new int[cap];
    }
    ~CQueue() {
        delete arr;
    }

    void push(int elem) {
        if (isFull()) {
            cout << "queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = elem;
        ++size;
    }

    int pop() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        }
        int res = arr[front];
        front = (front + 1) % capacity;
        // do not forget to maintain size.
        --size;
        return res;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void print() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        if (front <= rear) {
            for (int i = front; i <= rear; ++i) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; ++i) {
                cout << arr[i] << " ";
            }
            for (int i = rear; i < front; ++i) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    CQueue q(1);
    q.print();
    q.push(1);
    q.push(2);
    q.print();
    cout << "popping --> " << q.pop() << endl;
    q.print();
    cout << "popping --> " << q.pop() << endl;
    cout << q.pop() << endl;
    cout << "pushing 3" << endl;
    q.push(3);
    cout << "printing 3" << endl;
    q.print();
    cout << "popping --> " << q.pop() << endl;
    q.print();
}
