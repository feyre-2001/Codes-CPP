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
/*vector<ll>g[1000001];
ll vis[1000005]={0};
map<ll,ll>y;
queue<ll>q ;*/
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
}
ll co=0;
ll dfs(ll curr)
{
       vis[curr]=1;
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(vis[child]==0)
              {
                     co++;
                     dfs(child);
              }
       }
       return co;
}*/
signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n][n],d[n][n];
        for(ll i=0;i<n;i++)
        {
               for(ll j=0;j<n;j++) 
               {
                      cin>>a[i][j]; d[i][j]=a[i][j];
               }
        }
        ll x[n];
        vector<ll>dis;
        for(ll i=0;i<n;i++)
        {
               cin>>x[i]; x[i]--;
        }
        ll mp[n]={0};
        for(ll op=n-1;op>=0;op--)
        {
              mp[x[op]]=1;
               for (ll i=0; i<n; ++i) 
                {
                     for (ll j=0; j<n; ++j) 
                     {
                            d[i][j] = min(d[i][j], d[i][x[op]]+d[x[op]][j]); 
                     }
                }
              ll s=0;
              for(ll ix=0;ix<n;ix++)
              {
                     for(ll jx=0;jx<n;jx++)
                     {
                            if(mp[ix] && mp[jx]) s=s+d[ix][jx];
                          //  if(ix==y || jx==y) a[ix][jx]=INF;
                     }
              }
              dis.pb(s);
        }
        reverse(dis.begin(),dis.end());
        for(ll i=0;i<dis.size();i++) cout<<dis[i]<<" ";
    }
}