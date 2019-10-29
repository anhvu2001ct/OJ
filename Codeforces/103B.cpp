#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)

#define bc __builtin_popcountll
#define onb(x, bit) (((x >> bit) & 1) != 0)
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

template<class T> ostream& operator<< (ostream &os, vector<T> const &v) {
	os << sz(v) << '['; for (int i = 0; i < sz(v); ++i) { os << v[i]; if (i < sz(v)-1) os << ' '; }
	return os << ']';
}

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e5+3;

int n, m, cnt;
int p[maxn];

int Par(int u) {
	return p[u] < 0 ? u : p[u] = Par(p[u]);
}

int Union(int u, int v) {
	u = Par(u); v = Par(v);
	if (u == v) return 1;
	p[u] += p[v];
	p[v] = u;
	return 0;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	fto (i, 1, n) p[i] = -1;

	int u, v;
	fto (i, 1, m) {
		cin >> u >> v;
		cnt += Union(u, v);
	}

	fto (i, 2, n) if (Par(i) != Par(1)) {
		puts("NO");
		return 0;
	}

	puts(cnt == 1 ? "FHTAGN!" : "NO");

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}