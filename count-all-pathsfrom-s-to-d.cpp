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
ll dis[1000005]={-1};
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
/*pair<ll,ll> bfs(ll s,ll n)
{
       vis[s]=1;
       q.push(s);
       dis[s]=0;
       ll curr=q.front(); vis[curr]=1;
       while(!q.empty())
       {
              curr=q.front(); q.pop(); // vis[curr]=1;
              for(ll i=0;i<g[curr].size();i++)
              {
                     ll child=g[curr][i];
                     if(dis[child]==-1) 
                     { 
                            q.push(child); 
                            dis[child]=dis[curr]+1;
                     }
              }
       }
       ll maxd=0,node=0;
       for(int i=1;i<=n;i++)
       {
              if (dis[i] > maxd)
              {
                     maxd= dis[i]; node = i;
              }
       }
       return mp(node, maxd);
}*/
ll co=0;
ll dfs(ll curr, ll d)
{
       vis[curr]=1;
       if(curr==d) co++;
       else{
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(vis[child]==0)
              {
                     dfs(child,d);
              }
       }
       }
       vis[curr]=0;
}
signed main() 
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
       ll n,m;
       cin>>n>>m;
       while(m--)
       {
              ll u, v;
              cin>>u>>v;
              g[u].pb(v);
       }
       ll s,d;
       cin>>s>>d;
       dfs(s,d);
       cout<<co<<"\n";
       co=0;
       for(ll i=0;i<n+1;i++) {g[i].clear(); vis[i]=0;}
    }
}