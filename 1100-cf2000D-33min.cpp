/*
ANALYSIS:
把贪心误判成了DP，导致浪费了时间，小耻辱。
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
const int MaxN=200005;
int n,a[MaxN],pre[MaxN],dp[MaxN],pr;
string s;
set<int> rs,ls;
void solution()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	pre[0]=0;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	//for(int i=1;i<=n;i++)cout<<pre[i]<<' ';cout<<endl;
	cin>>s;
	int ans=0;
	for(int p1=1,p2=n;p1<=p2;)
	{
		while(s[p1-1]!='L')p1++;
		while(s[p2-1]!='R')p2--;
		if(p1>p2)break;
		ans+=pre[p2]-pre[p1-1];
		p1++;p2--;
	}
	cout<<ans<<endl;
	// rs.clear();ls.clear();
	// for(int i=0;i<s.size();i++)
	// {
	// 	if(s[i]=='R')rs.insert(-(i+1));
	// 	else if(s[i]=='L')ls.insert((i+1));
	// }
	// cout<<"rs";for(auto i:rs)cout<<i<<' ';cout<<endl;
	// dp[0]=0;
	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<"cmpt"<<i<<endl;
	// 	dp[i]=dp[i-1];
	// 	if(s[i-1]=='R')
	// 	{
	// 		cout<<-(i-1);
	// 		auto fr=lower_bound(rs.begin(),rs.end(),-(i-1));
	// 		cout<<"FR"<<*fr<<endl;
	// 		if(fr==ls.end())pr=1;
	// 		else pr=-*fr;
	// 		cout<<"PR"<<pr<<endl;
	// 		auto fl=lower_bound(ls.begin(),ls.end(),pr);
	// 		if(fl==ls.end())continue;

	// 		cout<<"FL"<<*fl<<endl;
	// 		cout<<"DP"<<i<<' '<<*fl<<endl;
	// 		cout<<"DP"<<pre[i]<<' '<<pre[*fl-1]<<endl;
	// 		dp[i]=max(dp[i],dp[*fl-1]+pre[i]-pre[*fl-1]);
	// 	}
	// 	cout<<dp[i]<<endl;
	// }
	// cout<<"ANS"<<dp[n]<<endl;
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