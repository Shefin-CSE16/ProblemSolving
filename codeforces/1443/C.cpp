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

const ll sz = 2e5 + 10;
ll a[sz], b[sz], n;

inline bool check(ll k)
{
    ll t = 0;
    for1(i, n) {
        if(a[i] <= k) continue;
        t += b[i];
    }

    return t <= k;
}

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        sl(n);

        for1(i, n) sl(a[i]);
        for1(i, n) sl(b[i]);

        ll lo = 1, hi = 1e15, ret;
        while(lo <= hi) {
            ll mid = lo+hi >> 1;

            if(check(mid)) {
                ret = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        pf("%lld\n", ret);
    }

    return 0;
}
