#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
vector<ll>g[100001];
ll vis[100005]={0};
ll par[100005];
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
}
ll co=0;*/
ll sv=0,ev=0;
bool dfs(ll u, ll p)
{
       vis[u] = true;
	par[u] = p;
	for(auto v: g[u])
	{
		if(v == p) continue;
		if(vis[v]) 
		{
			sv = v; 
			ev = u; 
			return true;
		} 
		if(!vis[v]) 
		{
		       if(dfs(v,u)) 
				return true;
		}
	}
	return false;
}
bool visit_all(ll n)
{
	for(ll i = 1; i <= n; ++i)
	{
		if(!vis[i])
			if(dfs(i,-1)) return true;
	}
	return false;
}
signed main() 
{
    fast
    ll t=1;
   // cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        for(ll i=0;i<100005;i++) par[i]=-1;
        while(m--)
        {
               ll a,b;
               cin>>a>>b;
               g[a].pb(b);g[b].pb(a);
        }
        ll x=visit_all(n);
        
        if(x==0) cout<<"IMPOSSIBLE\n";
        else
        {
              // cout<<sv<<" "<<ev<<"\n";
               vector<ll> v;
               ll tf=ev;
               v.pb(ev);
               while(sv!=tf)
               {
                      v.pb(par[tf]);
                      tf=par[tf];
               }
               v.pb(ev);
               cout<<v.size()<<"\n";
               for(ll i=0;i<v.size();i++)
               {
                      cout<<v[i]<<" ";
               }
        }
    }
}