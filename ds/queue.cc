
using namespace std;

class Queue {
    int front, rear;
    int capacity;
    int *arr;

    Queue(int x) : front(-1), rear(-1), capacity(x) {
        arr = new int[x];
    }
    ~Queue() {
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

    int front() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};