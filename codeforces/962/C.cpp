#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18
/***template***/
#define ___                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 100005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  1e18
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
#define uniquee(x)            x.erase(unique(x.begin(), x.end()),x.end())
/****only for priority queue******/
/**struct node
{
    ll nod,d;
    node(ll a,ll b)
    {
        nod=a;
        d=b;
    }
    bool operator<(const node &p)const
    {
        return p.d<d;
    }
};**/

ll Set(ll n,ll pos)
{
    return n=n|(1LL<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1LL<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}
ll mul(ll a,ll b)
{
    ll c;
    c = (a%mod * b%mod)%mod;
    return c;
}
ll add(ll a,ll b)
{
    ll c;
    c = (a%mod + b%mod)%mod;
    return c;
}
ll sub(ll a,ll b)
{
    ll c;
    c = ((a%mod - b%mod)%mod + mod)%mod;
    return c;
}
ll power(ll x,ll y)
{
    ll res = 1;
    x = x;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
    }
    return res;
}
long long exgcd(long long x, long long y, long long &a, long long &b)
{
    // ax + by = gcd(x,y)
    int flag = 0;
    long long t, la = 1, lb = 0, ra = 0, rb = 1;
    while(x%y)
    {
        if(flag == 0)
            la -= x/y*ra, lb -= x/y*rb;
        else
            ra -= x/y*la, rb -= x/y*lb;
        t = x, x = y, y = t%y;
        flag = 1 - flag;
    }
    if(flag == 0)
        a = ra, b = rb;
    else
        a = la, b = lb;
    return y;
}
/***template***/


unordered_map <string, bool> sqr;
#define sz 45000
string s;
ll ans = 2e18;

void solve(string s1, ll indx, ll cnt)

{
    if(indx == s.length()) {
        if(sqr[s1] == 1) {
            ll tmp = cnt + s.length() - 1 - indx + 1;
            //cout << tmp << "  " << cnt << "  " << s1 << endl;
            ans = min(ans, tmp);
        }
        return;
    }
    if(s1.length() != 0) {
        if(sqr[s1] == 1) {
            ll tmp = cnt + s.length() - 1 - indx + 1;
            //cout << tmp << "  " << cnt << "  " << s1 << endl;
            ans = min(ans, tmp);
        }
    }

    solve(s1, indx + 1, cnt + 1);
    s1 += s[indx];
    solve(s1, indx + 1, cnt);
}

int main()

{
    for(ll i = 1; i <= sz; i++) {
        ll ans = i * i;

        string in = "";
        while(ans != 0) {
            ll rem = ans % 10;
            ans /= 10;
            in +=  (rem + '0');
        }
        reverse(in.begin(), in.end());
        sqr[in] = 1;
    }

    ll n;
    cin >> n;

    ll tmp = n;
    s = "";
    while(tmp != 0) {
        ll rem = tmp % 10;
        tmp /= 10;
        s +=  (rem + '0');
    }
    reverse(s.begin(), s.end());

    if(sqr[s] == 1) {
        cout << 0 << endl;
        return 0;
    }

    string pass = "";
    solve(pass, 0, 0);

    if(ans == 2e18)
        cout << -1 << endl;
    else
        cout << ans << endl;


    return 0;
}
