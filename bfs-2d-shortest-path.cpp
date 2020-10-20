#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define INF 1000000000000
using namespace std;
//vector<ll>g[1000001];
//ll vis[1000005]={0};
//ll col[1000001];
//map<ll,ll>y;

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
ll n, m;
char a[1001][1001];
bool vis[1001][1001];
ll dis[1001][1001];
ll rs,cs,rd,cd;
pair<ll,ll> pred[1001][1001];
queue<pair<ll,ll>>q ;
ll bfs()
{
       vis[rs][cs]=true;
       q.push(mp(rs,cs));
       while(!q.empty())
       {
              ll cr=q.front().ff;
              ll cc=q.front().ss;
              q.pop(); 
              
              if(cr==rd && cc==cd) return dis[cr][cc];
              
              if (cr-1>= 0 && vis[cr-1][cc] == false) 
              { 
                     //cout<<"hey"<<" ";
                     dis[cr-1][cc]=dis[cr][cc]+1;
                     q.push(mp(cr- 1, cc)); 
                     vis[cr-1][cc] = true; 
                     pred[cr-1][cc]=mp(cr,cc);
              }
              if (cr + 1 < n && vis[cr + 1][cc] == false)
              { 
                     dis[cr+1][cc]=dis[cr][cc]+1;
                     q.push(mp(cr+ 1, cc)); 
                     vis[cr+1][cc] = true; 
                     pred[cr+1][cc]=mp(cr,cc);
              }
              if (cc-1 >= 0 && vis[cr][cc-1] == false)
              { 
                     dis[cr][cc-1]=dis[cr][cc]+1;
                     q.push(mp(cr, cc-1)); 
                     vis[cr][cc-1] = true; 
                     pred[cr][cc-1]=mp(cr,cc);
              }
              if (cc+1 < m && vis[cr][cc+1] == false)
              { 
                     dis[cr][cc+1]=dis[cr][cc]+1;
                     q.push(mp(cr, cc+1)); 
                     vis[cr][cc+1] = true; 
                     pred[cr][cc+1]=mp(cr,cc);
              }
       }
       return -1; 
}

signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    while(t--)
    {
       
       cin>>n>>m;
       for(ll i=0;i<n;i++){
              for(ll j=0;j<m;j++) cin>>a[i][j];
       }
       for(ll i=0;i<1001;i++)
       {
              for(ll j=0;j<1001;j++) 
              {
                     if(j>=0 &&j<m && i>=0 && i<n)
                     { 
                            if(a[i][j]=='#') vis[i][j]=true;
                            else vis[i][j]=false;  
                            if(a[i][j]=='A') {rs=i,cs=j;}
                            if(a[i][j]=='B') {rd=i,cd=j;}
                     }
                     else vis[i][j]=true;
                     dis[i][j]=MOD;
                     pred[i][j]=mp(-1,-1);
              }
       }
       dis[rs][cs]=0;
       
       ll g=bfs();
       
       if(g==-1)  cout<<"NO\n";
       else
       {
              cout<<"YES\n";
              cout<<g<<"\n";
              string s="";
              ll x=rd, y=cd;
       while(pred[x][y].ff!=-1 && pred[x][y].ss!=-1 )
       {
           //   cout<<x<<" "<<y<<" "<<s<<" ";
              ll k=pred[x][y].ff;
              ll h=pred[x][y].ss;
            //  cout<<k<<" "<<h<<"\n";
              if(x-k==1) {s=s+"D"; }
              if(k-x==1) {s=s+"U"; }
              if(h-y==1) { s=s+"L";}
              if(y-h==1) s=s+"R";
              x=k;y=h;
       }
       /*for(ll i=0;i<n;i++)
       {
              for(ll j=0;j<m;j++)
              {
                     cout<<pred[i][j].ff<<","<<pred[i][j].ss<<" ";
              }
              cout<<"\n";
       }*/
      reverse(s.begin(), s.end()); 
       cout<<s<<"\n";
       }
    }
}