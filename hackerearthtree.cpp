#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
vector<ll>g[1000001];
ll vis[1000005]={0};
ll l[1000001];
ll m[1000001];
/*queue<ll>q ;
void bfs(ll s)
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
void dfs(ll curr,map<ll,ll>pehli)
{
       vis[curr]=1;
       if(pehli[l[curr]]==0)
       {
              m[curr]=-1;
              pehli[l[curr]]=curr;
       }
       else 
       {
              m[curr]=pehli[l[curr]];
              pehli[l[curr]]=curr;
       }
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(vis[child]==0)
              {
                     dfs(child,pehli);
              }
       }
       
}
signed main() 
{
    fast
    ll n,c;
    cin>>n>>c;
    for(ll i=2;i<=n;i++)
    {
           ll u; cin>>u;
           g[u].pb(i);
    }
    for(ll i=1;i<=n;i++) cin>>l[i];
    map<ll,ll>pehli;
    dfs(1,pehli);
    m[1]=-1;
    for(ll i=1;i<=n;i++) cout<<m[i]<<" ";
}