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
const int MaxN=200005;
int n,m,k,w,a[MaxN],sum;
vector<int> V;
void solution()
{
	cin>>n>>m>>k;
	V.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			V.push_back(min(k,min(n-k+1,min(abs(i-1)+1,abs(n-i)+1)))*min(k,min(m-k+1,min(abs(j-1)+1,abs(m-j)+1))));	
	sort(V.begin(),V.end(),greater<int>());
	cin>>w;
	for(int i=0;i<w;i++)
		cin>>a[i];
	sort(a,a+w,greater<int>());
	sum=0;
	for(int i=0;i<w;i++)
		sum+=V[i]*a[i];
	cout<<sum<<endl;
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