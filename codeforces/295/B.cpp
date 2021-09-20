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
#define inf (1LL << 60)
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

const ll sz = 505;
ll mat[sz][sz], ara[sz];
vector <ll> lst, ans;

int main()
{
    ll n;
    cin >> n;

    for1(i, n)
        for1(j, n)
            sl(mat[i][j]);

    for1(i, n)
        sl(ara[i]);

    rep1(i, n) {
        lst.pb(ara[i]);

        ll w = ara[i];

        for1(j, n)
            for1(k, n)
                mat[j][k] = min(mat[j][k], mat[j][w] + mat[w][k]);

        ll sum = 0;
        for(ll &u : lst)
            for(ll &v : lst)
                sum += mat[u][v];

        ans.pb(sum);
    }

    reverse(all(ans));
    for(ll &v : ans) pf("%lld ", v);
    pn;

    return 0;
}
