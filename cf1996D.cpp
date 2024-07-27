/*if内的条件若一次不满足则次次不满足，则应该放进循环条件里或者加入break，可飞速优化算法
看似是n方的算法有时优化远快于n方，比如调和级数优化，比如越来越早的提前跳出*/
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

int n,x,ans,c2;

void input()
{

}
void initilization()
{

}
void solution()
{
	cin>>n>>x;
	ans=0;
	for(int a=1;a<=n;a++)
	{
		for(int b=1;a*b<=n&&a+b<=x;b++)
		{
			ans+=min(x-a-b,(n-a*b)/(a+b));	
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
		input();
		initilization();
		solution();
	}
	return 0;
}
