// You are given an array a consisting of n integers, and additionally an integer m. You have to choose some sequence of indices b1, b2, ..., bk (1 ≤ b1 < b2 < ... < bk ≤ n) in such a way that the value of  is maximized. Chosen sequence can be empty.

// Print the maximum possible value of .

// Input
// The first line contains two integers n and m (1 ≤ n ≤ 35, 1 ≤ m ≤ 109).

// The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109).

// Output
// Print the maximum possible value of .



// https://codeforces.com/contest/888/problem/E

//Author: MishiranuHito(見知らぬ人)

//..........................................................................
#include <bits/stdc++.h>
using namespace std;

// some short hands
//..........................................................................
#define ain(arr,n) for(int i = 0 ; i<n ; i++){ cin >> arr[i];}
#define aout(arr,n) for(int i = 0 ;i<n;i++){cout << arr[i]<<" ";}cout << endl;
#define srt(arr,n) sort(arr,arr+n);
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define int long long
#define MishiranuHito() auto begin = std::chrono::high_resolution_clock::now();ios_base::sync_with_stdio(false);
//..........................................................................

const long long MAXN = 2e6;
const long long MOD = 1e9 + 7;

long long fac[MAXN + 1];
long long inv[MAXN + 1];


/*................................................................................................................................................*/

// SOME IMPORTANT FUNCTIONS

long long exp(long long x, long long n, long long m) {
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

//..........................................................................

void factorial() {
    fac[0] = 1;
    for (long long i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}


//..........................................................................
int getBit(int num, int pos){
return (num & (1 << pos)) != 0;
}


//..........................................................................
void inverses() {
    inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
    for (long long i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

//..........................................................................

long long choose(long long n, long long r) { 
    if(r>n)return 0ll;
    return (fac[n] * inv[r] % MOD * inv[n - r] % MOD)%MOD; 
}

//..........................................................................

/* FUNCTIONS */
#define f(i,s,e) for(long long i=s;i<e;i++)
#define cf(i,s,e) for(long long i=s;i<=e;i++)
#define rf(i,e,s) for(long long i=e-1;i>=s;i--)

//..........................................................................

// SieveOfEratosthenes(FOR CHECKING PRIMES)
 bool prime[(long long)1e6 + 1];
 void SieveOfEratosthenes()
{
    long long n = 1e6;
    memset(prime, true, sizeof(prime));
    for (long long p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

//..........................................................................

// NUMBER TO BINARY
string bin(long long n,int q)
  {
    long long i;
    ll  mq = 1<<q-1;
    string s="";
    for (i = mq; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        s.push_back('1');
      }
      else
      {
        s.push_back('0');
      }
    }
    return s;
  }
//..........................................................................
  
  long long btll(string& binaryString) {
    long long result = 0;
    for (char bit : binaryString) {
        result <<= 1;
        if (bit == '1') {
            result |= 1;
        }
    }
    return result;
}
//..........................................................................
  
  // Function to calculate the Greatest Common Divisor (GCD)
ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//..........................................................................

// Function to calculate the Least Common Multiple (LCM)
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

//..........................................................................
// Function to set a specific bit at position 'pos' in an integer 'num'
long long setBit(long long num, long long pos) {
    return num | (1LL << pos);
}

//..........................................................................
// Function to clear a specific bit at position 'pos' in an integer 'num'
long long clearBit(long long num, long long pos) {
    return num & ~(1LL << pos);
}

//..........................................................................
// Function to count the number of set bits in an integer 'num'
long long countSetBits(long long num) {
    long long count = 0;
    while (num) {
        count+= num & 1;
        num >>= 1;
    }
    return count;
}

//..........................................................................
// Function to find the most significant bit (MSB) position in an integer 'num'
long long findMSB(long long num) {
    long long msb = 0;
    while (num > 1) {
        num >>= 1;
        msb++;
    }
    return msb;
}
//..........................................................................
map<long long, long long> gpf(long long n) {
    std::map<long long, long long> primeFactorsFreq;
    for (long long prime = 2; prime * prime <= n; prime++) {
        if (n % prime == 0) {
            long long count = 0;
            while (n % prime == 0) {
                n /= prime;
                count++;
            }
            primeFactorsFreq[prime] = count;
        }
    }
    if (n > 1) {
        primeFactorsFreq[n] = 1;
    }
    return primeFactorsFreq;
}
//..........................................................................


//..........................................................................
//...........................Jai Ma Durga...................................
//..........................................................................

void solve() {
    ll n,m;
    cin >> n >> m;
    ll arr[n];
    ain(arr,n);
    ll ans = INT_MIN;




  // meet in middle approch
    vector<int> a;
    vector<int> b;
    for (int i = 1 ; i<=1<<(n/2) ; i++)
    {
        string s = bin(i,(n/2));
        ll sum = 0;
        for (int j = 0  ;j<n/2 ;j++)
        {
            if (s[j]=='1')
            {
                sum += arr[j];
            }
        }
        sum = sum%m;
        a.push_back(sum);
    }

    for (int i=1 ; i<=(1<<(int)ceil((double)n/(2.0))) ; i++)
    {
        string s = bin(i,(int)ceil((double)n/(2.0)));
        ll sum = 0;
        for (int j = 0  ;j<(int)ceil((double)n/(2.0)) ;j++)
        {
            if (s[j]=='1')
            {
                sum += arr[j+(n/2)];
            }
        }
        sum = sum%m;
        b.push_back(sum);
    }




  
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    for(auto i:a)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i:b)
    {
        cout << i << " ";
    }
    cout << endl;
    int e = b.size();
    for (auto i:a)
    {
        int p = m-i-1;
        int x = upper_bound(b.begin() , b.end() , p) - b.begin();
        x--;
        if (x>=0 && x<e)
        ans = max(ans,(i+b[x])%m);
    }
    cout << ans <<  endl;
}


//..........................................................................
//..........................................................................
//..........................................................................
//..........................................................................

int32_t main() {
    // Jai Ma Durga
    MishiranuHito()
    //SieveOfEratosthenes();
    //factorial();
    //inverses();
        solve();
    
}
