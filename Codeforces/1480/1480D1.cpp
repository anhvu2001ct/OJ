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

int n;
int a[maxn], pos[maxn];
vector<int> store[2];

void add(deque<int> &mid, int p) {
    int idx = -1;
    if (!store[1].empty() && a[p] == store[1].back()) {
        mid.push_front(a[p]);
        mid.push_back(a[p]);
        fto1 (i, 1, sz(mid)-1) {
            if (mid[i] != a[p] && mid[i-1] != mid[i+1]) {
                idx = i-1;
                break;
            }
        }
        mid.pop_back();
        mid.pop_front();
    }
    fto1 (i, 0, sz(mid)) {
        if (idx == i) store[1].push_back(mid[i]);
        else store[0].push_back(mid[i]);
    }
    mid.clear();
}

#define multi_test 0
void _main() {
    cin >> n;
    fto (i, 1, n) cin >> a[i];
    ii cur = {a[1], 1};
    fto (i, 2, n+1) {
        if (a[i] == cur.first) ++cur.second;
        else {
            if (cur.second > 1) pos[i - cur.second] = i-1;
            cur = {a[i], 1};
        }
    }
    deque<int> mid;
    fto (i, 1, n) {
        if (pos[i]) {
            add(mid, i);
            store[0].push_back(a[i]);
            store[1].push_back(a[i]);
            fto (j, i+2, pos[i]) store[0].push_back(a[i]);
            i = pos[i];
        } else {
            mid.push_back(a[i]);
        }
    }
    while (!mid.empty()) store[0].push_back(mid.front()), mid.pop_front();
    int ans = 0, tmp = 0;
    fto1 (i, 0, sz(store[0])) {
        if (store[0][i] != tmp) ++ans, tmp = store[0][i];
    }
    tmp = 0;
    fto1 (i, 0, sz(store[1])) {
        if (store[1][i] != tmp) ++ans, tmp = store[1][i];
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