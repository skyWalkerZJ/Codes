#include <stack>
#include <iostream>
using namespace std;
class MinStack {
public:
    stack<int> mainStack;
    stack<int> helpStack;
    MinStack() {
        helpStack.push(INT_MAX);
    }
    
    void push(int val) {
        mainStack.push(val);
        helpStack.push(min(val,helpStack.top()));
    }
    
    void pop() {
        if(!mainStack.empty())
        {
            mainStack.pop();
            helpStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return helpStack.top();
    }
};