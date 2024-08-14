#pragma GCC optimize(2)
/*
ANALYSIS:
因为用了memset(b,0,sizeof(b));而不是for(int i=1;i<=n;i++)b[i]=0;，使得时间复杂度成为O(T*MAXN)而不是O(T*N),多组输入的数据只保证O(T*N)等价于O(n)，
并未保证O(T*MAXN)等价于O(n)，事实上，O(T*MAXN)等价于O(TMax*n)，使得TLE，耻辱。可见多组输入要把“多组输入不影响时间复杂度的条件”纳入考虑范围，使之确保得到执行
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
int n,a[MaxN],b[MaxN];
void solution()
{
	scanf("%lld",&n);
	//memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	b[a[1]]=1;
	for(int i=2;i<=n;i++)
	{
		if((a[i]<n&&b[a[i]+1]==1||a[i]>1&&b[a[i]-1]==1))
		{
			b[a[i]]=1;
		}
		else
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

i32 main()
{
	//preprocess();
	int T=1;
	cin>>T;
	while(T--)
	{
		solution();
	}
	return 0;
}