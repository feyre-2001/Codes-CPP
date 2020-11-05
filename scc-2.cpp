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
vector<ll>g[300001];
vector<ll>g1[300001];
ll vis[100005]={0};
ll in[100005]={0};
ll low[100005]={0};
ll vis2[300005]={0};
ll in2[300005]={0};
ll low2[300005]={0};
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
vector<pair<ll,pair<ll,ll>>>bridge;
set<ll>art;

/*ll dfs(ll curr,ll par)
{
       vis[curr]=1;
       in[curr]=low[curr]=timer;
       timer++;
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i].first;
              ll index=g[curr][i].second;
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
                            bridge.pb({index,{curr,child}});
                            art.insert(index);
                     }
                     low[curr]=min(low[curr],low[child]);
              }
       }
}*/
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 
vector<ll>order,SCC;
void dfs(ll node)
{
	vis[node] = 1;
	
	for(ll child :g[node])
	if(vis[child] == 0)
	dfs(child);
	
	order.pb(node);
}
void dfs1(ll node)
{
	vis2[node] = 1;
	
	for(ll child : g1[node])
	if(vis2[child] == 0)
	dfs1(child);
	
	SCC.pb(node);
}
signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    while(t--)
    {
       ll n,m;
       cin>>n>>m;
       while(m--)
       { 
              ll a,b;
              cin>>a>>b;
              g[a].pb(b);
              g1[b].pb(a);
       }
       ll c=0;
       vector<ll>v;
       /*for (ll i = 1; i <= n; ++i) 
       {
              if(g1[i].size()==0) {c++; v.pb(i);}
       }*/
       for (ll i = 1; i <= n; ++i) 
       {
              if(vis[i] == 0) dfs(i);
       }
       //vector<pair<ll,ll>>op;
       ll col[n+1];
       for (ll i = 1; i <= n; ++i) 
       {
              if(vis2[order[n-i]] == 0)
		{
		       c++;
			SCC.clear();
			dfs1(order[n - i]);
			for(int node : SCC) col[node]=c;
		}
       }
       cout<<c<<"\n";
       for(ll i=1;i<=n;i++) cout<<col[i]<<" ";
    }
}