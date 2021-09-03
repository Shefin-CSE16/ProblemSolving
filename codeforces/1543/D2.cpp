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

// === DEBUG MACRO STARTS HERE === //
#ifdef LOCALXOX
#define DEBUG
#define SYS_COL system("COLOR")
#endif

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; SYS_COL; \
                cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":" \
                <<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}

template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value,
            Ostream&>::type operator<<(Ostream& os,  const Cont& v) {
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
#else
#define dbg(x)
#endif
// === DEBUG MACRO ENDS HERE === //

#define ff first
#define ss second

inline bool ask(ll x)
{
    cout << x << endl;
    ll ret; cin>>ret;
    return ret;
}

ll n, k;

ll sxork(ll v1, ll v2)
{
    vector <int> a, b;
    while(v1) {
        a.pb(v1%k);
        v1 /= k;
    }
    while(v2) {
        b.pb(v2%k);
        v2 /= k;
    }

    while(b.size() < a.size()) b.pb(0);
    while(a.size() < b.size()) a.pb(0);

    reverse(all(a));
    reverse(all(b));

    ll ret = 0;
    for0(i, a.size()) {
        ll cur = (a[i] - b[i]) % k;
        if(cur < 0) cur += k;

        ret = ret*k + cur;
    }

    //dbg(a); dbg(b); dbg(ret);
    return ret;
}

ll xork(ll v1, ll v2)
{
    vector <int> a, b;
    while(v1) {
        a.pb(v1%k);
        v1 /= k;
    }
    while(v2) {
        b.pb(v2%k);
        v2 /= k;
    }

    while(b.size() < a.size()) b.pb(0);
    while(a.size() < b.size()) a.pb(0);

    reverse(all(a));
    reverse(all(b));

    ll ret = 0;
    for0(i, a.size()) {
        ll cur = (a[i] + b[i]) % k;
        ret = ret*k + cur;
    }

    //dbg(a); dbg(b); dbg(ret);
    return ret;
}

int main()
{
//    k = 3;
//    dbg(xork(1, 3));

    fastio;

    ll t;
    cin >> t;

    while(t--) {
        cin >> n >> k;

        ll prv = 0, cur = 0, q = 0;

        while(!ask(q)) {
            cur++;

            if(cur % 2 == 0)
                q = xork(prv, cur);
            else
                q = sxork(prv, cur);

            prv = sxork(q, prv);
        }
    }

    return 0;
}

