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
ll tree[1000000];
ll arr[200001];
void build(ll s, ll e, ll idx)
{
       if(s>e) return;
       else if(s==e){  tree[idx]=arr[e]; return;}
       else
       {
              ll mid=(s+e)/2;
              build(s, mid, 2*idx);
              build(mid+1 , e, 2*idx+1);
              tree[idx] = (tree[2*idx]+tree[2*idx+1]);
       }
}
void nodeupdate(ll s, ll e, ll value, ll idx, ll index)
{
       if(e==s && e==index) { tree[idx]=value; return;}
       else if(index>e || s>index || s>e) return;
       else
       {
              ll mid=(s+e)/2;
              nodeupdate(s, mid, value, 2*idx, index);
              nodeupdate(mid+1, e, value, 2*idx+1, index);
              tree[idx] = (tree[2*idx]+tree[2*idx+1]);
       }
}
ll queries(ll s, ll e, ll qs, ll qe, ll idx)
{
       if(s>= qs && qe>=e) return tree[idx];
       else if(s>qe || e<qs) return 0;
       else
       {
              ll mid=(e+s)/2;
              ll ql=queries(s, mid, qs, qe, 2*idx);
              ll qr=queries(mid+1,e , qs, qe, 2*idx+1);
              return (ql+qr);
       }
}
signed main() 
{
    fast
    ll t=1;
   // cin>>t;
    while(t--)
    {
       ll n,q;
       cin>>n>>q;
       for(ll i=1;i<=n;i++) cin>>arr[i];
       build(1,n,1);
       while(q--)
       {
              ll p,a,b;
              cin>>p>>a>>b;
              if(p==1) nodeupdate(1,n,b,1,a); 
              else cout<<queries(1,n,a,b,1)<<"\n";
       }
    }
}