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
int const maxn = 5e3+3;

int n;
string s;
set<ii> unique_pos;
ii a[maxn];

bool solve(ii p, map<ii, vector<int>> &pos) {
    map<ii, int> save;

    ii offset = {0, 0}, cur = p;
    int id = 0;
    while (1) {
        vector<int> &vec = pos[cur];
        int &idx = save[cur];
        while (idx < sz(vec) && vec[idx] <= id) ++idx;
        if (idx == sz(vec)) break;
        id = vec[idx];
        char dir = s[id];
        offset.ff += (dir == 'R') ? 1 : (dir == 'L') ? -1 : 0;
        offset.ss += (dir == 'U') ? 1 : (dir == 'D') ? -1 : 0;
        cur = {p.ff + offset.ff, p.ss + offset.ss};
    }

    ii last = {a[n].ff - offset.ff, a[n].ss - offset.ss};
    return last == ii(0, 0);
}

#define multi_test 1
void _main() {
    cin >> s;
    n = sz(s); s = " " + s;
    unique_pos.clear();
    map<ii, vector<int>> pos;
    
    fto (i, 1, n) {
        a[i] = a[i-1];
        a[i].ff += (s[i] == 'R') ? 1 : (s[i] == 'L') ? -1 : 0;
        a[i].ss += (s[i] == 'U') ? 1 : (s[i] == 'D') ? -1 : 0;
        pos[a[i]].push_back(i);
        unique_pos.insert({a[i].ff, a[i].ss});
    }

    fat (cur, unique_pos) {
        if (solve(cur, pos)) {
            bug(cur.ff, cur.ss);
            return;
        }
    }
    bug(0, 0);
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