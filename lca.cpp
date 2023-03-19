#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define print(ve)     \
    for (auto x : ve) \
        cout << x << " ";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)
const int mod = 998244353;
const int64_t INF = 2e18;
const int N = 2e5 + 5;

void io()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int row[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int col[8] = {0, 0, -1, 1, -1, 1, -1, 1};

//root->0 , zero indexing
class lca
{
    public:
    int n, l;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    lca(int root, int n)
    {
        tin.resize(n);
        tout.resize(n);
        adj.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root);
    }

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];

        for (int u : adj[v])
        {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i)
        {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

};

void
solve()
{

    int n;
    cin>>n;
    lca lca(0,n);
   
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        lca.adj[a].pb(b);
        lca.adj[b].pb(a);
    }
  
}

int32_t main()
{
    IOS;
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
        cout << endl;
    }
    return 0;
}
