https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Basically if revisit the node that is present int the current DFS route then a Cycle is present.
#include <bits/stdc++.h>
bool dfs(int node , set<int> &v ,map<int , vector<int>> &mp , set<int> &cv)
{
  cv.insert(node);
  v.insert(node);
  for (auto i:mp[node])
  {
    if (!v.count(i))
    {
      if (dfs(i,v,mp,cv))
      return true;
    }
    else if (cv.count(i))
    return true;
    
  }
  cv.erase(node);
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  map<int , vector<int>> mp;
  for (auto i:edges)
  {
    mp[i.first].push_back(i.second);
  }
  set<int> v , cv;
  for (int i = 1 ; i<=n ;i++)
  {
    for (auto j:mp[i])
    {
      if (!v.count(j))
      {
        if (dfs(j,v,mp,cv))
        {
          return true;
        }
      }
    }
  }
  return false;
}
