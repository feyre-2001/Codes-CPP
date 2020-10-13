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
ll par[100001];
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
    ll t;
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<100001;i++) par[i]=i;
        ll n,q; cin>>n>>q;
        ll yes=0,no=0;
		while(q--)
		{
			char s; cin>>s;
			if(s=='J')
			{
				ll a,b;
				cin>>a>>b;
				union1(a,b);
			}
			else if(s=='?')
			{
				ll a,b;
				cin>>a>>b;
                if(find(a)==find(b)) yes++;
                else no++;
			}
		}
        cout<<yes<<" "<<no<<"\n";
    }
}