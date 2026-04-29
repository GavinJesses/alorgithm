#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int mod = 998244353;
const int N = static_cast<const int>(2e6 + 1000);
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
int k;
vector<vector<int>> g(201, vector<int>(201));
bool is_csp(int x, int y)
{
    if(g[x][y]<k||g[x][y+1]<k||g[x][y+2]<k||g[x][y+3]<k||g[x][y+4]<k||g[x][y+5]<k||g[x][y+6]<k||g[x][y+7]<k||g[x][y+8]<k||g[x+1][y]<k||g[x+1][y+3]<k||g[x+1][y+6]<k||g[x+1][y+8]<k||g[x+2][y]<k||g[x+2][y+3]<k||g[x+2][y+4]<k||g[x+2][y+5]<k||g[x+2][y+6]<k||g[x+2][y+7]<k||g[x+3][y]<k||g[x+3][y+5]<k||g[x+3][y+6]<k||g[x+4][y]<k||g[x+4][y+1]<k||g[x+4][y+2]<k||g[x+4][y+3]<k||g[x+4][y+4]<k||g[x+4][y+5]<k||g[x+4][y+6]<k)
        return false;
    if(g[x+1][y+1]>=k||g[x+1][y+2]>=k||g[x+1][y+4]>=k||g[x+1][y+5]>=k||g[x+1][y+7]>=k||g[x+2][y+1]>=k||g[x+2][y+2]>=k||g[x+2][y+8]>=k||g[x+3][y+1]>=k||g[x+3][y+2]>=k||g[x+3][y+3]>=k||g[x+3][y+4]>=k||g[x+3][y+7]>=k||g[x+3][y+8]>=k||g[x+4][y+7]>=k||g[x+4][y+8]>=k)
        return false;
    return true;
}
void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> res(65536,0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    for(int i = 0;i<n-4;i++)
    {

        for(int j = 0;j<n-8;j++)
        {
            if(min({g[i][j],g[i][j+1],g[i][j+2],g[i][j+3],g[i][j+4],g[i][j+5],g[i][j+6],g[i][j+7],g[i][j+8],g[i+1][j],g[i+1][j+3],g[i+1][j+6],g[i+1][j+8],g[i+2][j],g[i+2][j+3],g[i+2][j+4],g[i+2][j+5],g[i+2][j+6],g[i+2][j+7],g[i+3][j],g[i+3][j+5],g[i+3][j+6],g[i+4][j],g[i+4][j+1],g[i+4][j+2],g[i+4][j+3],g[i+4][j+4],g[i+4][j+5],g[i+4][j+6]})<=max({g[i+1][j+1],g[i+1][j+2],g[i+1][j+4],g[i+1][j+5],g[i+1][j+7],g[i+2][j+1],g[i+2][j+2],g[i+2][j+8],g[i+3][j+1],g[i+3][j+2],g[i+3][j+3],g[i+3][j+4],g[i+3][j+7],g[i+3][j+8],g[i+4][j+7],g[i+4][j+8]}))
                continue;
            for(int u = 0;u<l;u++)
            {
                k = u;
                if(is_csp(i,j))
                    res[k] = 1;
            }
            
        }
    }
    for(int i = 0;i<65536;i++)
        if(res[i] == 1)
            cout<<i<<endl;
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