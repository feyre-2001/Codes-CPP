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
ll col[1000001];
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
}
 
signed main() 
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
         ll n;
         cin>>n;
         ll q=n;
         n--;
         while(n--)
         {
                ll u, v;
                cin>>u>>v;
                g[u].pb(v);
                g[v].pb(u);
         }
         ll res=dfs(1,0);
         for(ll i=1;i<q+1;i++)
         {
                if(col[i]==0) col[i]=2;
                cout<<col[i]<<" ";
         }
         for(ll i=0;i<1000005;i++)  vis[i]=0;
         for(ll i=0;i<1000001;i++) col[i]=0;
         for(ll i=0;i<1000001;i++) g[i].clear();
         cout<<"\n";
         
    }
}
