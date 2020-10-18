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
    ll t=1;
    //cin>>t;
    while(t--)
    {
           string s;
           cin>>s;
           ll flag=1;
          // for(ll i=0;i<s.size();i++)
          // {
          //        if(s[i] != s[s.size()-i-1]){flag = 1;break;}
         //  }
           if (flag == 1)
           {
                         ll p=s.size();
                         
                         p=p+(p-2);
                         ll k=p-1;
                        // s1=s1+s1[s1.size()-2];
                         ll g=k+1;
                         ll f=1;
                         //for(ll i=0;i<s1.size() ;i++)
                         //{
                          //      if(s1[i] != s[s1.size()-i-1]){f= 1;break;}
                         //}
                         if(f)
                         {
                                cout<<"4\n";
                                cout<<"R 2"<<"\n";
                                cout<<"R "<<k<<"\n";
                                cout<<"L "<<g<<"\n";
                                cout<<"L 2\n";
                         }
           }
           else cout<<"0\n";
    }
}