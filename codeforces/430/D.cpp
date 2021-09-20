// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 1e3 + 10;
ll mat[sz][sz], dp1[sz][sz], dp2[sz][sz], dp3[sz][sz], dp4[sz][sz];

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, n)
        for1(j, m)
            sl(mat[i][j]);


    for1(i, n)
        for1(j, m)
            dp1[i][j] = mat[i][j] + max(dp1[i-1][j], dp1[i][j-1]);

    rep1(i, n)
        rep1(j, m)
            dp2[i][j] = mat[i][j] + max(dp2[i+1][j], dp2[i][j+1]);

    rep1(i, n)
        for1(j, m)
            dp3[i][j] = mat[i][j] + max(dp3[i+1][j], dp3[i][j-1]);

    for1(i, n)
        rep1(j, m)
            dp4[i][j] = mat[i][j] + max(dp4[i-1][j], dp4[i][j+1]);

    ll ans = 0;
    for1(i, n) {
        for1(j, m) {

            if(i+1 <= n && i-1 >= 1 && j+1 <= m && j-1 >= 1) {
                ans = max(ans, dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1]);
                ans = max(ans, dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j]);
            }
        }
    }

    cout << ans << EL;

    return 0;
}
