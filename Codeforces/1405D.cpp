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
#define buga(a, s, e) cout << '{'; fto (i, s, e) cout << a[i] << " }"[i == e]; cout << endl

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
int const maxn = 1e5+3;

int n, a, b, da, db, d;
int h[maxn];
vector<int> adj[maxn];

int dfs(int u, int p) {
    h[u] = h[p]+1;
    ii cnt;
    fat (v, adj[u]) {
        if (v == p) continue;
        int val = dfs(v, u)+1;
        if (cnt.ff < val) cnt = {val, cnt.ff};
        else cnt.ss = max(cnt.ss, val);
        d = max(d, cnt.ff + cnt.ss);
    }
    return cnt.ff;
}

#define multi_test 1
void _main() {
    cin >> n >> a >> b >> da >> db;
    fto (i, 1, n) {
        adj[i].clear();
    }
    fto1 (i, 1, n) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    h[0] = -1;
    d = 0;
    dfs(a, 0);
    if (h[b] <= da) bug("Alice");
    else if (2*da >= d) bug("Alice");
    else bug(db > 2*da ? "Bob" : "Alice");
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
