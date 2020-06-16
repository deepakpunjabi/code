/*
Micro just purchased a queue and wants to perform N operations on the queue. The operations are of following type:

E x: Enqueue x in the queue and print the new size of the queue.
D : Dequeue from the queue and print the element that is deleted and the new size of the queue separated by space. If there is no element in the queue then print 1 in place of deleted element.

Since Micro is new with queue data structure, he need your help.

Input:
First line consists of a single integer denoting N
Each of the following N lines contain one of the operation as described above.

Output:
For each enqueue operation print the new size of the queue. And for each dequeue operation print two integers, deleted element (1, if queue is empty) and the new size of the queue.

*/

// Write your code here
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
            // cout << "queue is empty" << endl;
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
            cout << 1;
        }
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
	int n;
	cin >> n;

	Queue q(n);
	for (int i=0; i<n; ++i) {
		char op;
		cin >> op;
		switch (op) {
			case 'E':
				int elem;
				cin >> elem;
				q.push(elem);
				cout << q.size() << endl;
				break;
			case 'D':
				cout << q.pop() << " " << q.size() << endl;
				break;
		}
	}
}
