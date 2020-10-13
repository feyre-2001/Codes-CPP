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
int find(int x, int par[])
{
    if (x == par[x]) return x; 
    return par[x] = find(par[x], par); 
}
void union1(int x, int y, int par[])
{
    par[y]=x;
}
signed main() 
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int>>v;
        ll n; cin>>n;
        ll md=0;
        vector<ll>ans;
        while(n--)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            md=max(md,b);
            v.pb(mp(c,b));
        }
        sort(v.rbegin(), v.rend());
        int par[md+1];
        for(ll i=0;i<md+1;i++) par[i]=i;
        for(ll i=0;i<v.size();i++)
        {
            int x= find(v[i].second, par);
            if(x>0)
            {
                int f=find(x, par);
                int g=find(x-1, par);
                union1( g , f , par);
                ans.pb(v[i].first);
            }
        }
        int sum=0;
        for(int i=0;i<ans.size();i++) sum=sum+ans[i];
        cout<<ans.size()<<" "<<sum<<"\n";
    }
}