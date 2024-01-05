#include<bits/stdc++.h>
using namespace std;
  void solve(vector<vector<int>> &m, int n,int x,int y,string s,vector<string> &v,vector<vector<int>> visited)
    {
        if (x==n-1 && y==n-1)
        {
            v.push_back(s);
            return;
        }
        if (x<0 || x>=n || y<0 || y>=n || m[x][y]==0)
        {
            return;
        }
        if (visited[x][y]==1)
        {
            return;
        }
        visited[x][y] = 1;
        
        
         //right
         if (y+1<n && m[x][y+1]==1)
         {
                 s.push_back('R');
                 solve(m,n,x,y+1,s,v,visited);
                 s.pop_back();
           
            
         }
         //left
         if (y-1>=0 && m[x][y-1]==1){
         
             
                 s.push_back('L');
                 solve(m,n,x,y-1,s,v,visited);
                 s.pop_back();
            
         }
         //down
         if (x+1<n && m[x+1][y]==1)
         {
                 s.push_back('D');
                 solve(m,n,x+1,y,s,v,visited);
                 s.pop_back();
          
         }
         // up
         if (x-1>=0 && m[x-1][y]==1)
         {
             
                 s.push_back('U');
                 solve(m,n,x-1,y,s,v,visited);
                 s.pop_back();
        
         }
    }
    int main()
    {
    	vector<vector<int>> m;
    	int n;
    	cin >> n;
    	for (int i = 0 ;i<n ;i++)
    	{
    		vector<int> v;
    		for (int j =0 ;j<n ;j++)
    		{
    			int a;
    			cin >> a;
    			v.push_back(a);
    		}
    		m.push_back(v);
    	}
    	 vector<vector<int>> visited = m;
        for (int i = 0 ;i<n ;i++)
        {
            for (int j = 0 ;j<n ;j++)
            {
                visited[i][j] = 0;
            }
        }
    	vector<string> v;
    	solve(m,n,0,0,"",v,visited);
    	for (auto i:v)
    	{
    		cout <<i <<endl;
    	}

    }
