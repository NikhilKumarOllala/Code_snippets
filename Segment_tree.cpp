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
const int mod = 1e9 + 7; 
const int64_t INF = 2e18;
const int N = 1e5 + 5;
const int ep = 1e-9;
 
void io(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
} 
 
void update(int k,int x,int n,vector<int>&tree){
       k+=n;
       tree[k]=x;
       for(int i=k/2;i>=1;i/=2){
           tree[i] = gcd(tree[2*i],tree[(2*i)+ 1]);
       }
}
 
int getGcd(int a,int b,int n,vector<int>&tree){
    a+=n;
    b+=n;
    int s = 0;
    while(a<=b){
        if(a%2==1) s=gcd(s,tree[a++]);
        if(b%2==0) s=gcd(s,tree[b--]);
        a/=2;b/=2;
    }
    return s;
}

vector<int>build_tree(vector<int>&v){
    int sz = v.size();
    vector<int> tree(2*sz,0);
    for(int i=sz;i-sz<v.size();i++){
          tree[i] = v[i-sz];
    }
    for(int i=sz-1;i>=1;i--){
         tree[i] = gcd(tree[2*i],tree[(2*i)+1]) ;
    }
    return tree;
}
 
void solve(){
   int n;
   cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
   vector<int>tree = build_tree(v);
  
}
 
 
 
int32_t main()
{   
    IOS;
    int t=1;
    //cin>>t;
    while(t--)
     {
      solve();
      // cout<<endl;
     }
    return 0;
 
}