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
ll par[1001];
ll find(ll x)
{
	if (par[x]!=x) par[x]=find(par[x]); 
	return par[x];
}
void union1(ll x, ll y)
{
	x=find(x); y=find(y);
	if(x!=y) par[x]=y;
}
signed main() 
{
    fast
    ll t=1;
    //cin>>t;
	for(ll i=1;i<1001;i++) par[i]=i;
    while(t--)
    {
        ll n; cin>>n;
        ll e[n+1];
        for(ll i=1;i<=n;i++) cin>>e[i];
        ll q;
        cin>>q;
		while(q--)
		{
			ll a, b;
            cin>>a>>b;
            union1(a,b);
		}
        for(ll i=1;i<=n;i++) par[i]=find(i);
        vector<ll>v[n+1];
        for(ll i=1;i<=n;i++)
        {
            v[par[i]].pb(i);
        }
        vector<ll>ans;
        for(ll i=1;i<n+1;i++)
        {
             ll mn=1001;
            if(v[i].size()!=0)
            {
                ll c=0;
                for(ll j=0;j<v[i].size();j++)
                {
                    mn=min(e[v[i][j]],mn);
                }
                for(ll j=0;j<v[i].size();j++)
                {
                    if(mn==e[v[i][j]]) c++;
                }
                if(c!=0) ans.pb(c);
            }
        }
        ll res=1;
        for(ll i=0;i<ans.size();i++) res=(ans[i]*res)%MOD;
        cout<<res<<"\n";
    }
}