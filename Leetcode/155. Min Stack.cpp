class MinStack {
    
private:
    stack <int> Stack;
    int Min;

public:
    MinStack() {
        while (!Stack.empty()) {
            Stack.pop();
        }
        Min = INT_MAX;
    }
    
    void push(int val) {
        if (Stack.empty()) {
            Stack.push(val);
            Min = val;
        } else if (val > Min) {
            Stack.push(val);
        } else {
            Stack.push(Min);
            Min = val;
            Stack.push(val);
        }
    }
    
    void pop() {
        int Top = Stack.top();
        if (Top == Min) {
            Stack.pop();
            Min = Stack.top();
        }
        Stack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return Min;
    }
};