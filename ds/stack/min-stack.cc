/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> mst;
    
    MinStack() {

    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            mst.push(x);
        } else {
            st.push(x);
            mst.push(min(x, mst.top()));
        }
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
