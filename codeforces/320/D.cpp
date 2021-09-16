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

const ll sz = 1e5 + 10;
ll ara[sz], tree[4*sz];

void update(ll lo, ll hi, ll idx, ll v, ll node)
{
    if(lo > idx || hi < idx)
        return;
    if(lo == hi) {
        tree[node] = v;
        return;
    }

    ll mid = lo+hi >> 1;
    update(lo, mid, idx, v, node<<1);
    update(mid+1, hi, idx, v, node<<1|1);

    tree[node] = max(tree[node<<1], tree[node<<1|1]);
}

ll query(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lo > r || hi < l)
        return 0;
    if(lo >= l && hi <= r)
        return tree[node];

    ll mid = lo+hi >> 1;
    return max(query(lo, mid, l, r, node<<1),
               query(mid+1, hi, l, r, node<<1|1));
}

int main()
{
    ll n;
    cin >> n;
    for1(i, n) sl(ara[i]);

    stack <ll> nearBig;
    ll ans = 0;
    for1(i, n) {
        while(!nearBig.empty() && ara[ nearBig.top() ] < ara[i])
            nearBig.pop();

        ll step = 0;
        if(!nearBig.empty()) {
            ll big = nearBig.top();
            step = query(1, n, big+1, i, 1) + 1;
        }

        update(1, n, i, step, 1);
        ans = max(ans, step);

        nearBig.push(i);
    }

    cout << ans << EL;

    return 0;
}
