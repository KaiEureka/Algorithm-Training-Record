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
const int MaxN=5;
int n;
struct Data
{
	int a,b;
	bool operator<(const Data &x)const
	{
		return b<x.b;
	}
}dat[200005];
int win[200005],cost[200005],x,k;
priority_queue<int,vector<int> >pq;
void solution()
{
	while(!pq.empty())pq.pop();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>dat[i].a;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>dat[i].b;
	}
	sort(dat+1,dat+n+1);
	win[0]=0;
	for(int i=1;i<=n;i++)
	{
		win[i]=win[i-1]+max(dat[i].b-dat[i].a,0ll);
	}
	cost[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		if(n-i+1>k)
		{
			pq.push(dat[i].a);
			cost[i]=cost[i+1]+dat[i].a-pq.top();
			pq.pop();
		}
		else
		{
			pq.push(dat[i].a);
			cost[i]=cost[i+1]+dat[i].a;
		}
	}
	int ans=0;
	for(int div=0;div<=n;div++)
	{
		if(n-div+1>k)ans=max(ans,win[div]-cost[div+1]);
	}
	cout<<ans<<endl;
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
