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
    //cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       ll a=0,ti=0,g=0,c=0;
       vector<ll>v;
       char temp=s[0];
       if(s[0]=='A') a++; else if(s[0]=='G') g++; else if(s[0]=='C') c++; else ti++;
       for(int i=1;i<s.size();i++)
       {
              if(s[i]=='A') 
              {
                     if(temp==s[i]) {a++; temp='A';}
                     else {a=1; temp='A';v.pb(ti); ti=0; v.pb(g);g=0; v.pb(c); c=0;}
              }
              else if(s[i]=='G') 
              {
                     if(temp==s[i]) {g++; temp='G';}
                     else {g=1; temp='G';v.pb(ti); ti=0; v.pb(a);a=0; v.pb(c); c=0;}
              }
              else if(s[i]=='C') 
              {
                     if(temp==s[i]) {c++; temp='C';}
                     else {c=1; temp='C';v.pb(ti); ti=0; v.pb(g);g=0; v.pb(a); a=0;}
              }
              else
              {
                     if(temp==s[i]) {ti++; temp='T';}
                     else {ti=1; temp='T';v.pb(a); a=0; v.pb(g);g=0; v.pb(c); c=0;}
              }
       }
       v.pb(ti); v.pb(g); v.pb(c); v.pb(a);
       sort(v.begin(),v.end());
       cout<<v[v.size()-1];
    }
}