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

const ll sz = 1e5 + 10;
ll ara[sz];

int main()
{
    ll n, ans = 0;
    cin >> n;
    for1(i, n) {
        sl(ara[i]);
    }

    for(ll i = 0; i <= 30; i++) {
        ll sum = 0, mx = 0, got = 0;
        for1(j, n) {
            if(ara[j] > i || sum + ara[j] < 0) {
                if(got) mx = max(mx, sum);
                sum = 0, got = 0;
                continue;
            }
            if(ara[j] == i) got = 1;

            sum += ara[j];

            if(got) mx = max(mx, sum);
        }
        if(got) mx = max(mx, sum);

        ans = max(ans, mx - i);
    }

    pf("%lld\n", ans);

    return 0;
}

