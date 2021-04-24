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
int const maxn = 3e5+3;

struct Node {
    int cnt;
    int child[2];
    Node(): cnt(0) {
        child[0] = child[1] = -1;
    }
};

int n, m;
int a[maxn];
bool check[maxn];
vector<Node> node(1);

void add(int x) {
    int root = 0;
    fdto (i, 18, 0) {
        bool bit = (x >> i) & 1;
        if (node[root].child[bit] == -1) {
            node[root].child[bit] = sz(node);
            node.push_back(Node());
        }
        root = node[root].child[bit];
        ++node[root].cnt;
    }
}

int solve(int x) {
    int root = 0, ans = 0;
    fdto (i, 18, 0) {
        if (root == -1) break;
        bool bit = (x >> i) & 1;
        if (node[root].child[bit] == -1) break;
        if (node[node[root].child[bit]].cnt == (1 << i)) {
            bit ^= 1;
            ans |= (1 << i);
        }
        root = node[root].child[bit];
    }
    return ans;
}

#define multi_test 0
void _main() {
    cin >> n >> m;
    fto (i, 1, n) {
        cin >> a[i];
        if (!check[a[i]]) {
            check[a[i]] = 1;
            add(a[i]);
        }
    }
    int cur = -1;
    while (m--) {
        int x; cin >> x;
        if (cur == -1) cur = x;
        else cur ^= x;
        bug(solve(cur));
    }
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