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

const ll sz = 55;
ll mat[sz][sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, m, a, b;
        sl(n), sl(m), sl(a), sl(b);

        if(n * a != m * b) {
            pf("NO\n");
            continue;
        }

        ll dx;
        for1(i, m) {
            if(n * i % m == 0) {
                dx = i;
                break;
            }
        }

        for(ll i = 1, j = 1; i <= n; i++, j += dx) {

            if(j > m) j -= m;

            for(ll k = j, cnt = 1; cnt <= a; cnt++, k++) {
                if(k > m) k = 1;
                mat[i][k] = 1;
            }
        }

        pf("YES\n");
        for1(i, n) {
            for1(j, m) {
                pf("%lld", mat[i][j]);
            }
            pn;
        }

        ms(mat, 0);
    }

    return 0;
}
