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

const ll sz = 1e5 + 10;
ll k, cyc = inf, par[sz], lev[sz];
vector <ll> g[sz], ans;
pll cycle;
bool vis[sz];

void cycle_dfs(ll u, ll p, ll d)
{
    if(vis[u] == 1) {
        ll len = abs(lev[p] - lev[u]) + 1;
        //cout << u << " || " << p << " || " << lev[u] << " " << lev[p] << " " << len << endl;
        if(len < cyc) {
            cyc = len;
            cycle = mp(p, u);
        }
        return;
    }

    par[u] = p, lev[u] = d, vis[u] = 1;
    for(ll v : g[u]) {

        if(v == p || v == par[u] || vis[v] == 2)
            continue;

        cycle_dfs(v, u, d+1);
    }
    vis[u] = 2;
}

ll con[sz];
set <pii> lst;

int main()
{
    ll n, m;
    cin >> n >> m >> k;
    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    for1(i, n) {
        con[i] = g[i].size();
        lst.insert(mp(con[i], i));
    }

    ll half = k / 2;
    if(k & 1) half++;
    while(ans.size() < half && !lst.empty()) {
        pll p = *lst.begin();
        lst.erase(p);
        ans.push_back(p.second);

        for(ll &v : g[p.second]) {

            auto it = lst.find(mp(con[v], v));
            if(it == lst.end()) continue;
            lst.erase(it);

            for(ll &w : g[v]) {
                it = lst.find(mp(con[w], w));
                if(it == lst.end()) continue;

                lst.erase(it);
                con[w]--;
                lst.insert(mp(con[w], w));
            }
        }
    }

    if(ans.size() == half) {
        pf("1\n");
        for0(i, (ll)ans.size()) {
            if(i != 0)
                pf(" ");
            pf("%lld", ans[i]);
        }
        pn;
        return 0;
    }

    cycle_dfs(1, -1, 0);

    pf("2\n%lld\n", cyc);
    pf("%lld", cycle.first);

    ll cur = cycle.first;
    while(cur != cycle.second) {
        cur = par[cur];
        pf(" %lld", cur);
    }
    pn;

    return 0;
}
