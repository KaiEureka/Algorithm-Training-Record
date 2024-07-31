/*我们从每个联通快中抽取一个数字，只在这些数字中尝试连接，而不是所有数字中尝试连接，也可以保证得到连上，而不会错过,
为什么如此呢，因为鸽巢原理，我们抽出了x+1个相互不可达的点，这些点中一定有一对满足模x等于0，因为模x一共只有x个结果
嗯所以想过这题，要么想到鸽巢原理，把核心步骤的n方操作变成n，从而秒过。要么想到平均而言n方的算法其实只比n慢一点点，
因此用shuffle保证平均就业过了*/
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
#include <ctime>
#include <random>
#define int long long
#define i32 signed
#define endl '\n'
using namespace std;

const int MaxN=2005;
int fa[MaxN],Rank[MaxN],Peo[MaxN];
inline int find(int x) {return (fa[x] == x) ? x :  fa[x]=find(fa[x]);}
inline void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (Rank[x] > Rank[y])
	{
		fa[y] = x;
		Peo[x] += Peo[y];
	}
	else
	{
		fa[x] = y;
		Peo[y] += Peo[x];
		if (Rank[x] == Rank[y]) //树高相同时让父节点的树高值加一
			Rank[y] += 1;
	}
}
inline void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		fa[i] = i;
		Rank[i]=1;
		Peo[i]=1;
	}
}
stack<pair<int,int>> Q;
struct node{
	int data,no;
	bool operator < (const node &a) const
	{
		return data<a.data;
	}
}a[MaxN];
int n;
void solution()
{
	while(!Q.empty())
		Q.pop();
	scanf("%lld",&n);
	init(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].data);
		a[i].no=i;
	}
	shuffle(a+1,a+n+1,default_random_engine(time(0)));
	for(int x=n-1;x>=1;x--)
	{
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(find(i)!=find(j)&&abs(a[j].data-a[i].data)%x==0)
				{
					merge(i,j);
					Q.push({a[i].no,a[j].no});
					flag=1;
					goto out;
				}
			}
		}
		out:
		if(flag==0)
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	printf("YES\n");
	while(!Q.empty())
	{
		printf("%lld %lld\n",Q.top().first,Q.top().second);
		Q.pop();
	}
}

i32 main()
{
	//freopen("/Users/Kai/NewCode/CF/workplace/input.txt","r",stdin);
	int T=1;
	scanf("%lld",&T);
	while(T--)
	{
		solution();
	}
	return 0;
}
