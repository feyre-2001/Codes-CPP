#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;
//vector<ll>g[1000001];
//ll vis[1000005]={0};
//ll col[1000001];
//map<ll,ll>y;
//queue<ll>q ;

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
ll dfs(ll curr, ll color)
{
       vis[curr]=1;
       col[curr]=color;
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(vis[child]==0)
              {
                     dfs(child, color^1);
              }
       }
}*/

signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    while(t--)
    {
       ll n, m,k;
       cin>>n>>m>>k;
       vector<pair<ll,ll>>gr[1000005];
       while(m--)
       {
              ll u, v, w;
              cin >> u >> v >> w;
              gr[u].pb(mp(v,w)); 
             // gr[v].pb(mp(u,w));
       }
       
       priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
       
       vector<vector<ll>> dis; 
       dis.resize(n+1);
	for(ll i = 1; i <= n; i++)
	{
		dis[i].resize(k);
		for(ll j = 0; j <k; ++j)
		{
			dis[i][j] = INF;
		}
	}
       dis[1][0]=0;
       
       pq.push(mp(0,1)); //weight node
       
       while(!pq.empty())
       {
              ll cd= pq.top().ff;
              ll curr=pq.top().ss;
       
              pq.pop();
              
              if(dis[curr][k-1]<cd) continue;
              
              for(pair<ll,ll>child : gr[curr])
              {
                     ll v=child.ff;
                     ll c=child.ss;
                     if(dis[v][k-1]>(cd + c))
                     {
                            dis[v][k-1]=cd+c;
                            pq.push(mp(dis[v][k-1],v));
                            sort(dis[v].begin(),dis[v].end());
                     }
              }
       }
       //dis[0]=-1;
       for(int i = 0; i < k; ++i)
	{
		cout << dis[n][i] << " ";
	}
    }
}