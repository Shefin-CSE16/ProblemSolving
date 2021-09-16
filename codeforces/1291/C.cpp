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
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll ara[3509], n, m, k;
ll dp[3509][3509];

ll solve(ll first, ll last)
{
    ll taken = first-1 + n-last;
    if(taken == m-1)
        return max(ara[first], ara[last]);

    ll &ret = dp[first][last];
    if(ret != -1)
        return ret;

    if(taken < k)
        ret = max(solve(first+1, last), solve(first, last-1));
    else
        ret = min(solve(first+1, last), solve(first, last-1));

    return ret;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        scanf("%lld %lld %lld", &n, &m, &k);
        for1(i, n)
            sl(ara[i]);

        for(ll i = 0; i <= n; i++) {
            for(ll j = 0; j <= n; j++)
                dp[i][j] = -1;
        }

        pf("%lld\n", solve(1, n) );
    }

    return 0;
}
