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

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003

int a[5];
set<int> s;

void solve(int n) {
	if (n == 1) {
		s.insert(a[0]);
		return;
	}
	int b[n], c[n];
	fto1 (i, 0, n) b[i] = i, c[i] = a[i];
	do {
		fto1 (i, 0, n) a[i] = c[b[i]];
		int v0 = a[0], v1 = a[1];
		a[0] = v0+v1;
		a[1] = a[n-1];
		solve(n-1);
		a[0] = v0-v1;
		solve(n-1);
		a[0] = v0*v1;
		solve(n-1);
		if (v1 && v0%v1 == 0) {
			a[0] = v0/v1;
			solve(n-1);
		}
		a[0] = v0;
		a[1] = v1;
	} while (next_permutation(b, b+n));
	fto1 (i, 0, n) a[i] = c[i];
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int test = 0;
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		if (!a[0]) break;
		s.clear();
		cout << "Case " << (++test) << ": ";
		solve(4);
		ii cur = {-oo, -oo}, ans = {-oo, -oo-1};
		fit (it, s) {
			if (*it != cur.y+1) {
				cur = {*it, *it};
			} else cur.y = *it;
			if (ans.y - ans.x + 1 <= cur.y - cur.x + 1) ans = cur;
		}
		cout << ans.x << " to " << ans.y << endl;
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}