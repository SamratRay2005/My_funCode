/*  Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.

Implement the following public functions :
1. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

2. pop() :
It pops the element from the top of the stack and returns nothing.

3. top() :
It returns the element being kept at the top of the stack.

4.  getMin() :
It returns the smallest element present in the stack. */





#include <stack>
class SpecialStack {
    public:
        stack<int> s;
        int mini;
    void push(int data) {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else{
            int val = data;
            if (data<mini)
            {
                val = 2*data - mini; // mini is the previous min
                mini = data;  // mini became data;
            }
            s.push(val);
        }
    }

    void pop() {
        if (!s.empty())
        {
        if (s.top() <= mini){
            if (s.top()<mini){
            int o = 2*mini - s.top();  // mini had became cur data so 2*data - (2*data - prv_min) => prv_min
            mini = o;}
        }
        s.pop();
        }
    }

    int top() {
        if (!s.empty())
       {
           if(s.top()<mini)
           {
               return mini;
           }
           else{
               return s.top();
           }
       }
       else{
           return -1;
       }
    }

    int getMin() {
        return mini;
    }  
};
