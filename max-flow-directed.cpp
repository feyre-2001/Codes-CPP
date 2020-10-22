#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;

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

bool bfs(vector<vector<ll>>& rg, ll s, ll t,ll parent[], ll n) 
{ 
    bool visited[n]; 
    memset(visited, 0, sizeof(visited)); 

    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
   
    while (!q.empty()) 
    { 
        ll u = q.front(); 
        q.pop(); 
  
        for (ll v=0; v<n; v++) 
        { 
            if (visited[v]==false && rg[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
    return (visited[t] == true); 
} 


ll maxflow(ll s, ll t, vector<vector<ll>>& g, ll n)
{
       vector<vector<ll>> rg(n, vector<ll>(n));
       for(ll i=0;i<n;i++)
       {
              for(ll j=0;j<n;j++) rg[i][j]=g[i][j];
       }
       
       ll parent[n];
       ll max_flow = 0; 
       while (bfs(rg, s, t, parent,n)) 
       { 
        ll path_flow = INT_MAX; 
        for (ll v=t; v!=s; v=parent[v]) 
        { 
            ll u = parent[v]; 
            path_flow = min(path_flow, rg[u][v]); 
        } 
        for (ll v=t; v != s; v=parent[v]) 
        { 
            ll  u = parent[v]; 
            rg[u][v] -= path_flow; 
            rg[v][u] += path_flow; 
        } 
        max_flow += path_flow; 
    } 
    return max_flow; 
}
signed main() 
{
    fast
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> g(n, vector<ll>(n));
    while(m--)
    {
           ll u,v,w; 
           cin>>u>>v>>w;
           u--; v--;
           g[u][v]=w;
    }
    cout<<maxflow(0,n-1,g , n)<<"\n";
}