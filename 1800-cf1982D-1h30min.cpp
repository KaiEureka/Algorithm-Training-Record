#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <list>
#define int long long
#define i32 signed
using namespace std;
inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
int n,m,k,a[505][505],l[505][505],sum,nowgcd;
string s[505];
void initilization()
{
	sum=0;
}

void solution()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			l[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i-1][j-1]=='0')sum-=a[i][j];
			else sum+=a[i][j];
		}
	}
	if(sum==0)
	{
		cout<<"YES"<<endl;
		return;
	}
	nowgcd=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-k+1;j++)
		{
			for(int jj=j;jj<=j+k-1;jj++)
				if(s[i-1][jj-1]=='1')
					l[i][j]++;
				else
					l[i][j]--;
		}
	}
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=1;j<=m-k+1;j++)
		{
			// int tsum=0;
			// for(int ii=i;ii<=i+k-1;ii++)
			// {
			// 	for(int jj=j;jj<=j+k-1;jj++)
			// 	{
			// 		if(s[ii-1][jj-1]=='1')
			// 			tsum++;
			// 		else
			// 			tsum--;
			// 	}
			// }
			int tsum=0;
			for(int ii=i;ii<=i+k-1;ii++)
				tsum+=l[ii][j];
			if(tsum!=0)
			{
				if(tsum<0)tsum=-tsum;
				if(nowgcd==0)nowgcd=tsum;
				else nowgcd=gcd(nowgcd,tsum);
			}
			if(nowgcd!=0&&sum%nowgcd==0)
			{
				cout<<"YES"<<endl;
				return;
			}
			
		}
	}
	cout<<"NO"<<endl;
	return;
}

i32 main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)
	{
		initilization();
		solution();
	}
	return 0;
}
