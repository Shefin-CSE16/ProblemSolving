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

// === Debug macro starts here ===

#ifndef ONLINE_JUDGE
#define DEBUG
#define SYS_COL system("COLOR")
#endif

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; SYS_COL; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

// === Debug macro ends here ===


void brute()
{
    ll l = 33, r = 46, mx = 0;

    for(ll i = l; i <= r; i++) {
        ll x = 0;
        for(ll j = i; j <= r; j++) {
            x ^= j;
            mx = max(mx, x);
        }
    }
    dbg(mx);
}

int main()
{
    //brute();

    fastio;
    ll n; cin >> n;

    string l, r;
    cin >> l >> r;

    if(r[0] == '0' || l == r) {
        cout << r << EL;
        return 0;
    }

    if(l[0] == '0') {
        for1(i, n) cout << '1';
        cout << EL;
        return 0;
    }

    if(r.back() == '1')
        cout << r << EL;
    else {
        bool d1 = 1;

        for0(i, n) {
            if(l[i] == r[i])
                continue;

            for(ll j = i+1; j < n; j++) {
                if(l[j] != '1' || r[j] != '0') {
                    d1 = 0;
                    break;
                }
            }
            break;
        }

        for0(i, n) {
            if(i != n-1) cout << r[i];
            else cout << (d1? '0':'1');
        }
        cout << EL;
    }

    return 0;
}
