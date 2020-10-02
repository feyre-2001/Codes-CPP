#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef long double ld;
const int inf = 1e9 + 7;
const int mod = 998244353;
const int maxn = 1e6 + 3;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define lb lower_bound
#define ub upper_bound
#define fact(n) rep(i, 1, n+1)ft.pb((ft[i-1]*i)%mod);
#define mod_in(a) exp(a, mod-2)
#define ncr(n, r) ((ft[n]*mod_in((ft[r]*ft[(n)-(r)])%mod))%mod)
#define deb(x) cout << #x << " " << x << endl;
#define flash ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
vector<ll>g[1000001];
ll vis1[100005]={0};
ll vis2[100005]={0};
ll dis[100005]={0};
ll s[100001];
ll ans[100001];
 
ll cnt=0;
void dfs1(ll curr,ll par) 
{
    vis1[curr]=1;
    dis[curr]=dis[par]+1;
      for(ll i=0;i<g[curr].size();i++) 
      {
        ll child=g[curr][i];
        if(vis1[child]==0)
        {
            dfs1(child,curr);
        }
    }
}
 
void solve(){
        ll n;
        cin >> n;
        ll p[n+1];
        p[1]=0;
        rep(i,2,n+1)
        {
            ll a;
            cin >> a;
            g[a].pb(i);
            p[i]=a;
        }
        rep(i,1,n+1)
        {
            ll b;
            cin >> b;
            s[i]=b;
        }
        dis[0]=0;
        dis[1]=1;
        dfs1(1,0);;
       ans[1] = s[1];
        for(ll curr=1;curr<=n;curr++) 
        {
            ll mn = inf;
            if(s[curr]==-1) {
                for(ll i=0;i<g[curr].size();i++) 
                {
                    ll child = g[curr][i];
                    if(child != p[curr])  mn = min(s[child],mn);
                }
             if(mn==inf)
             {
                 if(dis[curr]%2==0) 
                 {
                     ans[curr]=0;
                 }
                 else 
                 {
                     ans[curr]=s[curr]-s[p[curr]];
                 }
                 continue;
             }    
             if(curr != 1) ans[curr] = mn - s[p[curr]];
             if(curr != 1) s[curr] = s[p[curr]]+ans[curr];
            }
            else 
            {
                ans[curr] = s[curr]-s[p[curr]];
            }
        }
        ll sol=0;
        rep(i,1,n+1) 
        {
            sol+=ans[i];
            if(ans[i]<0){sol=-1;break;}
        }
        cout << sol << endl;
}
int main()
{   
    flash;
    ll t=1;
    //ft.pb(1);
    //fact(10000001);
    //cin >> t;
    while(t--) 
    { 
        solve();
    }
}