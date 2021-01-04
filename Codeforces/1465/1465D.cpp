#ifdef _LOCAL
    #include "local_include.hpp"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(it, a) for (auto it = (a).begin(); it != (a).end(); ++it)
#define fat(i, a) for (auto i : (a))

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define y1 ansdj
#define endl '\n'
#define ff first
#define ss second
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

template<typename T>
void bug(T const &var) { cout << var << endl; }

template<typename T, typename... Args>
void bug(T const &var, Args const &... args) {
    cout << var << ' ';
    bug(args...);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e5+3;

int n, x, y;
string s;
int cnt0[maxn], cnt1[maxn];
vector<int> pos;

ll solve0() {
    ll sum = 0;
    fto1 (i, 0, sz(pos)) {
        int p = pos[i];
        sum += (ll)cnt0[p]*x;
        sum += (ll)(cnt0[n] - cnt0[p])*y;
    }
    ll res = sum;
    fto1 (i, 0, sz(pos)) {
        int p = pos[i];
        sum -= (ll)(cnt0[p]+i)*x;
        sum -= (ll)(cnt0[n] - cnt0[p])*y;
        sum += (ll)cnt1[p]*y;
        sum += (ll)(cnt1[n] - cnt1[p] + sz(pos)-i-1)*x;
        res = min(res, sum);
    }
    return res;
}

ll solve1() {
    ll sum = 0;
    fto1 (i, 0, sz(pos)) {
        int p = pos[i];
        sum += (ll)cnt1[p]*y;
        sum += (ll)(cnt1[n] - cnt1[p])*x;
    }
    ll res = sum;
    fto1 (i, 0, sz(pos)) {
        int p = pos[i];
        sum -= (ll)(cnt1[p]+i)*y;
        sum -= (ll)(cnt1[n] - cnt1[p])*x;
        sum += (ll)cnt0[p]*x;
        sum += (ll)(cnt0[n] - cnt0[p] + sz(pos)-i-1)*y;
        res = min(res, sum);
    }
    return res;
}

#define multi_test 0
void _main() {
    cin >> s;
    n = sz(s); s = " " + s;
    cin >> x >> y;
    ll ans = 0;
    fto (i, 1, n) {
        cnt0[i] = cnt0[i-1] + (s[i] == '0');
        cnt1[i] = cnt1[i-1] + (s[i] == '1');
        if (s[i] == '0') ans += (ll)cnt1[i]*y;
        else if (s[i] == '1') ans += (ll)cnt0[i]*x;
        else pos.push_back(i);
    }
    bug(ans + min(solve0(), solve1()));
}

int main() {
    #ifdef _LOCAL
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    if (multi_test) cin >> t;
    while (t--) {
        _main();
    }

    #ifdef _LOCAL
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}