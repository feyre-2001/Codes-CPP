#include <bits/stdc++.h> 
#include <algorithm>  
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(long long int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
//vector<ll>g[1000001];
//ll vis[1000005]={0};
//ll in[1000005]={0};
queue<ll>q;
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

int dx[] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
int dy[] = { 1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};
int vis[10][10] , dist[10][10];
int targetX , targetY;

bool isValid(int x , int y)
{
	if(x < 1 || x > 8 || y < 1 || y > 8) return false;
	
	if(vis[x][y] == 1) return false;
	
	return true;
}

ll bfs(ll x, ll y)
{
       queue<pair<int,int> > q;
	dist[x][y] = 0;
	vis[x][y] = 1;
	q.push({x , y});
	
	if(x == targetX && y == targetY) return dist[x][y];
	
	while(!q.empty())
	{
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		
		for(int i=0;i<8;i++)
		if(isValid(curr_x + dx[i] , curr_y + dy[i]))
		{
			x = curr_x + dx[i];
			y = curr_y + dy[i];
			
			dist[x][y] = dist[curr_x][curr_y] + 1;
			vis[x][y] = 1;
			q.push({x , y});
			
			if(x == targetX && y == targetY) return dist[x][y];
		}
	}
}

void dfs(ll i, ll j)
{
       vis[i][j]=true;
       
       if(isValid(i-1,j)) dfs(i-1, j);
       if(isValid(i+1,j)) dfs(i+1, j);
       if(isValid(i,j-1)) dfs(i, j-1);
       if(isValid(i,j+1)) dfs(i, j+1);
}

signed main() 
{
    fast
    ll t,x,y;
    cin>>t;
    while(t--)
    {
	char a , b;
		
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++)
			vis[i][j] = 0;
	}
		
	cin>>a>>b;
	x = a-'a'+1;
	y = b - '0';
		
	cin>>a>>b;
	targetX = a-'a'+1;
	targetY = b - '0';
		
	cout<<bfs(x , y)<<endl;
    }
}