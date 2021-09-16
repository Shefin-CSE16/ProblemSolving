// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

#define ll int
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
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 1e6 + 10;
int tree[4*sz];

void update(ll lo, ll hi, ll idx, ll v, ll node) {
    if(lo > idx || hi < idx)
        return;
    if(lo == hi) {
        tree[node] += v;
        return;
    }

    ll mid = lo+hi >> 1;
    update(lo, mid, idx, v, node<<1);
    update(mid+1, hi, idx, v, node<<1 | 1);

    tree[node] = tree[node<<1] + tree[node<<1 | 1];
}

ll query(ll lo, ll hi, ll k, ll node)
{
    if(lo == hi)
        return lo;

    ll mid = lo+hi >> 1, lft = node<<1, rgt = node<<1 | 1, ret = -1;
    if(tree[lft] >= k)
        return query(lo, mid, k, lft);
    else
     return query(mid+1, hi, k-tree[lft], rgt);
}

int main()
{
    ll n, q;
    cin >> n >> q;
    for1(i, n) {
        ll inp;
        si(inp);

        update(1, n, inp, 1, 1);
    }

    for1(i, q) {
        ll inp;
        si(inp);

        if(inp > 0) update(1, n, inp, 1, 1);
        else {
            ll num = query(1, n, -inp, 1);
            update(1, n, num, -1, 1);
        }
    }

    if(tree[1] == 0) pf("0\n");
    else pf("%d\n", query(1, n, 1, 1));

    return 0;
}
