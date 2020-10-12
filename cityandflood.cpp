#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
ll par[100001];



ll findsu(ll a)
{
    if(par[a]==a) return a;
    else 
    {
        ll x=findsu(par[a]);
        par[a]=x;
        return x;
    }
}
void unionsu(ll a, ll b)
{
        par[b]=a;
}
signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    for(ll abc=1; abc<100001; abc++) par[abc]=abc;
    while(t--)
    {
      ll n,k;
      cin>>n>>k;
      while(k--)
      {
          ll a,b;
          cin>>a>>b;

          ll x=findsu(a);
          ll y=findsu(b);

          if(x!=y) unionsu(x,y);
      }
	  for(int i=1;i<=n;i++) findsu(i);
	  set<ll>s;
	  for(ll i=1;i<=n;i++) {s.insert(par[i]);}
	  //for(auto i: s) cout<<i<<" ;";
	  cout<<s.size()<<"\n";
    }
}