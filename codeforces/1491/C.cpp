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

const ll sz = 5009;
ll ara[sz];

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        set <int> lst;

        ll n; sl(n);
        for1(i, n) {
            sl(ara[i]);
            if(ara[i] != 1)
                lst.insert(i);
        }

        ll ans = 0;

        for1(i, n-1) {

            ll d = n-i;
            if(ara[i] > d) ans += (ara[i] - d);

            ara[i] = min(ara[i], d);

            while(ara[i] > 1) {

                ll nxt = i+ara[i];
                while(nxt <= n) {

                    auto it = lst.lower_bound(nxt);
                    if(it == lst.end())
                        break;

                    nxt = *it;
                    ll tmp = nxt+ara[nxt];
                    ara[nxt]--;
                    if(ara[nxt] == 1) lst.erase(nxt);

                    nxt = tmp;
                }

                ara[i]--;
                if(ara[i] == 1) lst.erase(i);
                ans++;
            }
        }
//        cout << ans << EL;
//
//        for1(i, n) {
//            cout << ara[i] << " ";
//        }
//        cout << endl;

        for1(i, n) ans += (ara[i]-1);

        pf("%lld\n", ans);
    }

    return 0;
}
