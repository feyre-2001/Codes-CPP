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
ll par[1501];

ll find(ll x) 
{
        if(par[x]==-1) return x;
		else return par[x]=find(par[x]);
} 
void Union(ll x, ll y) 
{  
	ll p = find(x);
    ll q = find(y);
	par[p] = q; 
}
signed main() 
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<1501;i++) par[i]=-1;
		ll n, m;
		cin>>n>>m;
		ll temp=m;
		vector< pair <pair <ll,ll> ,pair <ll,ll> > > v;
		for(ll i=1;i<=m;i++)
		{
			ll a,b,w;
			cin>>a>>b>>w;
            ll p=log(w);
			v.pb(mp(mp(p,w),mp(a,b)));
		} 

        sort(v.begin(),v.end());
		ll sum=1; 

		for(ll i=0;i<v.size();i++)
		{
			ll x = v[i].second.first;
            ll y = v[i].second.second;
            ll cost = v[i].first.second;
			if(find(x)!=find(y))
			{
				Union(x,y);
				sum=((sum%MOD)*(cost%MOD))%MOD;
			}
		}
		cout<<sum%MOD<<"\n";
    }
}

