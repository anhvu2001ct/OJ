#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

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
	for (int i = 0; i < sz(v); ++i) { os << v[i]; if (i < sz(v)-1) os << ' '; }
	return os;
}

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 4e2+3;

int n, m;
int a[maxn][maxn];

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	fto (i, 1, m) {
		int u, v;
		cin >> u >> v;
		a[u][v] = a[v][u] = 1;
	}

	if (a[1][n]) {
		fto (i, 1, n) fto (j, i+1, n) a[i][j] = a[j][i] ^= 1;
	}

	fto (i, 1, n) fto (j, i+1, n) if (!a[i][j]) a[i][j] = a[j][i] = oo;

	fto (k, 1, n) fto (i, 1, n) fto (j, 1, n) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

	if (a[1][n] == oo) a[1][n] = -1;
	bug(a[1][n]);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}