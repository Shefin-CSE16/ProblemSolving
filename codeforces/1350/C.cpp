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
ll ara[sz], cnt[sz][20];

void factor(ll num)
{
    for(ll i = 2; i * i <= num; i++) {
        if(num % i != 0)
            continue;

        ll ase = 0;
        while(num % i == 0) num /= i, ase++, cnt[i][ase]++;
    }
    if(num > 1) cnt[num][1]++;
}

int main()
{
    ll n;
    cin >> n;

    for1(i, n) sl(ara[i]), factor(ara[i]);

    ll g = 1;
    for1(i, sz-1) {

        for1(j, 19) {
            if(cnt[i][j] < n-1) break;

            g *= i;
        }
    }

    cout << g << EL;

    return 0;
}
