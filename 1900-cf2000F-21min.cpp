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
const int MaxN=1005;
int n,k,a[MaxN],b[MaxN],dp[MaxN][MaxN];
void solution()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<=n;i++)
		dp[i][0]=0;
	for(int j=1;j<=k;j++)
		dp[0][j]=1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			dp[i][j]=dp[i-1][j];
			int h=a[i],l=b[i],cost=0;
			for(int get=1;get<=a[i]+b[i];get++)
			{
				if(h>l)
				{
					cost+=l;
					h--;
				}
				else
				{
					cost+=h;
					l--;
				}
				dp[i][j]=min(dp[i][j],dp[i-1][max(0ll,j-get)]+cost);
			}
			// dp[i][j]=min(dp[i][j],dp[i-1][max(0ll,j-a[i]-b[i])]+a[i]*b[i]);
			// for(int l=0;l<a[i];l++)
			// 	dp[i][j]=min(dp[i][j],dp[i-1][max(0ll,j-l)]+l*b[i]);
			// for(int l=0;l<b[i];l++)
			// 	dp[i][j]=min(dp[i][j],dp[i-1][max(0ll,j-l)]+l*a[i]);
		}
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=k;j++)
	// 	{
	// 		cout<<dp[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	if(dp[n][k]==1e9)
		cout<<-1<<endl;
	else
		cout<<dp[n][k]<<endl;
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