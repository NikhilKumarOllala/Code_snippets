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
const int mod = 1e8; 
const int64_t INF = 2e18;
const int N = 1e5 + 5;
const int ep = 1e-9;

void io(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
} 
//gives the longest proper prefix which is also suffix
vector<int>prefix_function(string &s){
   int n = s.size();
   vector<int>pre(n,0);
   for(int i=1;i<n;i++){
     int j = pre[i-1];
     while(j>0 && s[j]!=s[i]){
        j = pre[j-1];
     }
     if(s[i]==s[j]){
        j++;
     }
     pre[i] = j;
   }
   return pre;
}

void solve(){ 
    string s;
    cin>>s;
    vector<int>pie = prefix_function(s);
   
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