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

ll par[sz], siz[sz];

ll findPar(ll u)
{
    if(par[u] == u)
        return u;

    return par[u] = findPar(par[u]);
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, n) par[i] = i, siz[i] = 1;

    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        ll pu = findPar(u), pv = findPar(v);

        if(pu == pv)
            continue;

        par[pv] = pu;
        siz[pu] += siz[pv];
    }

    ll ans = 0;
    for1(i, n) ans = max(ans, siz[i]);

    cout << ans << EL;

    return 0;
}
