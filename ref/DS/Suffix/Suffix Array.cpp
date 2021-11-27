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
int const maxn = 5e5+3;

int n;
int ipos[maxn], sa[maxn], lcp[maxn];
string s, s1, s2;

// ipos: invert position of suffix array (ipos[i] = position of i-th suffix in `sa`)
// sa: suffix array
void buildSA() {
	vector<ii> tmp(n);
	fto1 (i, 0, n) {
		tmp[i] = {s[i]-'a', -1};
		sa[i] = i;
	}
	for (int step = 1; ;step <<= 1) {
		sort(sa, sa+n, [&tmp](int l, int r) {
			return tmp[l] < tmp[r];
		});
		ipos[sa[0]] = 0;
		fto1 (i, 1, n) ipos[sa[i]] = ipos[sa[i-1]] + (tmp[sa[i]] > tmp[sa[i-1]]);
		if (step >= n) break;
		fto1 (i, 0, n) tmp[i] = {ipos[i], (i+step < n) ? ipos[i+step] : -1};
	}
}

// lcp[i] = Longest common prefix(sa[i], sa[i+1])
void buildLCP() {
	int k = 0;
	fto1 (i, 0, n) {
		int j = ipos[i];
		if (j == n-1) continue;
		j = sa[ipos[i]+1];
		while (s[i+k] == s[j+k]) ++k;
		lcp[ipos[i]] = k;
		if (k) --k;
	}
}

int cnt[maxn];

#define multi_test 0
void _main() { // spoj LCS
	cin >> s1 >> s2;
	s = s1 + "!" + s2;
	n = sz(s);

	fto1 (i, 0, n) {
		if (i <= sz(s1)) cnt[i] = 1;
		else cnt[i] = 2;
	}

	buildSA();
	buildLCP();

	int ans = 0;
	fto1 (i, 1, n) {
		if (cnt[sa[i]] != cnt[sa[i-1]]) {
			ans = max(ans, lcp[i-1]);
		}
	}
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
