#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int mod = 998244353;
const int N = static_cast<const int>(2e6 + 1000);
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

void solve() {
    int n;
    double a;
    cin>>n>>a;
    int c = n;
    int cnt = 0;
    while(c--)
    {
        double x,y;
        cin>>x>>y;
        if(x*x+y*y<=a*a)
            cnt++;
    }
    cout<<fixed<<setprecision(6)<<4.0*cnt/n<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) 
        solve();

    return 0;
}