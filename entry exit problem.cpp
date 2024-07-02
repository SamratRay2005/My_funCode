// There are n projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day.
// What is the maximum amount of money you can earn?
// Input
// The first input line contains an integer n: the number of projects.
// After this, there are n lines. Each such line has three integers a_i, b_i, and p_i: the starting day, the ending day, and the reward.
// Output
// Print one integer: the maximum amount of money you can earn.
// Constraints

// Example
// Input:
// 4
// 2 4 4
// 3 6 6
// 6 8 2
// 5 7 3

// Output:
// 7
//https://cses.fi/problemset/task/1140/

// note the process #standard
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}
void solve() {
    ll n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(3));
    for  (int i = 0 ; i<n ; i++)
    {
        cin >> arr[i][0] >>  arr[i][1] >>  arr[i][2];
    }
    sort(all(arr),cmp);
    // sortv(arr);
    set<pair<int,int>> dp;
    dp.insert({0,0});
    ll ans = 0;
    for (int i = 0 ;i<n ; i++)
    {
        auto it = dp.lower_bound({arr[i][0],0});
        --it;
        ans = max(ans, it->ss + arr[i][2]);
        dp.insert({arr[i][1],ans});
    }
    cout << ans << endl;
}
