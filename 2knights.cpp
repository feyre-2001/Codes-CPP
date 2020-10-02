
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
    ll t=1;
   // cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       for(ll i=1;i<=n;i++)
       {
              if(i==1) cout<<"0\n";
              else
              {
                     ll q=((i*i)*(i*i-1))/2;
                     ll r=2*(i-2)*(2*(i-2)+2);
                     cout<<q-r<<"\n";
              }
       }
    }
=======
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
    ll t=1;
   // cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       for(ll i=1;i<=n;i++)
       {
              if(i==1) cout<<"0\n";
              else
              {
                     ll q=((i*i)*(i*i-1))/2;
                     ll r=2*(i-2)*(2*(i-2)+2);
                     cout<<q-r<<"\n";
              }
       }
    }
}