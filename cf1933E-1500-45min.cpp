#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#define int long long
using namespace std;

int n,q,l,u,r,a[100005];

void solution()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
		a[i]+=a[i-1];
	a[0]=0;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>l>>u;
		//just find a r push abs(a[r]-a[l-1]-u-1) min
		int nl=l,nr=n;
		double U=a[l-1]+u+0.5;
		while(nr-nl>=5)
		{
			int midl=max(nl+1,nl+(nr-nl)/3),midr=min(nr-(nr-nl)/3,nr-1);
			if(midl==midr)midr++;
			if(fabs(a[midl]-U)>fabs(a[midr]-U)&&fabs(fabs(a[midl]-U)-fabs(a[midr]-U))>1e-5)
				nl=midl;
			else
				nr=midr;
		}
		int ansvalue=1e10,ansr=l;
		//cout<<'x'<<nl<<' '<<nr<<endl;
		for(r=nl;r<=nr;r++)
			if(fabs(a[r]-U)<ansvalue&&fabs(fabs(a[r]-U)-ansvalue)>1e-5)
				ansvalue=fabs(a[r]-U),ansr=r;
		cout<<ansr<<' ';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
		solution(),cout<<endl;
	return 0;
}
