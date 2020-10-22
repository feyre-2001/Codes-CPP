#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
bool vis[1005]={0};
map<ll,ll>y;
queue<ll>q ;
ll gcd(ll a, ll b){
    if(b%a==0) return a;
    else return gcd(b%a,a);
}
ll power(ll a, ll b){
    ll res=1;
    while(b)
    {
        if(b%2!=0) res=res*a;
        a=a*a;
        b=b/2;
    }
    return res;
}
bool bfs(const vector<vector<int>>& g, int s, int e, int parent[]) {
    bool used[g.size()] = {0};
    queue<int> q;
    q.push(s);
    used[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u = 0; u < g.size(); u++) {
            if (!used[u] && g[v][u] > 0) {
                q.push(u);
                parent[u] = v;
                used[u] = true;
            }
        }
    }
    return used[e];
}

int maxFlow(vector<vector<int>>& g, int s, int e) {
    int parent[g.size()] = {0};
    int max_flow = 0;
    while (bfs(g, s, e, parent)) {
        int flow = 1 << 15;
        for (int u = e; u != s; u = parent[u]) {
            int v = parent[u];
            flow = std::min(flow, g[v][u]);
        }
        
        for (int u = e; u != s; u = parent[u]) {
            int v = parent[u];
            g[u][v] += flow;
            g[v][u] -= flow;
        }
        max_flow += flow;
    }
    return max_flow;
}

signed main() 
{
    fast
    int t;
	cin >> t;
	while (t-- > 0) {
	    int n; cin >> n;
	    int m; cin >> m;
	    vector<vector<int>> g(n, vector<int>(n));
	    for (int i = 0; i < m; i++) {
	        int u; cin >> u;
	        int v; cin >> v;
	        int w; cin >> w;
	        u--; v--;
	        g[u][v] += w;
	        g[v][u] += w;
	    }
	    
	    cout << maxFlow(g, 0, n-1) << '\n';
	}
}