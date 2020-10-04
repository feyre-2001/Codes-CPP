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
       ll n,m;
       cin>>n>>m;
       ll a[n][m];
       for(ll i=0;i<n;i++)
       {
           for(ll j=0;j<m;j++) 
           {
               cin>>a[i][j];
           }
       }
       
       ll s=0;
       
       for(ll i=0;i<n/2;i++)
       {
           for(ll j=0;j<m/2;j++)
           {
                
                ll e1=0,e2=0,e3=0,e4=0;
               
                e1=e1+abs(a[i][j]-a[i][m-j-1]);
                e1=e1+abs(a[i][j]-a[n-i-1][j]);
                e1=e1+abs(a[i][j]-a[n-i-1][m-j-1]);
                
                e2=e2+abs(a[i][m-j-1]-a[i][j]);
                e2=e2+abs(a[i][m-j-1]-a[n-i-1][j]);
                e2=e2+abs(a[i][m-j-1]-a[n-i-1][m-j-1]);
                
                e3=e3+abs(a[n-i-1][j]-a[i][j]);
                e3=e3+abs(a[n-i-1][j]-a[n-i-1][m-j-1]);
                e3=e3+abs(a[n-i-1][j]-a[i][m-j-1]);
                
                e4=e4+abs(a[n-i-1][m-j-1]-a[i][j]);
                e4=e4+abs(a[n-i-1][m-j-1]-a[n-i-1][j]);
                e4=e4+abs(a[n-i-1][m-j-1]-a[i][m-j-1]);
                
                s=s+min(e1,min(e2,min(e3,e4)));
           }
       }
       if(n%2!=0)
       {
           ll nahi=n/2;
           for(ll i=0;i<m/2;i++)
           {
               s=s+abs(a[nahi][i]-a[nahi][m-i-1]);
           }
       }
       if(m%2!=0)
       {
           ll nahi=m/2;
           for(ll i=0;i<n/2;i++)
           {
               s=s+abs(a[i][nahi]-a[n-i-1][nahi]);
           }
       }
       cout<<s<<"\n";
    }
}