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
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

char s[110];

int main()

{
    ll t;
    sl(t);
    while(t--) {
        scanf("%s", s);

        ll z = 0, sum = 0, e = 0;
        for(ll i = 0; s[i] != '\0'; i++) {
            if(s[i] == '0')
                z++;

            sum += (s[i] - '0');

            ll now = s[i] - '0';
            if(now % 2 == 0)
                e++;
        }

        if(sum % 3 != 0 || z == 0 || e <= 1)
            pf("cyan");
        else
            pf("red");

        pn;
    }

    return 0;
}
