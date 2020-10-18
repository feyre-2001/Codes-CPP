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
    while(t--)
    {
       ll n;
       cin>>n;
       char a[n][n];
       for(ll i=0;i<n;i++)
       {
              for(ll j=0;j<n;j++) cin>>a[i][j];
       }
       ll x=0;
       vector<ll>r; vector<ll>co;
       ll am=(ll)a[0][1]-'0'; ll b=(ll)a[1][0]-'0';
       ll c=(ll)a[n-1][n-2]-'0'; ll d=(ll)a[n-2][n-1]-'0';
       
       if(am==1)
       {
              if(b==1)
              {
                     if(c==1) {x++; r.pb(n-1); co.pb(n-2);}
                     if(d==1) {x++; r.pb(n-2); co.pb(n-1);}
              }
              else
              {
                     if(c==1)
                     {
                            if(d==1) { x++; r.pb(0); co.pb(1);}
                            else 
                            {
                                   x=x+2;
                                   r.pb(1); co.pb(0);
                                   r.pb(n-1); co.pb(n-2);
                            }
                     }
                     else
                     {
                            if(d==0) { x++; r.pb(1); co.pb(0);}
                            else 
                            {
                                   x=x+2;
                                   r.pb(0); co.pb(1);
                                   r.pb(n-1); co.pb(n-2);
                            }
                     }
              }
       }
       else
       {
              if(b==0)
              {
                     if(c==0) {x++; r.pb(n-1); co.pb(n-2);}
                     if(d==0) {x++;r.pb(n-2); co.pb(n-1);}
              }
              else
              {
                     if(c==0)
                     {
                            if(d==0) { x++; r.pb(0); co.pb(1);}
                            else 
                            {
                                   x=x+2;
                                   r.pb(1); co.pb(0);
                                   r.pb(n-1); co.pb(n-2);
                            }
                     }
                     else
                     {
                            if(d==1) { x++; r.pb(1); co.pb(0);}
                            else 
                            {
                                   x=x+2;
                                   r.pb(0); co.pb(1);
                                   r.pb(n-1); co.pb(n-2);
                            }
                     }
              }
       }
       
       cout<<x<<"\n";
       for(ll i=0;i<r.size();i++)
       {
              cout<<r[i]+1<<" "<<co[i]+1<<"\n";
       }
    }
}