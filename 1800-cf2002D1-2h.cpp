#pragma GCC optimize("O3")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
int n,q,fa[MaxN],p[MaxN],x,y;

int check(int i)
{
	if(i==1)
	{
		if(p[i]==1)
			return 1;
		else
			return 0;	
	}
	if(p[i-1]==fa[p[i]])
		return 1;
	if(fa[p[i-1]]==fa[p[i]])
		return 1;
	x=p[i-1];
	while(x!=1)
	{
		x=fa[x];
		if(fa[x]==fa[p[i]])
			return 1;
	}
	return 0;
}

void solution()
{
	cin>>n>>q;
	fa[1]=0;
	for(int i=2;i<=n;i++)cin>>fa[i];
	for(int i=1;i<=n;i++)cin>>p[i];
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=check(p[i]);
	for(int qi=1;qi<=q;qi++)
	{
		cin>>x>>y;
		auto fx=x,fy=y;
		unordered_set<int>s;
		s.insert(x);if(x+1<=n)s.insert(x+1);
		s.insert(y);if(y+1<=n)s.insert(y+1);
		//cout<<x<<' '<<y<<endl;
		for(auto i:s)
			cnt-=check(i);
		//cout<<x<<' '<<y<<endl;
		swap(p[fx],p[fy]);
		for(auto i:s)
			cnt+=check(i);
		if(cnt==n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
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
		solution();
	}
	return 0;
}
