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
const int mod = 1e9+7;
const int64_t INF = 2e18;
const int MAX = 2e9;
const int N = 2e5 + 5;
const int ep = 1e-9;


int power(int x,int y, int p)
{
    int res = 1; 
    x = x % p; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 

int modInverse(int n,int p)
{
    return power(n, p - 2, p);
}

int nCr(int n,int r, int p)
{
  
    if (n < r)
        return 0;
   
    if (r == 0)
        return 1;

    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
 
void solve(){
   int n;
   cin>>n;
   int ans = nCr(n/3,n/6,mod);
   //cout<<ans<< " ";
   for(int i=0;i<n/3;i++){
    vector<int>v(3);
    cin>>v[0]>>v[1]>>v[2];
    sort(all(v));
    if(v[0] == v[2]){
        ans = ((ans%mod)*3)%mod;
    }
    else if(v[0]==v[1]){
        ans = ((ans%mod)*2)%mod;
    }
   }
   cout<<ans;
}
 
int32_t main()
{   
    IOS;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cout<<endl;
     }
     return 0;
 
}