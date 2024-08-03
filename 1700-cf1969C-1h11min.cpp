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
const int MaxN=300005;
int n,k,a[MaxN],sum[MaxN],ans,dp[MaxN][15],amin[MaxN][15],len,tamin;
void solution()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum[0]=0;
	sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	ans=0;
	for(int j=0;j<=k;j++)
	{
		dp[0][j]=dp[1][j]=0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int i=2;i<=n;i++)
	{
		for(len=2;len-1<=k&&i-len+1>=1;len++)
		{
			tamin=1e9;
			for(int p=i-len+1;p<=i;p++)
			{
				tamin=min(tamin,a[p]);
			}
			amin[i][len]=tamin;
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=2;i<=n;i++)
		{
			//cout<<"computing dp["<<i<<"]["<<j<<"]"<<endl;
			dp[i][j]=dp[i-1][j];
			for(int len=2;i-len>=0&&j-len+1>=0;len++)
			{
				// int oamin=1e9;
				// for(int p=i-len+1;p<=i;p++)
				// {
				// 	oamin=min(oamin,a[p]);
				// }
				// cout<<oamin<<' '<<i<<' '<<len<<' '<<amin[i][len]<<endl;
				//cout<<"len="<<len<<" amin="<<amin<<endl;
				dp[i][j]=max(dp[i][j],dp[i-len][j-len+1]+sum[i]-sum[i-len]-len*amin[i][len]);
				//cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
			}
		}
	}
	// cout<<"DP"<<endl;
	// for(int j=1;j<=k;j++)
	// {
	// 	for(int i=1;i<=n;i++)
	// 		cout<<dp[i][j]<<' ';
	// 	cout<<endl;
	// }
	cout<<sum[n]-dp[n][k]<<endl;
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

// while(k--)
	// {
	// 	tans=0;
	// 	for(int i=1;i<n;i++)
	// 	{
	// 		if(ban[i]==1||ban[i+1]==1)continue;
	// 		if(a[i]>a[i+1])
	// 		{
	// 			if(((a[i]-a[i+1])*b[i])>tans)
	// 			{
	// 				tans=(a[i]-a[i+1])*b[i];
	// 				xue=i+1;
	// 				beixue=i;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			if(((a[i+1]-a[i])*b[i+1])>tans)
	// 			{
	// 				tans=(a[i+1]-a[i])*b[i+1];
	// 				xue=i;
	// 				beixue=i+1;
	// 			}
	// 		}
	// 	}
	// 	ans+=tans;
	// 	b[xue]=b[beixue]+1;
	// 	if(beixue<xue)
	// 		for(int j=beixue;j>=beixue-b[beixue]+1;j--)
	// 			a[j]=a[xue];
	// 	else
	// 		for(int j=beixue;j<=beixue+b[beixue]-1;j++)
	// 			a[j]=a[xue];
	// 	//cout<<xue<<" "<<beixue<<endl;
	// }
	// cout<<sum-ans<<endl;
