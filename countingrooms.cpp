#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
//vector<ll>g[1000001];
//ll vis[1000005]={0};
//ll in[1000005]={0};
//queue<ll>q;
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
}*/
bool vis[10005][10005];
ll n, m;
char a[10001][10001];

bool isValid(ll x , ll y)
{
	if(x < 1 || x > n || y < 1 || y > m) return false;
 
	if(vis[x][y] == true || a[x][y] == '#') return false;
	
	return true;
} 

void dfs(ll i, ll j)
{
       vis[i][j]=true;
       
       if(isValid(i-1,j)) dfs(i-1, j);
       if(isValid(i+1,j)) dfs(i+1, j);
       if(isValid(i,j-1)) dfs(i, j-1);
       if(isValid(i,j+1)) dfs(i, j+1);
}

signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    while(t--)
    {
       cin>>n>>m;
       for(ll i=1;i<=n;i++)
       {
              for(ll j=1;j<=m;j++)
              {
                     cin>>a[i][j];
              }
       }
       ll c=0;
       for(ll i=1;i<=n;i++)
       {
              for(ll j=1;j<=m;j++)
              {
                     if(vis[i][j]==false && a[i][j]=='.')
                     {
                            c++; dfs(i,j); 
                     }
              }
       }
       cout<<c<<"\n";
    }
}