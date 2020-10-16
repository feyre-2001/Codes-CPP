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
/*map<ll,ll>y;
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
ll co=0;*/
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
}
ll par[1000001];

ll find(ll x) 
{
        if(par[x]==-1) return x;
		else return par[x]=find(par[x]);
} 
void Union(ll x, ll y) 
{  
	ll p = find(x);
    ll q = find(y);
	par[p] = q; 
}
signed main() 
{
    fast
    ll t=1;
    //cin>>t;
	for(ll i=0;i<1000001;i++) par[i]=-1;
    while(t--)
    {
		ll n, m, k;
		cin>>n>>m>>k;
		ll temp=m, s=0,f=0;
		vector< pair <ll,pair <ll,ll> > > v;
		while(m--)
		{
			ll a,b,w;
			cin>>a>>b>>w;
            g[a].pb(b);
            g[b].pb(a);
            s=s+w;
			v.pb(mp(w,mp(a,b)));
		} 
        dfs(1);
        for(ll i=1;i<=n;i++)
        {
            if(vis[i]==0) f=1;
        }
        if(s<=k) cout<<"0\n";
        else if(f==1) cout<<"-1\n";
        else
        {
            sort(v.begin(),v.end());
            ll sum=0; 
            vector<ll>op;
            for(ll i=0;i<v.size();i++)
            {
                ll x = v[i].second.first;
                ll y = v[i].second.second;
                ll cost = v[i].first;
                if(find(x)!=find(y))
                {
                    Union(x,y);
                    sum=sum+cost;
                    op.pb(cost);
                }
			}
            if(sum<=k) cout<<"0\n";
            else if(k<op.size()) cout<<"-1\n";
            else
            {
                sort(op.begin(),op.end());
                ll c=0, j=op.size()-1;
                for(;;)
                {
                    if(sum>k)
                    {
                        sum=sum-op[j]+1;
                        c++; j--;
                    }
                    else break;
                }
                cout<<c<<"\n";
            }
        }
    }
}