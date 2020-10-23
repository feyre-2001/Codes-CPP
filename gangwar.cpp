
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
ll prime[100002];
ll exp(ll a,ll b);
void sieve(ll n);
ll gcd(ll a ,ll b);
ll countdigit(ll n);
ll check(string str);
vector<ll>ft;

ll mul(ll a, ll b){
    ll ans= ((a%mod)*(b%mod))%mod;
    return ans%mod;
}
ll sub(ll a, ll b){
    ll ans = (a-b+mod)%mod;
    return ans;
}
ll add(ll a,ll b){
    ll ans = (a+b)%mod;
    return ans;
}
ll fun(ll number) 
{     
      return (ll)log2(number)+1; 
} 
vector<ll>g[1000001];
ll vis1[100005]={0};
ll vis2[100005]={0};
ll dis[100005]={0};
ll p[100001];
ll col[1000005];
ll cnt=0;
void dfs1(ll curr,ll par) {
    vis1[curr]=1;
    dis[curr]=dis[par]+1;
      for(ll i=0;i<g[curr].size();i++) {
        ll child=g[curr][i];
        if(vis1[child]==0){
            dfs1(child,curr);
        }
    }
}

ll dfs2(ll curr,ll c) {
    vis2[curr] = 1;
    col[curr] = c;
    for(ll child:g[curr]) {
        if(vis2[child] == 0) {
            ll temp = dfs2(child,c^1);
            if(temp == 0) {
                return 0;
            }
        } 
        else {
            if(col[curr]==col[child]) {
                return 0;
            }
        }
    }
    return 1;
}
void solve(){
        ll n;
        cin >> n;
        ll q;
        cin >> q;
        rep(i,0,q){
            ll a,b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
            p[b]=p[a];
        }
        ll ans = 0;
        for(ll i=1;i<=n;i++) {
            if(vis2[i]==0){
                ans=dfs2(i,0);
               // /cout<<i<<" ";
               // cout<<ans<<" ";
                if(ans==0)break;
            }
        }
        if(ans==0)cout<<"No\n";
        else cout<<"YeS\n";
        
        rep(i,0,n+1)col[i]=100;
        rep(i,0,n+1)vis2[i]=0;
        for(ll i=0;i<=n;i++){
            g[i].clear();
        }
}
int main()
{   
    flash;
    ll t=1;
    //ft.pb(1);
    //fact(10000001);
    cin >> t;
    while(t--) { 
        solve();
    }
}
