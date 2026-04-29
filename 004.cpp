#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int mod = 998244353;
const int N = static_cast<const int>(2e6 + 1000);
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
vector<int> v;
vector<int> f(500001, 0);
vector<int> w(500001);
vector<int> res;
void dfs(int u, vector<vector<int>> &g, int goal)
{
    if (u == goal)
    {
        res = v;
        return;
    }
    for (auto it : g[u])
    {
        if (!f[it])
        {
            v.push_back(w[it]);
            f[it] = 1;
            dfs(it, g, goal);
            if (!res.empty())
                return;
            v.pop_back();
            f[it] = 0;
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        v.clear();
        fill(f.begin(), f.end(), 0);
        res.clear();
        v.push_back(w[x]);
        f[x] = 1;
        dfs(x, g, y);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        int j = 0;
        unordered_set<int> st(res.begin(), res.end());
        int mex = 0;
        while (st.count(mex))
            mex++;
        cout<<mex<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
