/*
ANALYSIS:

*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ctime>
#include <random>
#define int long long
#define i32 signed
#define endl '\n'
using namespace std;
const int MaxN=200005;
map<int,set<int> > mp;
int n,m,a[MaxN],b[200];
string s;
void solution()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int qi=1;qi<=m;qi++)
	{
		cin>>s;
		if(s.size()!=n)
		{
			cout<<"NO"<<endl;
			continue;
		}
		mp.clear();
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		{
			if(mp[a[i]].size()==0&&b[s[i]]==0||mp[a[i]].size()!=0&&mp[a[i]].find(s[i])!=mp[a[i]].end())
			{
				mp[a[i]].insert(s[i]);
				b[s[i]]=1;
			}
			else
			{
				cout<<"NO"<<endl;
				goto out;
			}
		}
		cout<<"YES"<<endl;
		out:;
	}
}

i32 main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//preprocess();
	int T=1;
	cin>>T;
	while(T--)
	{
		solution();
	}
	return 0;
}