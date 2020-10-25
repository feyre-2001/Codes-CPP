#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define ff first
#define ss second
using namespace std;
const ll INF = 1000000000000000000;
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
        ll n,m;
        cin>>n>>m;
        ll e[m][3];
        vector<ll> d (n); 
        vector<ll> p (n);
        d[0]=0;
        for(ll i=0;i<m;i++)
        {
               ll u,v,w;
               cin>>u>>v>>w;
               u--; v--;
               e[i][0]=w; e[i][1]=u; e[i][2]=v;
        }
        ll y;
        for(ll i=0;i<n;i++)
        {
               y = -1;
               for(ll j=0;j<m;j++)
               {
                     ll a=e[j][1];
                     ll b= e[j][2];
                     ll cost=e[j][0];
                   //  if (d[a] < INF)      
                    // {
                         //  cout<<a<<" "<<b<<" "<<cost<<"\n";
                            if (d[b] > d[a] + cost)
                            {
                                   d[b] = max (-INF, d[a] + cost);
                                   p[b] = a;
                                   y=b;
                            }
                    // }
               }
        }
        if(y!=-1)
        {
               cout<<"YES\n";
               ll z = y;
               for (ll i=0; i<n; ++i) z = p[z];
 
              vector<ll> path;
              for (ll cur=z; ; cur=p[cur])
              {
                path.pb(cur);
                if (cur == z && path.size() > 1) break;
              }
              reverse (path.begin(), path.end());
              for (ll i=0; i<path.size(); ++i) cout <<path[i]+1<< ' ';
        }
        else cout<<"NO\n";
    }
}