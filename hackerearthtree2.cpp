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
ll co=0;
map<pair<ll,ll>,ll>m;
void dfs(ll curr, ll par, ll x)
{
       vis[curr]=1;
       int d=0;
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(child!=par)
              {
                     d=1;
                     dfs(child, curr, x+m[mp(curr,child)]);
              }
       }
       if(d==0 && x%2!=0) co++;
}
signed main() 
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>> n;
        ll p=n-1;
        m.clear();
        while(p--)
        {
               ll a,b,k;
               cin>>a>>b>>k;
               g[a].pb(b); g[b].pb(a);
               m[mp(a,b)]=k;
               m[mp(b,a)]=k;
        }
        co=0;
        dfs(1,0,0);
        cout<<co<<"\n";
        for(ll i=0;i<=n;i++) g[i].clear();
    }
}