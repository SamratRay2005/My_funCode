// USE OF 2D DP


// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

// https://leetcode.com/problems/coin-change-ii/description/





class Solution {
public:
int dp[310][(int)1e4+1];
int solve(int id ,int a, vector<int>& coins)
{
    if (a==0)
    {
        return 1;
    }
    if (id<0)
    {
        return 0;
    }
    if (dp[id][a]!=-1)
    {
        return dp[id][a];
    }
    
    int m = 0;
    
    for (int i = 0 ;i<=a ;i += coins[id])
    {
        m += (solve(id-1 ,a-i, coins));
    }
    return dp[id][a]=m;
}
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins.size()-1,amount,coins);
        return ans;
    }
};
