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

map<int,vector<int> > b;
int n,k,a[200005],maxa,ans,secmax,tansl[200005],tansr[200005];
void input()
{

}
void initilization()
{

}
void solution()
{
	cin>>n>>k;
	ans=0;
	b.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]%k].push_back(a[i]);
	}
	int odd=0;
	for(auto& r:b)
	{
		auto& V=r.second;
		if(V.size()==0)continue;
		if(V.size()%2==1)
		{
			odd++;
			if(odd==2)
			{
				cout<<-1<<endl;
				return;
			}
			sort(V.begin(),V.end());
			tansl[0]=0;
			for(int i=0;i<V.size()-1;i+=2)
			{
				tansl[i+2]=tansl[i]+(V[i+1]-V[i])/k;
			}
			tansr[V.size()+1]=0;
			for(int i=V.size()-1;i>=1;i-=2)
			{
				tansr[i]=tansr[i+2]+(V[i]-V[i-1])/k;
			}
			int otans=99999999999999999;
			for(int gthrow=1;gthrow<=V.size();gthrow+=2)
			{
				int tans=0;
				// for(int i=0;i<=gthrow-1;i+=2)
				// 	tans+=(V[i+1]-V[i])/k;
				// for(int i=gthrow+1;i<V.size();i+=2)
				// 	tans+=(V[i+1]-V[i])/k;
				tans=tansl[gthrow-1]+tansr[gthrow+1];
				otans=min(otans,tans);
			}
			ans+=otans;
			continue;
		}
		sort(V.begin(),V.end());
		for(int i=0;i<V.size();i+=2)
		{
			ans+=(V[i+1]-V[i])/k;
		}
	}//I love STL
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
		input();
		initilization();
		solution();
	}
	return 0;
}
