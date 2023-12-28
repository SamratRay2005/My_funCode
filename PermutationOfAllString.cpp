#include <bits/stdc++.h>
using namespace std;
void perp(string s , int n , string ns)
{	
	if (n==0)
	{
		cout << ns << endl;
		return;
	}
	for (int i  = 0; i<n ; i++)
	{
		ns.push_back(s[i]);
		string newstring = "";
		for (int j = 0 ;j<n ;j++)
		{
			if (j!=i)
			{
				newstring.push_back(s[j]);
			}
		}

		perp(newstring,n-1,ns);
		ns.pop_back();
	}
}
int main ()
{
	string s;
	cin >> s;
	int n = s.size();
	 perp(s,n,"");
	return 0;
}