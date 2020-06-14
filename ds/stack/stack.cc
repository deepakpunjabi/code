#include <iostream>

using namespace std;

class Stack {
    // this is not safe as arr+x location can be alloted to some variable
    // better use dedicated space using linked list or vector
    // EDIT: not as such because we are allocating memory using new

    // data store
    int *arr;
    // stores location of current top element
    int top;
    // limit on how much data we can store
    int capacity;

   public:
    // improved variable name in constructor
    Stack(int cap) : top(-1), capacity(cap) {
        arr = new int[cap];
    }
    ~Stack() {
        delete arr;
    }

    // in c/cpp you cannot have function name and variable name same.
    // as both of them can be address using pointer, &top will not know
    // if to call method or member
    int getTop() {
        // Doesn't matter as if stack is empty arr[top] will still return -1
        // if (top == -1) return -1;
        return arr[top];
    }

    // changed x to elem
    int push(int elem) {
        if (isFull()) return -1;
        // ++top;
        arr[++top] = elem;
        return top;
    }

    void pop() {
        if (isEmpty()) return;
        // reset the data
        arr[top] = 0;
        --top;
    }

    bool isEmpty() {
        return top == -1;
    }

    // had made a mistake here writing full is top = capacity
    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    int n = 5;

    Stack s(n);
}
