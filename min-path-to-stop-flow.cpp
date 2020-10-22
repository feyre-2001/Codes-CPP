#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fr(i, a, b) for (long long int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
bool vis[1005] = {0};
map<ll, ll> y;
queue<ll> q;
ll gcd(ll a, ll b)
{
    if (b % a == 0)
        return a;
    else
        return gcd(b % a, a);
}
ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2 != 0)
            res = res * a;
        a = a * a;
        b = b / 2;
    }
    return res;
}
bool bfs(const vector<vector<int>> &g, int s, int e, int parent[],vector<vector<int>> &rg)
{
    bool used[g.size()] = {0};
    queue<int> q;
    q.push(s);
    used[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u = 0; u < rg.size(); u++)
        {
            if (!used[u] && rg[v][u] > 0)
            {
                q.push(u);
                parent[u] = v;
                used[u] = true;
            }
        }
    }
    return used[e];
}

int maxFlow(vector<vector<int>> &g, int s, int e,vector<vector<int>> &rg)
{
    int parent[g.size()] = {-2};
    int max_flow = 0;
    while (bfs(g, s, e, parent,rg))
    {
        int flow = 1 << 15;
        for (int u = e; u != s; u = parent[u])
        {
            int v = parent[u];
            flow =  min(flow, rg[v][u]);
        }

        for (int u = e; u != s; u = parent[u])
        {
            int v = parent[u];
            rg[u][v] += flow;
            rg[v][u] -= flow;
        }
        max_flow += flow;
    }
    /*for(ll i=0;i<g.size();i++) 
    {
           for(ll j=0;j<g.size();j++) cout<<rg[i][j]<<" ";
           cout<<"\n";
    }
    cout<<"============\n";
    for(ll i=0;i<g.size();i++) 
    {
           for(ll j=0;j<g.size();j++) cout<<g[i][j]<<" ";
           cout<<"\n";
    }*/
    return max_flow;
}

void dfs(ll v[],ll s,vector<vector<int>> &rg)
{
       v[s]=1;
       for(ll i=0;i<rg.size();i++)
       {
              if(v[i]==0 && rg[s][i]!=0) 
              {
                     //cout<<i<<"@ ";
                     dfs(v,i,rg);
              }
       }
}
signed main()
{
    fast 
    int t=1;
    // cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<int>> g(n, vector<int>(n));
        vector<vector<int>> rg(n, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            int u;
            cin >> u;
            int v;
            cin >> v;
            u--;
            v--;
            g[u][v] += 1;
            g[v][u] += 1;
            rg[u][v] += 1;
            rg[v][u] += 1;
        }

        cout <<maxFlow(g, 0, n - 1,rg) << '\n';
        ll v[n]={0};
        dfs(v,0,rg);
        //for(ll i=0;i<n;i++) cout<<v[i]<<"## ";
        for(ll i=0;i<n;i++)
        {
               for(ll j=0;j<g.size();j++)
               {
                      if(v[i] && g[i][j]==1 && v[j]==0)
                      {
                             cout<<i+1<<" "<<j+1<<"\n";
                      }
               }
        }
    }
}