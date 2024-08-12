#pragma GCC optimize("O3")
/*
ANALYSIS:
首先有一个重要的思想，我不需要知道有哪些节点有问题，因为不需要时刻维护有问题的节点的集合以便check，只需要知道有问题的节点的总数，然后根据每次修改
调整这个总数即可。这个总数只需要对小修改进行小调整，不用管别的，因此无需维护这个集合，想要判断的时候只要看有问题的节点数等不等于0即可。
当然我原来那套维护无序集合、用queue暂存待删除元素，时刻知晓具体哪些元素有问题的方案也是可行的，甚至代码实现发现我的方法100ms、上面这个方法130ms，
课件其实都可以，但上面这个方法更简洁，思路更清晰。
另外，需要注意的是，tmd set、unordered_set、map、unordered_map这些东西，插入的时候都TMD是插入的引用，引用啊tmd，我一直以为是拷贝，这意味着
一个元素只要插进去了，就可能被莫名其妙的更改，因为看似是访问操作，但实则可能会引起红黑树内部的节点改变造成原元素的漂移，因此如果一个东西插入之后还
要用，那一定不要直接插入，而是赋值给一个刚建立的东西，然后把这个东西插入进去，或者直接插入进去，但是提前拷贝留值。
同时存树不要只存fa这一个元素，还要反向存ch这一个vector数组，表示儿子们
*/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>

#define int long long
#define i32 signed
#define endl '\n'
using namespace std;
const int MAXN=300005;
vector<int> ch[MAXN];
int tin[MAXN], tout[MAXN], id[MAXN], par[MAXN];
int T = 0;
int n,q,fa[MAXN],p[MAXN],x,y;
unordered_set<int>s;
queue<int>E;

//对于每一个节点，记录它的dfs序，dfs序的起点和终点，以及它的父节点
void dfs(int u, int p)
{
	id[u] = tin[u] = tout[u] = T++;
	for (auto v : ch[u])
	{
		if (v != p)
		{
			dfs(v, u);
			tout[u] = tout[v];
		}
	}
}

int oldcheck(int i)
{
	if(i==1)
	{
		if(p[i]==1)
			return 1;
		else
			return 0;	
	}
	if(p[i-1]==fa[p[i]])
		return 1;
	if(fa[p[i-1]]==fa[p[i]])
		return 1;
	x=p[i-1];
	while(x!=1)
	{
		x=fa[x];
		if(fa[x]==fa[p[i]])
			return 1;
	}
	return 0;
}

void solution()
{
	T = 0;
	fa[1]=0;
	cin>>n>>q;
	for (int i = 0; i <= n; i++)
		ch[i].clear();
	for (int i = 2; i <= n; i++)
	{
		cin >> fa[i];
		ch[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)cin>>p[i];

	dfs(1, 1);

	auto check = [&](int i)
	{
		if (p[i] == 1)
			return i == 1 ? 1 : 0;
		int from = p[i - 1]; //代指p[i-1]，表示p[i]理论上的所从来
		if (fa[p[i]] == from)//若是子
			return 1;
		if (tin[from] != tout[from])//==如果from不是叶子
			return 0;//不是叶子就不能是兄弟或者祖先之兄弟，必须是子，但是前面又说了不是子，所以不行，return 0
		int pa = fa[p[i]];
		//from是p[i]的兄弟或者祖先之兄弟，本质上是说fa[p[i]]是p[i]的祖先,记pa = fa[p[i]]，
		//则若p[i]在以pa为根的子树中，则yes，否则no
		return (tin[from] >= tin[pa] && tin[from] <= tout[pa]) ? 1 : 0;//若在子树中，势必比根后入而先出
	};

	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=check(p[i]);
	for(int qi=1;qi<=q;qi++)
	{
		cin>>x>>y;
		auto fx=x,fy=y;
		unordered_set<int>s;
		s.insert(x);if(x+1<=n)s.insert(x+1);
		s.insert(y);if(y+1<=n)s.insert(y+1);
		//cout<<x<<' '<<y<<endl;
		for(auto i:s)
			cnt-=check(i);
		//cout<<x<<' '<<y<<endl; 如果把check换成oldcheck，在去掉这两个输出的注释号，就会发现一个诡异的语法现象，我在前面说过了。记下来，以免下次再因为这事调试一年
		swap(p[x],p[y]);
		for(auto i:s)
			cnt+=check(i);
		if(cnt==n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
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
		solution();
	}
	return 0;
}


