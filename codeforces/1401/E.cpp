// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>  using orderedSet =
	tree<T, null_type, less<T>,   /// greater<T> for sorting decreasingly
	rb_tree_tag, tree_order_statistics_node_update>;


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

vector <pll> horiz[sz], vert[sz];

orderedSet <int> horizLst;

int main()
{
    ll n, m, ans = 1, last = 1e6;
    cin >> n >> m;

    for1(i, n) {
        ll y, lx, rx;
        sl(y), sl(lx), sl(rx);

        horiz[lx].pb(mp(y, 1));
        horiz[rx+1].pb(mp(y, -1));

        if(lx == 0 && rx == last) ans++;
    }

    for1(i, m) {
        ll x, ly, ry;
        sl(x), sl(ly), sl(ry);

        vert[x].pb(mp(ly, ry));

        if(ly == 0 && ry == last) ans++;
    }

    for(ll x = 0; x <= last; x++) {

        for(pll &h : horiz[x]) {
            if(h.second == -1) horizLst.erase(h.first);
            else    horizLst.insert(h.first);
        }

        for(pll &v : vert[x]) {

            ll rgt = horizLst.order_of_key(v.second+1);
            ll lft = horizLst.order_of_key(v.first);

            ans += (rgt - lft);
        }
    }

    cout << ans << EL;

    return 0;
}
