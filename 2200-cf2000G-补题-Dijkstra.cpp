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
const int maxn=100005;
int n,m,t0,t1,t2,u,v,w1,w2;
const int INF=1e18;

struct way {  
    int v, len;  
    way(int v = 0, int len = 0) :v(v), len(len) {}  
    bool operator < (const way &a)const { 
        return len < a.len;  
    }  
};  

struct node {  
    int v, len1,len2;  
    node(int _v = 0, int _len1 = 0, int _len2 = 0) :v(_v), len1(_len1), len2(_len2) {}  
};  

vector<node>G[maxn];  
bool vis[maxn];  
int dis[maxn];

void init() {  
    for (int i = 0; i<maxn; i++) {  
        G[i].clear();  
        vis[i] = false;  
        dis[i] = -1;  
    }  
}  

int dijkstra(int s, int e) {  
    priority_queue<way>Q;  
    Q.push(way(s, t0));
    dis[s] = t0;  
	auto update=[&](int to,int time){if(dis[to]<time)dis[to]=time,Q.push(way(to,time));};
    while (!Q.empty()) {  
        auto [v,_] = Q.top(); 
        Q.pop();  
        if (vis[v]) continue;
        vis[v] = true;  
        for (auto [to,len1,len2]:G[v]) 
		{
            update(to, dis[v] - len2);
			if ( dis[v] <= t1 || dis[v] - len1 >= t2 ) 
				update(to, dis[v] - len1);
			else 
				update(to, t1 - len1);
        }  
    }  
    return dis[e];  
}  


void solution()
{
	cin>>n>>m;
	cin>>t0>>t1>>t2;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w1>>w2;
		G[u-1].push_back(node(v-1,w1,w2));
		G[v-1].push_back(node(u-1,w1,w2));
	}
	cout<<dijkstra(n-1,0)<<endl;
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
