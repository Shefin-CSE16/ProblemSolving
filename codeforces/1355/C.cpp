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

const ll sz = 1e6 + 10;
ll sum[sz], big[sz];

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    for(ll i = a; i <= b; i++) {
        sum[i+b]++;
        sum[i+c+1]--;
    }

    for(ll i = 1; i < sz; i++) sum[i] += sum[i-1];
    for(ll i = sz-1; i >= 1; i--) big[i] = sum[i] + big[i + 1];

    ll ans = 0;
    for(ll i = c; i <= d; i++)  ans += big[i+1];

    cout << ans << endl;

    return 0;
}
