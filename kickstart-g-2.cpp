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
signed main() 
{
    fast
    ll t;
    cin>>t;
    for(ll op=1;op<=t;op++)
    {
         ll n;
         cin>>n;
         ll a[n][n];
         for(ll i=0;i<n;i++)
         {
                for(ll j=0;j<n;j++)
                {
                       cin>>a[i][j];
                }
         }
         vector<ll>v;
         for(ll i=0;i<n;i++)
         {
                ll s=0,k=0;
                for(ll j=i;j<n && k<n ;j++)
                {
                       s=s+a[k][j];
                       k++;
                }
                v.pb(s);
         }
         for(ll i=0;i<n;i++)
         {
                ll s=0,k=0;
                for(ll j=i;j<n && k<n ;j++)
                {
                       s=s+a[j][k];
                       k++;
                }
                v.pb(s);
         }
        // for(ll i=0;i<v.size();i++) cout<<v[i]<<" ";
         sort(v.begin(),v.end());
         cout<<"Case #"<<op<<": "<<v[v.size()-1]<<"\n";
    }
}