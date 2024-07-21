//这个weight的引入太棒了，以下子解决了操作2数目难以求出的问题，每进行一次操作2，必然weight-1，故比较weight差值即可
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

vector<int> c[100005];
int ansl[100005],weight[100005],ansr[100005],C[1000005],ans[100005];//ans is pos of l point
int ac;
int n,m;

int brutecompute(int i)
{
	int p1=1,p2=m;
	for(int j=1;j<=m;j++)
	{
		C[j]=c[i][j];
	}
	while(p2-p1>1)
	{
		while(C[p1]==0)p1++;
		while(C[p2]==0)p2--;
		if(C[p1]<C[p2])
		{
			C[p1+1]+=C[p1];
			C[p2-1]+=C[p1];
			C[p2]-=C[p1];
			C[p1]=0;
		}
		else if(C[p1]>C[p2])
		{
			C[p1+1]+=C[p2];
			C[p2-1]+=C[p2];
			C[p1]-=C[p2];
			C[p2]=0;
		}
		else
		{
			C[p1+1]+=C[p1];
			C[p2-1]+=C[p2];
			C[p1]=0;
			C[p2]=0;
		}
		while(C[p1]==0)p1++;
		while(C[p2]==0)p2--;
	}
	ansl[i]=C[p1];
	ansr[i]=C[p1+1];p2=p1+1;
	weight[i]=p1*C[p1]+p2*C[p2];
	return p1;
}
void initilization()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		c[i].clear();
		c[i].push_back(0);
		for(int j=1;j<=m;j++)
		{
			cin>>ac;
			c[i].push_back(ac);
		}
	}
}
void solution()
{
	for(int i=1;i<=3;i++)
	{
		ans[i]=brutecompute(i);
		//cout<<ans[i]<<' '<<ansl[i]<<' '<<ansr[i]<<' '<<weight[i]<<endl;
	}
	
	if(ansl[1]==ansl[2]&&ansl[1]==ansl[3])
	{
		for(int i=4;i<=n;i++)
		{
			ans[i]=brutecompute(i);
			if(weight[i]!=weight[1])
			{
				cout<<i<<' '<<abs(weight[i]-weight[1])<<endl;
				return;
			}
		}	
		cout<<"dataerror"<<endl;
	}
	else
	{
		if(ansl[1]==ansl[2])
		{
			cout<<3<<' '<<abs(weight[3]-weight[1])<<endl;
		}
		else if(ansl[1]==ansl[3])
		{
			cout<<2<<' '<<abs(weight[2]-weight[1])<<endl;
		}
		else if(ansl[2]==ansl[3])
		{
			cout<<1<<' '<<abs(weight[1]-weight[2])<<endl;
		}
		else
		{
			cerr<<"dataerror"<<endl;
		}
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
		initilization();
		solution();
	}
	return 0;
}
