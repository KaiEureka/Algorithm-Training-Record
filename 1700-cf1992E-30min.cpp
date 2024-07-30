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

int n,lenn,pow10[20],totalw,ans;
queue<pair<int,int> > Q;
int getlen(int n)
{
	int lenn=0;
	while(n)
	{
		n/=10;
		lenn++;
	}
	return lenn;
}
void input()
{

}
void initilization()
{

}
void solution()
{
	while(!Q.empty())Q.pop();
	cin>>n;
	ans=0;
	lenn=getlen(n);
	for(int a=1;a<=10000;a++)
	{
		for(int b=max(1ll,lenn*a-6);b<=min(10000ll,lenn*a-1);b++)//1<=lenn*a-b<=6//n*a-b<=1e6 6位 至少0位
		{
			if(getlen(n*a-b)==lenn*a-b)
			{
				int r=0;
				totalw=lenn*a-b;
				while(totalw)
				{
					if(totalw-lenn>=0)
					{
						r=r*pow10[lenn]+n;
						totalw-=lenn;
					}
					else
					{
						r=r*pow10[totalw]+n/pow10[lenn-totalw];
						totalw=0;
					}
				}
				if(r==n*a-b)
				{
					ans++;
					Q.push(pair<int,int>(a,b));
				}
			}
		}
	}
	cout<<ans<<endl;
	while(!Q.empty())
	{
		cout<<Q.front().first<<" "<<Q.front().second<<endl;
		Q.pop();
	}
}

i32 main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	pow10[0]=1;
	for(int i=1;i<=18;i++)
	{
		pow10[i]=pow10[i-1]*10;
	}
	cin>>T;
	while(T--)
	{
		input();
		initilization();
		solution();
	}
	return 0;
}
