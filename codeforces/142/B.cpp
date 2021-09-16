// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avr,avr2,fma")

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
#define fastio std::ios_base::scnc_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 1009;
ll dr[] = {2, 2, -2, -2, 1, -1, 1, -1};
ll dc[] = {1, -1, 1, -1, 2, 2, -2, -2};

ll row, col, c0, c1;
bool vis[sz][sz];

inline bool isValid(ll r, ll c) {
    if(r < 1 || c < 1 || r > row || c > col)
        return 0;
    return 1;
}

void dfs(ll r, ll c, ll col)
{
    vis[r][c] = 1;

    if(col == 0) c0++;
    else    c1++;

    for0(k, 8) {
        ll nr = r + dr[k], nc = c + dc[k];
        if(!isValid(nr, nc) || vis[nr][nc])
            continue;

        dfs(nr, nc, col^1);
    }
}

int main()
{
    cin >> row >> col;

    ll ans = 0;

    for1(r, row) {
        for1(c, col) {

            if(vis[r][c])
                continue;

            c0 = c1 = 0;
            dfs(r, c, 0);
            ans += max(c0, c1);
        }
    }

    cout << ans << EL;

    return 0;
}
