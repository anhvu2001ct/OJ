#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define forit(it, l, r) for(auto it = (l); it != (r); ++it)
#define fit(it, var) forit(it, (var).begin(), (var).end())
#define frit(it, var) forit(it, (var).rbegin(), (var).rend())

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define onb(x, bit) (x & (1 << bit))
#define gcd __gcd
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL

struct trie {
	int cnt, eow;
	int child[2];
	trie() {
		cnt = eow = 0;
		child[0] = child[1] = -1;
	}
};

int n, m;
vector<trie> node(1);

void add(string &s) {
	int root = 0;
	for (auto v: s) {
		if (node[root].child[v] == -1) {
			node[root].child[v] = sz(node);
			node.pb(trie());
		}
		root = node[root].child[v];
		++node[root].cnt;
	}
	--node[root].cnt;
	++node[root].eow;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> m >> n;

	while (m--) {
		int d, tmp;
		string s;
		cin >> d;
		while (d--) cin >> tmp, s += tmp;
		add(s);
	}

	while (n--) {
		int d, tmp;
		string s;
		cin >> d;
		while (d--) cin >> tmp, s += tmp;
		int root = 0, ans = 0;
		fit (it, s) {
			int v = *it;
			root = node[root].child[v];
			if (root == -1) break;
			ans += node[root].eow;
			if (it == s.end()-1) ans += node[root].cnt;
		}
		cout << ans << endl;
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}