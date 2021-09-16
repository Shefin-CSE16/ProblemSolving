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

struct info {
    ll id, dif;
    const bool operator <(const info &b) {
        return dif > b.dif;
    }
};

const ll sz = 110;
ll mat[sz][sz];

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, m) {
        for1(j, n)
            sl(mat[i][j]);
    }

    ll mn = inf;
    vector <int> ans;

    for1(j, n-1) {
        vector <info > lst;

        for1(i, m)
            lst.pb({i, mat[i][j] - mat[i][n]});

        sort(all(lst));

        vector <int> tmp;
        ll sum = 0, stop = -1;

        for(ll i = 0; i < lst.size(); i++) {
            info Info = lst[i];

            if(sum+Info.dif < 0)
                break;

            stop = i;
            sum += Info.dif;
        }

        for(ll i = stop+1; i < lst.size(); i++) tmp.pb(lst[i].id);

        ll bad = tmp.size();
        if(bad < mn) {
            mn = bad;
            ans = tmp;
        }
    }

    cout << mn << EL;
    for(ll i = 0; i < ans.size(); i++) {
        if(i != 0) pf(" ");
        pf("%d", ans[i]);
    }
    if(mn != 0) cout << EL;

    return 0;
}
