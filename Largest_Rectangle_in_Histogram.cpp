//https://leetcode.com/problems/largest-rectangle-in-histogram/description/



// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:
// Input: heights = [2,4]
// Output: 4
//  Constraints:
// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

  
// Its a question of Monotonic Stack
// I found a better method to the problem


// The Other Method Using Vector instead of Stack

class Solution {
public:
#define ll long long
    int largestRectangleArea(vector<int>& heights) {
        ll n = heights.size();
        vector<ll> a(n) , b(n);
        vector<ll> v(n+1);
        for (int i = 0 ; i<n ;i++)
        {
            v[i] = i-1;
            while (v[i]>=0 && heights[v[i]]>=heights[i])
            {
                v[i] = v[v[i]];
            }
            ll ans = v[i];
            a[i] = (i-ans)*heights[i];
        }
        v.clear();
        for (int i = n-1 ; i>=0 ;i--)
        {
            v[i] = i+1;
            while (v[i]<n && heights[v[i]]>=heights[i])
            {
                v[i] = v[v[i]];
            }
            ll ans = v[i];
            b[i] = (ans-i)*heights[i];
        }
        ll m = 0;
        for (int i = 0 ; i<n ; i++)
        {
            m = max(m,a[i]+b[i] - heights[i]);
        }
        return m;
    }
};




// Monotonic Stack Approch
class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights,int n)
    {
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    stack<int> q;
    map<int,int> mp;
    vector<int> v;
    v.push_back(-1);
    for (int i = n-1 ; i>=0 ; i--)
    {
        while (s.top()>=heights[i])
        {
            s.pop();
            v.pop_back();
        }
        q.push(v[v.size()-1]);
        v.push_back(i);
        s.push(heights[i]);
    }
    while (!q.empty())
    {
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
    }


    vector<int> prvSmaller(vector<int>& heights,int n)
    {
          stack<int> s;
    s.push(-1);
    vector<int> ans;
    stack<int> q;
    map<int,int> mp;
    vector<int> v;
    v.push_back(-1);
    for (int i = 0 ; i<n ; i++)
    {
        while (s.top()>=heights[i])
        {
            s.pop();
            v.pop_back();
        }
        ans.push_back(v[v.size()-1]);
        v.push_back(i);
        s.push(heights[i]);
    }
    
    return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
       vector<int> a = prvSmaller(heights,n);
        vector<int> b = nextSmaller(heights,n);
        for (int i = 0 ;i<n ; i++)
        {
            if (a[i]==-1)
            {
                a[i] = -1;
            }
            if (b[i]==-1)
            {
                b[i] = n;
            }
        }
        int ans = 0;
        for (int i = 0 ;i<n ;i++)
        {
            int x = b[i]-a[i]-1;
            ans = max(ans,x*heights[i]);
        }
       return ans;
        
    }
};
