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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// returns a random ll integer in [l, r] range
inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

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

const ll sz = 5e5 + 10, mod = 998244353;
ll ara[sz], lft[sz];
ll dp[sz][2], pre[sz][2];

int main()
{
    ll n;
    cin >> n;

    for1(i, n) sl(ara[i]);

    stack <int> st;

    for1(i, n) {
        lft[i] = -inf;

        while(!st.empty() && ara[st.top()] > ara[i]) st.pop();

        if(!st.empty()) lft[i] = st.top();

        st.push(i);
    }

    dp[0][0] = pre[0][0] = 1;

    for1(i, n) {
        for0(k, 2) {
            if(lft[i] != -inf) {
                ll way = ((pre[i-1][k^1] - pre[lft[i]-1][k^1]) + mod) % mod;
                way = (way * ara[i]) % mod;

                dp[i][k] = (way + dp[lft[i]][k]) % mod;
            }
            else
                dp[i][k] = (pre[i-1][k^1] * ara[i]) % mod;

            pre[i][k] = (pre[i-1][k] + dp[i][k]) % mod;
        }
    }

    ll ans = dp[n][n&1] - dp[n][!(n&1)];
    if(ans < 0) ans += mod;

    cout << ans << EL;

    return 0;
}
