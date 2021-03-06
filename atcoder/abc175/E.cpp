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

const ll sz = 3009;
ll dp[sz][sz][4], grid[sz][sz], r, c, k;

ll solve(ll row, ll col, ll take)
{
    if(row > r || col > c || row < 1 || col < 1)
        return 0;

    ll &ret = dp[row][col][take];
    if(ret != -1)
        return ret;

    ret = solve(row+1, col, 0);
    ret = max(ret, solve(row, col+1, take));

    if(take < 3) {
        ret = max(ret, grid[row][col] + solve(row+1, col, 0));
        ret = max(ret, grid[row][col] + solve(row, col+1, take+1));
    }

    return ret;
}

int main()
{
    cin >> r >> c >> k;
    for1(i, k) {
        ll r2, c2, v;
        sl(r2), sl(c2), sl(v);

        grid[r2][c2] = v;
    }

    ms(dp, -1);
    cout << solve(1, 1, 0) << EL;

    return 0;
}
