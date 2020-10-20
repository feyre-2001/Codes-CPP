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
const ll di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
const char dc[4]={'D','R','U','L'} ;
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
ll si,sj,ti,tj;
queue<array<ll,2>>q ;
string p[1001];

void bfs()
{
       vis[si][sj]=true;
       q.push({si,sj});
       while(!q.empty())
       {
              array <ll,2>u =q.front();
              q.pop(); 
              for(ll k=0;k<4;k++)
              {
                     ll ni=u[0]+di[k];
                     ll nj=u[1]+dj[k];
                     if(!(ni<n && ni>=0 && nj<m && nj>=0 && a[ni][nj]=='.' && vis[ni][nj]==false)) continue ;
                     
                     q.push({ni,nj});
                     
                     dis[ni][nj]=k;
                     vis[ni][nj]=true;
                     p[ni][nj]=dc[k];
              }
       }
}

signed main() 
{
    fast
    ll t=1;
    //cin>>t;
    while(t--)
    {
       cin>>n>>m;
       for(ll i=0;i<n;i++)
       {
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
                            if(a[i][j]=='A') {si=i,sj=j; a[i][j]='.';}
                            if(a[i][j]=='B') {ti=i,tj=j;a[i][j]='.';}
                     }
                     else vis[i][j]=true;
                     dis[i][j]=MOD;
                     p[i]=string(m,0);
              }
       }
       
       bfs();
       
       if(p[ti][tj])
       {
              string t;
              cout << "YES"<< endl ;
              while(si^ti || sj^tj)
              {
                     t+=p[ti][tj] ;
                     ll dd=dis[ti][tj]^2;
                     ti+=di[dd];
                     tj+=dj[dd];
              }   
              reverse(t.begin(),t.end());
              cout << t.size() <<"\n";
              cout << t;
       }
       else cout<<"NO\n";
    }
}