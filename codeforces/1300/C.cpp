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

ll ara[100009];
ll exist[40], start[100009];

int main()

{
    ll n, mxb = 0;
    cin >> n;
    for1(i, n) {
        sl(ara[i]);
    }

    sort(ara+1, ara+n+1, greater <ll> ());
    for1(i, n) {
        for(ll j = 31; j >= 0; j--) {
            if( (ara[i] >> j) & 1) {
                exist[j]++;

                start[i] = max(start[i], j);
                mxb = max(mxb, j);
            }
        }
    }

    ll bt = -1;
    for(ll i = 33; i >= 0; i--) {
        if(exist[i] == 1) {
            bt = i;
            break;
        }
    }

    ll pos = 1, cnt = 0;
    for1(i, n) {
        if(bt == -1)
            break;

        bool chk = 0;
        for(ll j = 31; j >= 0; j--) {
            if( (ara[i] >> j) & 1) {
                if(j == bt) {
                    chk = 1;
                    break;
                }
            }
        }

        if(chk) {
            pos = i;
            break;
        }

        //cout << nai << " " << ara[i] << endl;
    }

    pf("%lld", ara[pos]);

    for1(i, n) {
        if(i == pos)
            continue;

        pf(" %lld", ara[i]);
    }

    pn;

    return 0;
}
