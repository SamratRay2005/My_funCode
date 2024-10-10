// https://codeforces.com/contest/1603/problem/A

// we we cannot even delete for one index before the actual then we cannot delete it as the i+1 th position can only be decresed be deleting elemenent 
// before this so if it get deleted then it will be by all the index before of = to its own index

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ain(arr,n);
    ll l = 2;
    for (int i = 0 ; i<n ; i++)
    {
        l = lcm(l,i+2);
        if (l>1e9)
        {
            break;
        }
        if (arr[i]%l==0)
        {
            NO
            return;
        }
    }
    YES
}
