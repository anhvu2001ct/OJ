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
int const maxn = 2e5+3;

int n, q;
ll ans, numA, numB;
ll p[maxn];
string s;

pair<pll, ll> solve(char c) {
    pair<pll, ll> res = {{numA, numB}, ans};
    if (c == 'a') res.ff.ff = (res.ff.ff + p[q]) % oo;
    else if (c == 'b') res.ff.ss = (res.ff.ss + numA) % oo;
    else res.ss = (res.ss + numB) % oo;
    return res;
}

#define multi_test 0
void _main() {
    cin >> n >> s;
    p[0] = 1;
    fto (i, 1, n) p[i] = p[i-1] * 3 % oo;
    fto1 (i, 0, n) {
        pair<pll, ll> tmp = {{0, 0}, 0};
        if (s[i] != '?') tmp = solve(s[i]);
        else {
            pair<pll, ll> tmp2;
            fto (c, 'a', 'c') {
                tmp2 = solve(c);
                tmp.ff = {(tmp.ff.ff + tmp2.ff.ff) % oo, (tmp.ff.ss + tmp2.ff.ss) % oo};
                tmp.ss = (tmp.ss + tmp2.ss) % oo;
            }
            ++q;
        }
        numA = tmp.ff.ff;
        numB = tmp.ff.ss;
        ans = tmp.ss;
    }
    bug(ans);
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