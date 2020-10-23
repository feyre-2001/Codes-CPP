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
       ll n, m;
       cin>>n>>m;
       vector<pair<ll,ll>>gr[1000005];
       while(m--)
       {
              ll u, v, w;
              cin >> u >> v >> w;
              gr[u].pb(mp(v,w)); 
       }
       
      
       ll dist[n+1],disc[n+1];
       for(ll i=0;i<n+1;i++) {dist[i]=INF; disc[i]=INF;}
       
       dist[1]=0;
       
       priority_queue< 
	pair<ll, pair<ll,ll>>, 
	vector<pair<ll, pair<ll,ll>>>,
	greater<pair<ll, pair<ll,ll>>>> pq;
	
       pq.push({0,{1,0}}); //cost dest flag 
       
       while(!pq.empty())
       {
              ll d=pq.top().ff;
              ll u=pq.top().second.first;
              ll f=pq.top().second.second;
              
              pq.pop();
              
              if(f)
              {
                     if(disc[u]<d) continue;
              }
              if(!f)
              {
                     if(dist[u]<d) continue;
              }
              //if(cd!=dis[curr]) continue; 
              
              for(pair<ll,ll>child : gr[u])
              {
                     ll v=child.ff;
                     ll c=child.ss;
                     
                     if(f==0)
                     {
                            if(dist[v] > c + d) 
				{
					dist[v] = c+d;
					pq.push({dist[v], {v,0}});
				}
				if(disc[v] > d + c/2) 
				{
					disc[v] = d + c/2;
					pq.push({disc[v], {v,1}});	
				}
                     }
                     if(f==1)
                     {
                            if(disc[v] > d + c)
				{
					disc[v] = d + c;
					pq.push({disc[v], {v,1}});	
				}
                     }
              }
       }
       cout<<disc[n]<<"\n";
    }
}