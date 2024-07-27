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

int n,a[200005],b[200005],totalcost,cost,ccost[200005],flag,p,f[200005];

void solution()
{
	scanf("%lld",&n);
	flag=1;
	totalcost=0;
	p=0;
	for(int i=0;i<=n;i++)b[i]=0;
	for(int i=0;i<=n;i++)f[i]=i-1;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),b[a[i]]++;
	printf("%lld ",b[0]);
	
	for(int i=1;i<=n;i++)
	{
		if(flag==0)
		{
			printf("-1 ");
			continue;
		}
		if(b[i-1]==0)
		{
			int tflag=0;
			int r=i-3;
			while(f[r]>=0&&b[r]==1)
			{
				r=f[r];
			}
			//f[j]表示上一个b不为1的位置
			f[i-2]=r;
			for(int j=i-2;j>=0;j=f[j])
				if(b[j]>1)
				{
					totalcost+=i-1-j;
					b[i-1]++;
					b[j]--;
					tflag=1;
					if(b[j]==1)f[i-1]=f[j];
					break;
				}
			if(tflag==0)
			{
				flag=0;
				printf("-1 ");
				continue;
			}
		}
		printf("%lld ",totalcost+b[i]);
		//cout<<"N"<<i<<' '<<totalcost<<' ';
		//for(int j=0;j<=n;j++)cout<<b[j]<<' ';cout<<endl;
	}
	printf("\n");
}

signed main()
{
	int T;
	scanf("%lld",&T);
	while(T--)
		solution();
	return 0;
}
