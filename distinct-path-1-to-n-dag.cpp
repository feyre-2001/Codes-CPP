#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
 
int n, m;
vector<vector<int>> g;
vector<int> cnt;
vector<int> inDegree;
const int modb = 1e9+7;
 
void top_sort()
{
	queue<int> q;
	for(int i = 2; i <= n; ++i)
	{
		if(inDegree[i] == 0)
		{
			q.push(i);	
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v: g[u])
		{
			--inDegree[v];
			if(inDegree[v] == 0)
				q.push(v);
		}
	}
	q.push(1);
	cnt[1] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v: g[u])
		{
			--inDegree[v];
			cnt[v] = cnt[v] + cnt[u];
			cnt[v] %=  modb;
			if(inDegree[v] == 0)
				q.push(v);
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	cnt.resize(n+1);
	inDegree.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		inDegree[v]++;
		g[u].push_back(v);
	}
	for(int i = 2; i <= n; ++i)
	{
	}
	top_sort();
	cout << cnt[n];
}
