// N STACK IN AN ARRAY PROBLEM
// by using a single array we have to look of to n stacks and access the values of any of them if asked for.


#include <bits/stdc++.h> 
class NStack
{
    int* arr;
    int* top;
    int* next;
    int n,s;
    int freespot;
public:


// we basically add every element of the array continuously rather than dividing the stack equally. Its better in space complexity
// we make 3 array arr(for storing the data) ,top (for stoing the top element) , next(for finding the next empty storage & for keeping the track of the previous element of the-
// -specific sequence). For example in next we after traversing a perticular index we put the precious top index there. So when we backtrack during pop we can just follow each lead of index of next to reach the result. 

    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
       arr = new int[s];
       top = new int[n];
       next = new int[s];
       for (int i = 0 ;i<n ;i++)
       {
           top[i] = -1;
       }
       for (int i = 0 ;i<s ;i++)
       {
           next[i] = i+1;
       }
       next[s-1] = -1;
       freespot = 0;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m-1];
        top[m-1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m-1]==-1)
        {
            return -1;
        }
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
