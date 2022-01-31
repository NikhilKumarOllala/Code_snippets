#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define int long long
#define ff first 
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(ve)  for(auto x:ve)cout<<x<<" ";
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  (a*b)/__gcd(a,b)
const int mod = 1e9 + 7; 
const int64_t INF = 2e18;
const int N = 2e5 + 5;
const int ep = 1e-9;
 
void io(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
} 

int row[8]={-1,1,0,0,-1,-1,1,1};
int col[8]={0,0,-1,1,-1,1,-1,1};

struct DSU
{
	int connected;
	vector<int> par, sz;

	void init(int n) 
	{
		par = sz = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}

	int getPar(int u)
	{
		while(u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}

	int getSize(int u)
	{
		return sz[getPar(u)];
	}

	void unite(int u, int v)
	{
		int par1 = getPar(u), par2 = getPar(v);

		if(par1 == par2)
			return;

		connected--;

		if(sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};


void solve(){
 
}

int32_t main()
{   
    IOS;
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
       solve();
       cout<<endl;
     }
    return 0;
 
}
