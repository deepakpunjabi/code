#include <vector>

using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;

   public:
    Stack(int x) : top(-1), capacity(x) {
        arr = new int[x];
    }
    ~Stack() {
        delete arr;
    }

    int top() {
        if (top == -1) return -1;
        return arr[top];
    }

    int push(int x) {
        if (top == capacity) return -1;
        ++top;
        arr[top] = x;
        return top;
    }

    void pop() {
        if (top == -1) return;
        arr[top] = 0;
        --top;
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    int n = 5;
    
    Stack s(n);
}