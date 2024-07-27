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

int n;

void solution()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		if(i==2)cout<<1<<' '<<2<<endl;
		else cout<<i<<' '<<i<<endl;
	//cout<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
		solution();
	return 0;
}
