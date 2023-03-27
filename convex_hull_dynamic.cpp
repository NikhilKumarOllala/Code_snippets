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



const int is_query = -(1ll<<62);
struct line {
    int m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        int x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
 
// this is for maximum
// for minimum, just negate the slope and constant in input and take the negative of output
struct CHT : public multiset<line> { // wiint maintain upper huint for maximum
    const int inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
 
		/* compare two lines by slope, make sure denominator is not 0 */
        int v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        int v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(int m, int b) {
        auto y = insert({m,b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    int eval(int x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
};
 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>h(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
        sort(all(h));
 
    // original dp relation : dp[i] = min(dp[i], dp[j]+(hi-hj)^2+C)
    // expanding it : dp[j] + hi^2 + hj^2 - 2*hi*hj + C
    // slope of the line: -2*hj
    // constant : hj^2 + dp[j] 
    vector<vector<int> >dp(n,vector<int>(k+1,0));
    CHT prev;
    prev.insert(2*h[0],-(h[0]*h[0]));
    for(int i=1;i<n;i++){
        dp[i][1] = (h[i]-h[0])*(h[i]-h[0]);
        prev.insert(2*h[i],-(h[i]*h[i]+dp[i-1][1]));
    }
    
    int ans = dp[n-1][1];
    for(int p=2;p<=k;p++){
       CHT curr;
       curr.insert(-2*h[0], h[0]*h[0]);
       for(int i=1;i<n;i++){
           dp[i][p] = -prev.eval(h[i])+h[i]*h[i];
           curr.insert(2*h[i],-(h[i]*h[i]+dp[i-1][p]));
       }
       swap(prev,curr);
       ans = min(ans,dp[n-1][p]);
    }
    cout<<ans;

}

int32_t main()
{   
    IOS;
    //io();
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
     {
        solve();
        cout<<endl;
     }
    return 0;
 
}