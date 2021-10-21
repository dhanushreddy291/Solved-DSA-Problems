class MyQueue {
public:
    stack <int> Stack1, Stack2;
    MyQueue() {
        while (!Stack1.empty()) Stack1.pop();
        while (!Stack2.empty()) Stack2.pop();
    }
    
    void push(int x) {
        if (Stack1.empty() && !Stack2.empty()) {
            while (!Stack2.empty()) {
                Stack1.push(Stack2.top());
                Stack2.pop();
            }
        }
        Stack1.push(x);
    }
    
    int pop() {
        while (!Stack1.empty()) {
            Stack2.push(Stack1.top());
            Stack1.pop();
        }
        int t = Stack2.top();
        Stack2.pop();
        return t;
    }
    
    int peek() {
        int t = this -> pop();
        Stack2.push(t);
        return t;
    }
    
    bool empty() {
        return (Stack1.empty() && Stack2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */