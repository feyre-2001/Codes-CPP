#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;
vector<ll>g[100001];
ll vis[100005]={0};
ll in[100005]={0};
ll low[100005]={0};
ll vis2[100005]={0};
ll in2[100005]={0};
ll low2[100005]={0};
//map<ll,ll>y;
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
/*void bfs(ll s)
{
       vis[s]=1;
       q.push(s);
       ll curr=q.front(); vis[curr]=1;
       while(!q.empty())
       {
              curr=q.front(); q.pop(); // vis[curr]=1;
              for(ll i=0;i<g[curr].size();i++)
              {
                     ll child=g[curr][i];
                     if(vis[child]==0) 
                     { 
                            q.push(child); 
                            vis[child]=1;
                     }
              }
       }
}*/

ll timer=0;
vector<pair<ll,ll>>bridge;
vector<ll>art;

ll dfs(ll curr,ll par)
{
       vis[curr]=1;
       in[curr]=low[curr]=timer;
       timer++;
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(child==par) continue;
              if(vis[child]==1)
              {
                     //back edge curr-child
                     low[curr]=min(low[curr],in[child]);
              }
              if(vis[child]==0)
              {
                     // forward edge 
                     dfs(child,curr);
                     if(low[child]>in[curr])
                     {
                            if(curr>child) bridge.pb({child,curr});
                            else bridge.pb({curr,child});
                     }
                     low[curr]=min(low[curr],low[child]);
              }
       }
}
ll timer2=0;
ll dfs2(ll curr,ll par)
{
       vis2[curr]=1;
       in2[curr]=low2[curr]=timer2;
       timer2++;
       int sub=0;
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(child==par) continue;
              if(vis2[child]==1)
              {
                     //back edge curr-child
                     low2[curr]=min(low2[curr],in2[child]);
              }
              if(vis2[child]==0)
              {
                     // forward edge 
                     dfs2(child,curr);
                     if(low2[child]>=in2[curr] && par!=-1)
                     {
                            art.pb(curr);
                     }
                     sub++;
                     low2[curr]=min(low2[curr],low2[child]);
              }
       }
       if(par==-1 && sub>1) art.pb(curr);
}
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 
signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    while(t--)
    {
       ll n, m;
       cin>>n>>m;
       while(m--)
       {
              ll u, v;
              cin>>u>>v;
              g[u].pb(v); g[v].pb(u);
       }
       for (ll i = 1; i <= n; ++i) 
       {
              if (!vis[i]) 
              {
                     dfs(i,-1);
              }
              if (!vis2[i]) 
              {
                     dfs2(i,-1);
              }
       }
       cout<<art.size()<<"\n";
       for(ll i=0;i<art.size();i++)
       {
              cout<<art[i]<<" ";
       }
       cout<<"\n";
       cout<<bridge.size()<<"\n";
       sort(bridge.begin(), bridge.end());
       sort(bridge.begin(), bridge.end(), sortbysec);
       for(ll i=0;i<bridge.size();i++)
       {
              cout<<bridge[i].first<<" "<<bridge[i].second<<"\n";
       }
    }
}