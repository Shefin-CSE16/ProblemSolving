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
ll ara[sz], pos[sz];
vector <int> ans;
set <int> lst;

int main()
{
    ll n;
    cin >> n;

    for1(i, n) sl(ara[i]), pos[ara[i] ] = i;

    bool ok = 1;

    rep1(i, n) {
        ll p = pos[i];

        if(p == i)
            continue;

        auto it = lst.lower_bound(p);

        if(p < i) {

            if(it != lst.end() && *it <= i-1) {
                ok = 0;
                break;
            }

            for(ll j = p; j < i; j++) {
                ll v = ara[j+1];
                pos[v] = j;

                swap(ara[j], ara[j+1]);
                lst.insert(j);

                ans.pb(j);
            }
        }
        else {
            if(it != lst.begin()) {
                it--;
                if(*it >= i) {
                    ok = 0;
                    break;
                }
            }

            for(ll j = p-1; j >= i; j--) {
                ll v = ara[j];
                pos[v] = j;

                swap(ara[j], ara[j+1]);
                lst.insert(j);

                ans.pb(j);
            }
        }
    }

    if(!ok || (ans.size() != n-1)) {
        pf("-1\n");
        return 0;
    }

    for(int &p : ans)
        pf("%d\n", p);

    return 0;
}
