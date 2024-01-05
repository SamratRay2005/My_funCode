#include <bits/stdc++.h>
using namespace std;
int num(char c)
    {
        if (c=='I')
        return 1;
        else if (c=='V')
        return 5;
        else if (c=='X')
        return 10;
        else if (c=='L')
        return 50;
        else if (c=='C')
        return 100;
        else if (c=='D')
        return 500;
        else if (c=='M')
        return 1000;

        return 0;
    }

    int main() {
        string s;
        cin >> s;
        int ans=0;
        int i = s.size()-1;
        char prv = s[i];
        while (i>=0)
        {
            if (num(s[i])<num(prv) && num(s[i])==1)
            {
                ans = ans - num(s[i]);
            }
            else{
                if (num(s[i])<num(prv))
                {
                    ans = ans - num(s[i]);
                    if (i-1>=0)
                    prv = s[i-1];
                }  
                else{
                    ans = ans + num(s[i]);
                    prv = s[i];
                }
          }
          i--;        
        }
        cout << ans<<endl;
    }
