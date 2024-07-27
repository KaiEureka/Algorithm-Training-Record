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

int n,l,r,a[200005],sum,ans;

void initilization()
{

}

void solution()
{
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p1=1,p2=0;
	sum=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(sum>=l)
		{
			sum=0;
			ans++;
			p1=i;
		}
		sum+=a[i];
		while(sum>r)
		{
			sum-=a[p1];
			p1++;
		}
	}
	if(sum>=l)
	{
		sum=0;
		ans++;
		//p1=n+1;
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
		initilization();
		solution();
	}
	return 0;
}
