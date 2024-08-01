#include <bits./stdc++.h>
#define int long long
using namespace std;
int n,a[200005],p[200005],ans,T;
vector<int> V[200005];
int dfs(int p)//dfs是p的子树全部用于供养p所能给出的最大值
{
	if(V[p].size()==0)return a[p];
	int tans=999999999999999999;
	for(int i=0;i<V[p].size();i++)
	{
		int x=a[V[p][i]],y=dfs(V[p][i]);
		tans=min(tans,y<=x?y:x+(y-x)/2);
	}
	return tans;
}
void solution()
{
	cin>>n;p[1]=1;
	for(int i=1;i<=n;i++)cin>>a[i],V[i].clear();
	for(int i=2;i<=n;i++)cin>>p[i],V[p[i]].push_back(i);
	cout<<dfs(1)+a[1]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)solution();
	return 0;
}
