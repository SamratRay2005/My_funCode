#include <bits/stdc++.h>
using namespace std;
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

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)

int main() 
{
    int t;
    cin >> t;
    while(t-->0)
    {
        int n , q;
        cin >> n >> q;
        string s;
        cin >> s;
        int m = 0;
        int c = 1;
        char cmax = s[0];
        for (int i = 1 ; i<n ; i++)
        {
            if (s[i]==s[i-1])
            {
                c++;
            }
            else
            {
                if (c>m)
                {
                    m = c;
                    cmax = s[i-1];
                }
                c = 1;
            }
        }
      // c also contain the last frequency which is not taken into as it never became unequal
        if (c>m)
        {
            m = c;
            cmax = s[n-1];
        }
        cout << m << " ";
        for (int i = 0 ; i<q ; i++)
        {
            char a;
            cin >> a;
            n = s.size();
            if (a==s[n-1])
            {
                c++;
            }
            else
            {
                c = 1;
            }
            if (c>m)
            {
                m = c;
            }
            s.push_back(a);
            cout << m << " ";
        }
        cout << endl;
    }
}
