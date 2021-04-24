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
#define endl '\n'
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



#define multi_test 1
void _main() {
    int a, b; cin >> a >> b;
    string s; cin >> s;
    fto1 (i, 0, sz(s)) {
        if (s[i] != '?') {
            if (s[sz(s)-i-1] == '?') s[sz(s)-i-1] = s[i];
            if (s[sz(s)-i-1] != s[i]) {
                bug(-1);
                return;
            }
        }
    }
    fto1 (i, 0, sz(s)) {
        if (s[i] == '0') --a;
        else if (s[i] == '1') --b;
    }
    if (a < 0 || b < 0 || (a%2 && b%2)) {
        bug(-1);
        return;
    }
    if (a%2 || b%2) {
        if (s[sz(s)/2] != '?') {
            bug(-1);
            return;
        } else if (a%2) s[sz(s)/2] = '0', --a;
        else s[sz(s)/2] = '1', --b;
    }
    fto1 (i, 0, sz(s)) {
        if (s[i] == '?') {
            if (a) {
                s[i] = s[sz(s)-i-1] = '0';
                a -= 2;
            } else {
                s[i] = s[sz(s)-i-1] = '1';
                b -= 2;
            }
        }
    }
    bug(s);
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