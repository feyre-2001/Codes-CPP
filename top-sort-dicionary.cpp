#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;
vector<ll>g[1001];
ll vis[1005]={0};
ll vis2[1005]={0};
ll recStack[1005]={0};
//map<ll,ll>y;
queue<ll>q ;
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
vector<ll> ans;
bool iscycle(ll v)
{
       if(vis2[v]==false)
       {
              vis2[v] = true; recStack[v] = true;
             for(ll i=0;i<g[v].size();i++)
             {
                    ll child=g[v][i];
                    if ( !vis2[child] && iscycle(child)) return true; 
                    else if (recStack[child]) return true; 
             } 
       }
       recStack[v] = false;
       return false;
}
void top(ll v)
{
       vis[v] = true;
       for(ll i=0;i<g[v].size();i++)
       {
              ll child=g[v][i];
              if(vis[child]==0)
              {
                     top(child);
              }
       }
       ans.pb(v);
}
signed main() 
{
    fast
    ll t=1;
  //  cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<string>s;
        ll temp=n;
        while(temp--)
        {
               string str;
               cin>> str;
               s.pb(str);
        }
        ll flag=0;
        for (ll i = 0; i < n-1; i++) 
        { 
               string word1 = s[i], word2 = s[i+1]; 
               flag=0;
               for (ll j = 0; j < min(word1.length(), word2.length()); j++) 
               { 
                      if (word1[j] != word2[j]) 
                      { 
                            // cout<<word1[j]<<" "<<word2[j]<<"\n";
                             g[word1[j]-'a'].pb(word2[j]-'a'); 
                             flag=1;
                             break; 
                      } 
               } 
               if (word1.size()>word2.size() && !flag) {cout<<"Impossible"; return 0;}
        } 
        ll cycle=0;
        for(ll i = 0; i <26; i++) 
        {
              if (iscycle(i)) cycle=1;
        }
        if(cycle==1) {cout<<"Impossible"; return 0;}
        for(ll i=0;i<26;i++)
        {
               if(vis[i]==false) 
               {
                      top(i);
               }
        }
        reverse(ans.begin(), ans.end());
        for(ll i=0;i<ans.size();i++)
        {
               cout<<(char)('a'+ans[i]);
        }
    }
}