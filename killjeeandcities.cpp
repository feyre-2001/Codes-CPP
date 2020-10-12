#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
//ector<ll>g[1000001];
//ll vis[1000005]={0};
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
ll dfs(ll curr)
{
       vis[curr]=1;
       for(ll i=0;i<g[curr].size();i++)
       {
              ll child=g[curr][i];
              if(vis[child]==0)
              {
                     dfs(child);
              }
       }
}*/
int rnk[1000005],par[1000005];
int findparent(int val)
{
	if(par[val]==val)return val;
	return par[val]=findparent(par[val]);
}
void makeunion(int a,int b)
{
	int para=findparent(a);
	int parb=findparent(b);
	if(para==parb)return;
	else
	{
		if(rnk[para]<rnk[parb])
			par[parb]=para;
		else if(rnk[parb]<rnk[para])
			par[para]=parb;
		else
		{
			par[parb]=para;
			rnk[para]++;
		}
	}
}
signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    while(t--)
    {
      for(int i=1;i<=1000000;i++)par[i]=i;
      ll n,m;
      cin>>n>>m;
      ll s; cin>>s;
      while(m--)
      {
          ll a,b;
          cin>>a>>b;
          makeunion(a,b);
      }
      ll c=0;
      for(int i=1;i<=n;i++)if(par[i]==i)c++;
      ll q;
      cin>>q;
      ll s1; cin>>s1;
      while(q--)
      {
              ll a,b;
              cin>>a>>b;
              if(findparent(a)!=findparent(b)){makeunion(a,b);c--;}
		cout<<c-1<<" ";
      }
 
    }
}