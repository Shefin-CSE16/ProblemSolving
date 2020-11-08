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
char s[sz];
pll d[sz];

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        ll n, k;
        sl(n), sl(k);

        scanf("%s", s+1);

        ll prv = 0, ans = 0, idx = 0, pref = n+1;

        for1(i, n) {

            if(s[i] == 'L')
                continue;

            if(prv != 0)
                d[++idx] = mp(i-prv-1, prv+1);
            else
                pref = i;

            ll start = i, stop = i;

            for(ll j = i; j <= n; j++) {
                if(s[j] == 'L')
                    break;

                stop = j;

                if(j == i) ans++;
                else ans += 2;
            }

            i = prv = stop;
        }

        sort(d+1, d+idx+1);

        for1(i, idx) {
            if(d[i].first > k)
                continue;

            k -= d[i].first, ans += 2*d[i].first + 1;

            ll stop = d[i].second+d[i].first-1;

            for(ll j = d[i].second; j <= stop; j++) s[j] = 'W';
        }

        for1(i, n) {
            if(s[i] == 'L')
                continue;

            ll start = i, stop = i;

            for(ll j = i; j <= n; j++) {
                if(s[j] == 'L')
                    break;

                stop = j;
            }

            for(ll j = stop+1; j <= n && k != 0; j++) {
                s[j] = 'W';
                ans += 2, k--;
            }

            break;
        }

        for(ll i = pref-1; i >= 1 && k != 0; i--) {

            if(i == pref-1) {
                if(i != n) ans += 2;
                else ans++;
            }
            else
                ans += 2;

            k--;
        }

        pf("%lld\n", ans);
    }

    return 0;
}
