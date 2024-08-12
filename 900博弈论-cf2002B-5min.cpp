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
int n,a[MaxN],b[MaxN];
void solution()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"Bob"<<endl;
		return;
	}
	flag=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[n-i+1])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"Bob"<<endl;
		return;
	}
	cout<<"Alice"<<endl;
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
