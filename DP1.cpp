// You are given an integer 𝑛
// . You have to apply 𝑚
//  operations to it.

// In a single operation, you must replace every digit 𝑑
//  of the number with the decimal representation of integer 𝑑+1
// . For example, 1912
//  becomes 21023
//  after applying the operation once.

// You have to find the length of 𝑛
//  after applying 𝑚
//  operations. Since the answer can be very large, print it modulo 1e9+7

// https://codeforces.com/contest/1513/problem/C

ll d[10][2*((int)1e5)];
void sol()
{
    for (int i = 0 ;i<10 ; i++)
    {
        d[i][0] = 1;
    }
    for (int i = 1 ;i<=2*((int)1e5) ; i++){
   for (int j = 0; j<=8 ; j++)
   {
    d[j][i] = d[j+1][i-1]%MOD;
   }
   d[9][i] = (d[1][i-1]%MOD + d[0][i-1]%MOD)%MOD;
    }
}

void solve() {
    ll ans = 0;
    ll n,m;
    cin >> n >> m;
    while(n>0)
    {
        ans += d[n%10][m];
        ans = ans%MOD;
        n /= 10;
    }
    cout << ans << endl;
}
