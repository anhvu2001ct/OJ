#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
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
#define bug(...) _bug(cout, __VA_ARGS__)
#define bugn(...) _bugn(#__VA_ARGS__, __VA_ARGS__)
#define buga(a, s, e) cout << '{'; fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
    return os << '(' << v.ff << ", " << v.ss << ')';
}

template<typename T>
void _bug(ostream &os, T const &var) { os << var << endl; }

template<typename T, typename... Args>
void _bug(ostream &os, T const &var, Args const &... args) {
    os << var << ' ';
    _bug(os, args...);
}

template<typename... Args>
void _bugn(string const &s, Args const &... args) {
    auto split = [](string const &s, string const &delim) {
        int next, pos = 0;
        vector<string> res;
        while (1) {
            next = s.find(delim, pos);
            if (next == string::npos) break;
            res.push_back(s.substr(pos, next-pos));
            pos = next+sz(delim);
        }
        res.push_back(s.substr(pos));
        return res;
    };

    ostringstream os; _bug(os, args...);
    string tmp = os.str(); tmp.pop_back(); 
    vector<string> v1 = split(s, ", "), v2 = split(tmp, " ");
    fto1 (i, 0, sz(v1)) cout << '[' << v1[i] << ": " << v2[i] << "]" << " \n"[i == sz(v1)-1];
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 2e5+3;

int n;
vector<int> circle;
vector<int> adj[maxn];
bool visited[maxn], mark[maxn];

void find_circle(int u, int p) {
    static stack<int> s;
    s.push(u);
    visited[u] = 1;
    fat (v, adj[u]) {
        if (v == p) continue;
        if (!visited[v]) find_circle(v, u);
        else if (circle.empty()) {
            while (1) {
                circle.push_back(s.top());
                mark[s.top()] = 1;
                s.pop();
                if (circle.back() == v) break;
            }
        }
    }
    if (!s.empty()) s.pop();
}

ll ans = 0;
int dfs(int u, int p) {
    vector<int> vec;
    int c = 0;
    fat (v, adj[u]) {
        if (v == p || mark[v]) continue;
        vec.push_back(dfs(v, u));
        c += vec.back();
    }
    ll sum = 0;
    fat (no_child, vec) sum += (ll)no_child * (c - no_child);
    ans += sum/2 + c;
    return c+1;
}

#define multi_test 1
void _main() {
    cin >> n;
    ans = 0;
    circle.clear();
    fto (i, 1, n) {
        adj[i].clear();
        visited[i] = mark[i] = 0;
    }

    int u, v;
    fto (i, 1, n) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_circle(1, 0);
    vector<int> vec;
    int sum = 0;
    fat (root, circle) {
        vec.push_back(dfs(root, 0));
        sum += vec.back();
    }
    fat (no_child, vec) ans += (ll)no_child * (sum - no_child);
    bug(ans);
}

int main() {
    #ifdef KITTENS
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    if (multi_test) cin >> t;
    while (t--) {
        _main();
    }

    #ifdef KITTENS
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}