#include <stack>
using namespace std;
class CQueue {
public:
    //用两个栈实现队列
    stack<int> inStack,outStack;//输入栈和输出栈
    CQueue() {

    }
    
    void appendTail(int value) {
        inStack.push(value);
    }
    int inToOut()//将输入栈的数据导入到输出栈
    {
        while(!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
        return outStack.size();
    }
    int deleteHead() {
        int ans=-1;
        if(!outStack.empty())
        {
            ans=outStack.top();
            outStack.pop();
        }else{
            if(inToOut()==0) return ans;
            ans=outStack.top();
            outStack.pop();    
        }
        return ans;
    }
};