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
#define inf (1LL << 61)
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

const ll sz = 5005, mod = 1e9 + 7;
ll dp[sz][sz], csum[sz];

int main()
{
    ll n, a, b, k;
    cin >> n >> a >> b >> k;

    for1(i, n) dp[i][k+1] = 1;
    for1(i, n) csum[i] = dp[i][k+1] + csum[i-1];

    for(ll i = k; i >= 1; i--) {

        for1(pos, n) {

            ll rng = abs(pos - b) - 1;
            ll dwn = max(1LL, pos-rng), up = min(n, pos+rng);

            dp[pos][i] = (csum[up] - csum[dwn-1]) % mod;
            if(dp[pos][i] < 0) dp[pos][i] += mod;

            dp[pos][i] = (dp[pos][i] - dp[pos][i+1]) % mod;
            if(dp[pos][i] < 0) dp[pos][i] += mod;
        }

        for1(pos, n) csum[pos] = (dp[pos][i] + csum[pos-1]) % mod;
    }

    cout << dp[a][1] << EL;

    return 0;
}
