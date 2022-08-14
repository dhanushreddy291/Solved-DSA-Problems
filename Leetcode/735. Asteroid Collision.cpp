class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int N = asteroids.size(), i = 0;
        vector <int> finalState;
        stack <int> Stack;
        while (i < N) {
            if (Stack.empty()) {
                if (asteroids[i] < 0) finalState.push_back(asteroids[i++]);
                else Stack.push(asteroids[i++]);
            } else {
                if (asteroids[i] > 0) {
                    Stack.push(asteroids[i]);
                } else {
                    while (!Stack.empty() && Stack.top() < abs(asteroids[i])) {
                        Stack.pop();
                    }
                    if (!Stack.empty() && Stack.top() <= asteroids[i]) {
                        if (Stack.top() == abs(asteroids[i])) Stack.pop();
                        i++;
                    }
                }
            }
        }
        vector <int> stackElems;
        while (!Stack.empty()) {
            stackElems.push_back(Stack.top());
            Stack.pop();
        }
        int M = stackElems.size();
        for (int i = M - 1; i >= 0; i--) {
            finalState.push_back(stackElems[i]);
        }
        return finalState;
    }
};