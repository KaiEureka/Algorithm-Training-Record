//我的做法非正解， 正解是b1b2数组计算前缀和，早该想到的，任何轮流访问来计总数或者轮流访问另一个数组来计算该数组的值具体值，都可以用前缀和来解决
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
#define endl '\n'
using namespace std;

int n,q,l,r,ans,b1[200],b2[200],b1f[2005][200],b2f[2005][200];
string a,b;

void input()
{

}
void initilization()
{

}
void solution()
{
	cin>>n>>q;
	cin>>a>>b;
	a=' '+a;
	b=' '+b;
	for(int i=0;i<(n/100+1);i++)
	{
		for(int j='a';j<='z';j++)b1f[i][j]=b2f[i][j]=0;
		for(int j=i*500+1;j<=min(n,(i+1)*500);j++)
		{
			b1f[i][a[j]]++;
			b2f[i][b[j]]++;
		}
	}
	//pl=pr=0;
	for(int i=1;i<=q;i++)
	{
		ans=0;
		for(int j='a';j<='z';j++)b1[j]=b2[j]=0;
		cin>>l>>r;
		if(r-l<=500)
		{
			for(int j=l;j<=r;j++)
			{
				b1[a[j]]++;
				b2[b[j]]++;
			}
			for(int j='a';j<='z';j++)
			{
				ans+=abs(b1[j]-b2[j]);
			}
		}
		else
		{
			for(int j=l;j<=l/500*500+500;j++)
			{
				b1[a[j]]++;
				b2[b[j]]++;
			}
			for(int j=l/500+1;j<r/500;j++)
			{
				for(int k='a';k<='z';k++)
				{
					b1[k]+=b1f[j][k];
					b2[k]+=b2f[j][k];
				}
			}
			for(int j=r/500*500+1;j<=r;j++)
			{
				b1[a[j]]++;
				b2[b[j]]++;
			}
			for(int j='a';j<='z';j++)
			{
				ans+=abs(b1[j]-b2[j]);
			}
		}
		cout<<ans/2<<endl;
		//pl=l,pr=r;
	}
}

i32 main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)
	{
		input();
		initilization();
		solution();
	}
	return 0;
}
