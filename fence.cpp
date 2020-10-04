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
queue<ll>q;
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
ll ans=0, n ,m ;
ll a[1000005];
void dfs(ll curr, ll prev)
{
       vis[curr]=1;
       ll co;
       if(a[curr]==1) { co=prev+1; }
       else co=0;
       
       if(co>m) return;
       
       if(g[curr].size()==1 && curr!=1) 
       {
              //cout<<curr<<"\n";
              ans++;
       }
       
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(vis[child]==0)
              {
                     dfs(child, co);
              }
       }
}*/
signed main() 
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
       ll a, b, c;
       cin>>a>>b>>c;
       ll s= ceil(sqrt(a*a+((b-c)*(b-c))));
       cout<<s<<"\n";
    }
}