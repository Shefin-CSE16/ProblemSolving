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

struct info {
    char ch;
    ll v;
} ara[sz];

stack <int> st;
ll val[sz];

int main()
{
    ll n;
    cin >> n;

    ll m = 2*n, id = 0, ok = 1;

    for1(i, m) {
        scanf(" %c", &ara[i].ch);

        if(ara[i].ch == '+') {
            st.push(++id);
            continue;
        }

        scanf("%lld", &ara[i].v);

        if(st.empty()) {
            ok = -1;
            continue;
        }

        ll idx = st.top();
        st.pop();
        val[idx] = ara[i].v;
    }

    if(ok == -1) {
        cout << "NO" << EL;
        return 0;
    }

    set <int> lst;
    ll ptr = 0;

    for1(i, m) {
        if(ara[i].ch == '+') {
            lst.insert(val[++ptr]);
            continue;
        }

        if(lst.empty()) {
            ok = -1;
            break;
        }

        ll mn = *lst.begin();
        if(mn != ara[i].v) {
            ok = -1;
            break;
        }

        lst.erase(mn);
    }

    if(ok == -1) {
        cout << "NO" << EL;
        return 0;
    }

    cout << "YES" << EL;
    for1(i, n) {
        if(i != 1) pf(" ");
        pf("%lld", val[i]);
    }
    pn;

    return 0;
}
