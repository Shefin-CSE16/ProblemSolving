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

const ll sz = 1e6 + 10;
ll n, r1, r2, r3, d, mon[sz];

int main()
{
    cin >> n >> r1 >> r2 >> r3 >> d;

    for1(i, n) sl(mon[i]);

    ll full = 0, lastBossExtra = inf;

    for1(i, n) {

        ll nowFull = r1*mon[i] + r3;
        ll bossExtra = min(r1*mon[i] + 2*r1, r2 + r1);

        ll opt1 = full + nowFull;
        opt1 = min(opt1, lastBossExtra + 2*d + bossExtra);

        if(i != n) opt1 = min(opt1, lastBossExtra + 2*d + nowFull);
        else    opt1 = min(opt1, lastBossExtra + d + nowFull);

        ll opt2 = full + bossExtra;

        full = opt1, lastBossExtra = opt2;
    }

    cout << min(full, lastBossExtra + 2*d) + d*(n-1) << EL;

    return 0;
}
