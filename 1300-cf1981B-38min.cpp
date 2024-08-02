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
int n,m,ans,cnt;
void solution()
{
	cin>>n>>m;
	cnt=0;
	if(n==0&&m==0){cout<<0<<endl;return;}
	int x=n+m,y=max(0ll,n-m),fx=x,fy=y;
	string s1="",s2="";
	do{ s1+=char(x%2+'0'),x/=2;}while(x);
	do{ s2+=char(y%2+'0'),y/=2;}while(y);
	if(s1.size()!=s2.size())
	{
		cout<<((1<<(s1.size()))-1)<<endl;
		return;
	}
	else
	{
		int p;
		for(p=s1.size()-1;p>=0;p--)
		{
			if(s1[p]!=s2[p])break;
		}
		p++;
		cout<<(fx/(1<<(p))*(1<<(p))+(1<<(p))-1)<<endl;
		return;
	}
	
	// for(int i=max(0ll,n-m);i<=n+m;i++)
	// {
	// 	ans|=i;
	// }
	// cout<<ans<<endl;
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
