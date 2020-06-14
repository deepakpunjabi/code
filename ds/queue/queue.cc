#include <iostream>

using namespace std;

class Queue {
    int *arr;
    int front, rear;
    int capacity;

   public:
    Queue(int cap) : capacity(cap), front(0), rear(-1) {
        arr = new int[cap];
    }
    ~Queue() {
        delete arr;
    }

    void push(int elem) {
        return enqueue(elem);
    }

    int pop() {
        return dequeue();
    }

    void enqueue(int elem) {
        if (isFull()) {
            cout << "queue is full" << endl;
            return;
        }
        arr[++rear] = elem;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[front++];
    }

    int getCapacity() {
        return capacity;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return front > rear;
    }

    int getFrontElem() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRearElem() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    int size() {
        if (isEmpty()) return 0;
        // because rear will also have the element
        return rear - front + 1;
    }

    void print() {
        if (isEmpty()) {
            cout << "queue is empty";
        }
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.print();
    q.push(1);
    q.push(2);
    cout << "front --> " << q.getFrontElem() << endl;
    cout << "rear --> " << q.getRearElem() << endl;
    q.print();
    cout << "popping --> " << q.pop() << endl;
    q.print();
    cout << "front --> " << q.getFrontElem() << endl;
    cout << "rear --> " << q.getRearElem() << endl;
    cout << "popping --> " << q.pop() << endl;
    cout << q.pop() << endl;
    cout << "pushing 3" << endl;
    q.push(3);
    cout << "printing 3" << endl;
    q.print();
    cout << "front --> " << q.getFrontElem() << endl;
    cout << "rear --> " << q.getRearElem() << endl;
    cout << "popping --> " << q.pop() << endl;
    cout << "front --> " << q.getFrontElem() << endl;
    cout << "rear --> " << q.getRearElem() << endl;
    q.print();
}

class QueueV1 {
    int front, rear;
    int capacity;
    int *arr;

    QueueV1(int x) : front(-1), rear(-1), capacity(x) {
        arr = new int[x];
    }
    ~QueueV1() {
        delete arr;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // enqueue
    int push(int x) {
        if (isFull()) return -1;
        if (isEmpty()) {
            // initialize
            front = rear = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        return rear;
    }

    // dequeue
    void pop() {
        if (isEmpty()) return;
        if (front == rear) {
            // de-initialize
            front = rear = -1;
        }
        front = (front + 1) % capacity;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};
