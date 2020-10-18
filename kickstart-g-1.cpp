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
signed main() 
{
    fast
    ll t;
    cin>>t;
    for(ll op=1;op<=t;op++)
    {
         string s;
         cin>>s;
         string k = "KICK";
         string end= "START";
         ll pos =0;
         ll index;
         vector<ll> st,en;
         while((index = s.find(k, pos)) != string::npos) 
         {
                st.pb(index);
                //cout << "Match found at position: " << index << endl;
                pos = index + 1;
         }
         ll pos1 = 0;ll index1;
         while((index1 = s.find(end, pos1)) != string::npos) 
         {
                en.pb(index1);
                //cout << "Match found at position: " << index << endl;
                pos1 = index1 + 1; 
         }
         sort(st.begin(),st.end());
         sort(en.begin(),en.end());
         ll c=0;
         for(ll i=0;i<st.size();i++)
         {
                for(ll j=0;j<en.size();j++)
                {
                       if(st[i]<en[j]) c++;
                }
         }
         cout<<"Case #"<<op<<": "<<c<<"\n";
    }
}