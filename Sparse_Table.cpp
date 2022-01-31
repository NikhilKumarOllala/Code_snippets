#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define int long long
#define ff first 
#define ss second
#define pb push_back
#define mp make_pair
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define print(ve)  for(auto x:ve)cout<<x<<" ";
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  (a*b)/__gcd(a,b)
typedef vector<int> vi;
typedef pair<int,int> pi;
const int mod = 1e9 + 7;
const int64_t INF = 2e18;
const int ep = 1e-9;
 
void io(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
} 

const int MAXN = 205000;
const int MAXLOG = 22;

int n;
vector<int>a(MAXN);
vector<vector<int>>table(MAXLOG,vector<int>(MAXN));
vector<int>logs(MAXN); // logs[i] means such maximum p that 2^p <= i

void computeLogs() {
  logs[1] = 0;
  for (int i = 2; i <= n; i++) {
    logs[i] = logs[i / 2] + 1;
  }
}

void buildSparseTable() {
  for (int i = 0; i <= logs[n]; i++) {
    int curLen = 1 << i; // 2^i
    for (int j = 0; j + curLen <= n; j++) {
      if (curLen == 1) {
        table[i][j] = a[j];
      } else {
        table[i][j] = gcd(table[i - 1][j], table[i - 1][j + (curLen / 2)]);
      }
    }
  }
}

int getGcd(int l, int r) {
  int p = logs[r - l + 1];
  int pLen = 1 << p; // 2^p
  return gcd(table[p][l], table[p][r - pLen + 1]);
}

void solve(){
 cin>>n;
 for(int i=0;i<n;i++){
	 cin>>a[i];
 }
 computeLogs();
 buildSparseTable();
 
}
 
int32_t main()
{   
    IOS;
    int t=1;
    //cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
     return 0;
 
}
 
 
 