class MyStack {
public:
    queue <int> Queue1, Queue2, *Orig, *Temp, *K;
    MyStack() {
        while (!Queue1.empty()) Queue1.pop();
        while (!Queue2.empty()) Queue2.pop();
        Orig = &Queue1;
        Temp = &Queue2;
    }
    
    void push(int x) {
        if (Orig -> empty() && !Temp -> empty()) {
            while (!Temp -> empty()) {
                Orig -> push (Temp -> front());
                Temp -> pop();
            }
        }
        Orig -> push(x);
    }
    
    int pop() {
        while (Orig -> size() > 1) {
            Temp -> push (Orig -> front());
            Orig -> pop();
        }
        int t = Orig -> front();
        Orig -> pop();
        K = Orig;
        Orig = Temp;
        Temp = K;
        return t;
    }
    
    int top() {
        int t = this -> pop();
        Orig -> push (t);
        return t;
    }
    
    bool empty() {
        return (Queue1.empty() && Queue2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */