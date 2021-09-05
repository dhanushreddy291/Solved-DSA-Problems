#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack <int> Stack;
    int Minimum;
public:
    
    MinStack() {
        while (!Stack.empty())
            Stack.pop();
    }
    
    void push(int val) {
        if (Stack.empty()) {
            Stack.push(val);
            Minimum = val;
        } else if (val < Minimum) {
            Stack.push(val + (val - Minimum));
            Minimum = val;
        } else {
            Stack.push(val);
        }
    }
    
    void pop() {
        if (Stack.top() < Minimum)
        Minimum += (Minimum - Stack.top());
        Stack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return Minimum;
    }
};

int main()
{
    
    return 0;
}