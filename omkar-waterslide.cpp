#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
ll power(ll x, unsigned ll y, ll p)  
{  
    int res = 1;    
    x = x % p; 
    if (x == 0) return 0; 
    while (y>0)  
    {  
        if (y&1) res=(res*x) % p;  
        y = y>>1;
        x=(x*x)%p;  
    }  
    return res;  
}  
signed main() 
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],b[n];
        for(ll i=0;i<n;i++) 
        { 
            cin>>a[i]; 
        }
        b[0]=0;
        for(ll i=1;i<n;i++)
        {
            b[i]=a[i]-a[i-1];
        }
        int f=0;
        ll s=0;
        for(ll i=0;i<n;i++)
        {
            //cout<<b[i]<<" ";
            if(b[i]<0)
            {
                s=s+abs(b[i]);
            }
        }
        cout<<s<<"\n";
    }
}