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
#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
const int mod = 1e9+7; 
const int64_t INF = 2e18;
const int N = 2e5 + 5;
const int ep = 1e-9;

void io(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
} 

struct pt {
    double x, y;
};

bool compare(pt &a, pt& b){
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}
pt pp;

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool compare2(const pt& a, const pt& b){
    int o = orientation(pp, a, b);
    if (o == 0)
        return (pp.x-a.x)*(pp.x-a.x) + (pp.y-a.y)*(pp.y-a.y)
                < (pp.x-b.x)*(pp.x-b.x) + (pp.y-b.y)*(pp.y-b.y);
    return o > 0;
}



bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), compare);
    pp = p0;
    sort(a.begin(), a.end(), compare2);
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }
    a = st;
}

void solve(int n){
      vector<pt>a(n);
      for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
      }
      convex_hull(a,false);
      vector<pt>ans;
      ans.pb(a[0]);
      for(int i=1;i<a.size();i++){
          if(a[i].x==a[i-1].x && a[i].y==a[i-1].y)continue;
          ans.pb(a[i]);
      }
      a = ans;
      cout<<a.size()<<endl;
      for(int i=0;i<a.size();i++){
        cout<<a[i].x<<" "<<a[i].y<<endl;
      }
}

int32_t main()
{   
    IOS;
    //io();
    int t=1;
    //cin>>t;
    for(int i=1;;i++)
     {
        int n;
        cin>>n;
        if(n==0)return 0;
        solve(n);
     }
    return 0;
 
}

