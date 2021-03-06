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

const ll sz = 2e5 + 10, mod = 1e9 + 7;
ll ara[sz];
set <pii> f[sz], fac[sz];
bool chk[sz];
unordered_map <int, int> cnt[sz];

int main()
{
    for(ll i = 2; i < sz; i++) {

        if(!chk[i]) {

            for(ll j = i; j < sz; j += i) {
                chk[j] = 1;

                ll p = i, ase = 0;
                while(j % p == 0)
                    p *= i, ase++;

                f[j].insert(mp(i, ase));
            }
        }
    }

    ll n, q, g = 1;
    cin >> n >> q;

    for1(i, n) {
        sl(ara[i]);

        fac[i] = f[ ara[i] ];

        for(const pii &p : fac[i]) {

            for1(j, p.second) {
                ++cnt[p.first][j];

                if(cnt[p.first][j] == n)
                    g *= p.first;
            }
        }
    }

    while(q--) {
        ll idx, x;
        sl(idx), sl(x);

        for(const pii &p : f[x]) {

            auto it = fac[idx].lower_bound(mp(p.first, 0));

            ll start = 1, stop = p.second;

            if(it != fac[idx].end() && it->first == p.first) {
                start += it->second;
                stop += it->second;

                fac[idx].erase(it);
                fac[idx].insert(mp(p.first, stop));
            }
            else
                fac[idx].insert(p);
            //cout << p.first << " " << start << " " << stop << EL;

            for(ll i = start; i <= stop; i++) {
                ++cnt[p.first][i];

                if(cnt[p.first][i] == n)
                    g = (g*p.first) % mod;
            }
        }

        pf("%lld\n", g);
    }

    return 0;
}
