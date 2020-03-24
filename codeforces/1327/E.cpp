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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10, mod = 998244353;
ll pw[sz];

int main()
{
    pw[0] = 1;
    for(ll i = 1; i < sz; i++) pw[i] = (pw[i-1] * 10) % mod;

    ll n;
    cin >> n;
    for1(i, n) {
        ll res = 0;
        if(i + 2 <= n)
            res = (res + (n-i+1 - 2) * 9*pw[n-i-2]*9 * 10 ) % mod;
        if(i + 1 <= n)
            res = (res + 2 * 9*pw[n-i-1]*10) % mod;
        if(i == n)
            res = 10;

        if(i != 1) pf(" ");
        pf("%lld", res);
    }
    pn;

    return 0;
}
