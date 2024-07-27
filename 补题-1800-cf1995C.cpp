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

int n,ans;
double llog2=log(2.0);
double a[200005];
int cnt=0;

void solution()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
		if((fabsl(a[i]-1)<1e-9)&&a[i-1]-1>1e-9)
		{
			cout<<-1<<endl;
			return;
		}
	int p=1;
	for(int i=1;i<=n;i++)
	{
		if(fabs(a[i]-1)<1e-9)
			p++,a[i]=-99999999;
		else
			a[i]=log(log(a[i]));
	}
	ans=0;
	for(int i=p+1;i<=n;i++)
	{
		if(a[i]<a[i-1]&&fabs(a[i]-a[i-1])>1e-9)
		{
			double tans=(a[i-1]-a[i])/llog2;
			int inttans;
			if(fabs(tans-(int)tans)<1e-9)
				inttans=(int)tans;
			else
				inttans=(int)tans+1;
			a[i]+=inttans*llog2;
			ans+=inttans;
		}
	}
	cout<<ans<<endl;
}


i32 main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)
	{
		solution();
	}
	return 0;
}
//1 8 2 4 6 3 10 10 9 10
