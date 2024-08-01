#include <iostream>
using namespace std;
const long long N = 1e6 + 10;
long long  m, k, q;
long long a[N], b[N];

/*线段树*/
#define lson rt << 1
#define rson rt << 1 | 1
long long n;
long long c[N];
//n is the number of elements in the array

void inner_build(long long rt, long long l, long long r)
{
	if (l == r)
	{
		c[rt] = 0;
		return;
	}
	long long mid = (l + r) >> 1;
	inner_build(lson, l, mid);
	inner_build(rson, mid + 1, r);
}
inline void build(){inner_build(1, 1, n);}

void pushdown(long long rt, long long l, long long r)
{
	long long mid = (l + r) >> 1;
	if (c[rt])
	{
		c[lson] += c[rt];
		c[rson] += c[rt];
		c[rt] = 0;
	}
}

void inner_change(long long rt, long long l, long long r, long long x, long long y, long long z)
{
	if (x <= l && r <= y)
	{
		c[rt] += z;
		return;
	}
	pushdown(rt, l, r);
	long long mid = (l + r) >> 1;
	if (x <= mid)
		inner_change(lson, l, mid, x, y, z);
	if (y > mid)
		inner_change(rson, mid + 1, r, x, y, z);
}
inline void change(int x,int y,int z){inner_change(1,1,n,x,y,z);}

long long inner_query(long long rt, long long l, long long r, long long x)
{
	if (l == r)
		return c[rt];
	pushdown(rt, l, r);
	long long mid = (l + r) >> 1;
	if (x <= mid)
		return inner_query(lson, l, mid, x);
	else
		return inner_query(rson, mid + 1, r, x);
}
inline long long query(long long x){return inner_query(1,1,n,x);}

void mian()
{
	long long ans = 0;
	scanf("%lld%lld", &n, &q);
	for (long long i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		b[i] = 0;
	}
	//b[i]是想与第i个怪物发生战斗的最大升级速度，即阈值
	//query（i)是当k=i时打完已知怪物后所获得的经验值，利用query数组可以很快二分求出b[i]，整个过程是n*(log^2)的复杂度
	build();
	change(1, n, 1);//所有k值都至少可以打一个怪物怪物[1]
	for (long long i = 2; i <= n; ++i)//对于每一个怪物，利用a[i],算出这个怪物的阈值res，存入b[i]，1~i-1的怪物就是一只怪物，健在根据一只怪物计算未知怪物i的阈值，然后将i也纳入已知怪物序列
	{
		long long l = 1, r = n, res = 0;
		while (l <= r)
		{
			long long mid = (l + r) >> 1;
			if (query(mid) / mid + 1 > a[i])//query(mid) / mid + 1 > a[i]就是check(mid)函数，表示这个阈值是不是小于答案
											//能这么做，是因为query(mid)是当k=mid时的战斗次数，query(mid) / mid + 1就是等级，等级>怪物等级则战斗不会发生
				l = mid + 1;
			else
				res = mid, r = mid - 1;
		}
		b[i] = res;
		change(res, n, 1);//然后说明k>=res的怪物数全部需要加一
	}
	while (q--)
	{
		long long x, y;
		scanf("%lld%lld", &x, &y);
		if (b[x] <= y)//升级速度慢与阈值，可以战斗
			printf("Yes\n");
		else//否则不能战斗
			printf("No\n");
	}
}

int main()
{
	int T = 1;
	while (T--)
		mian();
	return 0;
}
