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
const int MaxN=100005;
int x[MaxN],y[MaxN],n,xs,ys,xt,yt;
void solution()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	cin>>xs>>ys>>xt>>yt;
	int r2=(xs-xt)*(xs-xt)+(ys-yt)*(ys-yt);
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if((x[i]-xt)*(x[i]-xt)+(y[i]-yt)*(y[i]-yt)<=r2)
		{
			flag=0;
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
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
