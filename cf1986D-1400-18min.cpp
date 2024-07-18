#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#define int long long
using namespace std;

string s;
int n;
int a[100];

void solution()
{
	cin>>n;
	cin>>s;
	int ans=1e9;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(j<i)
				a[j]=s[j-1]-'0';
			else if(j==i)
				a[j]=(s[j-1]-'0')*10+(s[j+1-1]-'0');
			else
				a[j]=s[j+1-1]-'0';
		}
		//for(int j=1;j<n;j++)cout<<a[j]<<' ';cout<<endl;
		for(int j=1;j<n;j++)
			if(a[j]==0)
			{
				ans=0;
					break;
			}
		int tans=0;
		for(int i=1;i<n;i++)
			if(a[i]!=1)
				tans+=a[i];
		if(tans==0)tans++;
		ans=min(ans,tans);
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
		solution();
	return 0;
}
