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
ll n, m, pos[sz];
string s, t;

int main()
{
    fastio;

    cin >> n >> m >> s >> t;

    rep0(i, s.size())
        pos[i] = inf;

    ll idx = s.size() - 1;

    rep0(i, t.size()) {

        while(s[idx] != t[i])
            idx--;

        pos[idx] = i, idx--;
    }

    rep0(i, s.size()-1) pos[i] = min(pos[i], pos[i+1]);

    ll mat = -1, ans = 1;

    for0(i, s.size()) {
        ll lo = 0, hi = s.size()-i-1, ret = inf;

        while(lo <= hi && i != 0) {
            ll mid = lo+hi >> 1;

            if(pos[i+mid] <= mat+1) {
                ret = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }

        if(i != 0 && ret != inf)
            ans = max(ans, ret+1);

        while(s[i] != t[mat+1])
            i++;

        mat++;
        if(mat == t.size()-1) break;
    }

    cout << ans << EL;

    return 0;
}
