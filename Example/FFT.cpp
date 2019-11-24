#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fat(i, a) for(auto i : a)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)

#define bc __builtin_popcountll
#define isbit(x, bit) (((x >> bit) & 1) != 0)
#define onbit(x, bit) (x | (1LL << (bit)))
#define offbit(x, bit) (x & ~(1LL << (bit)))
#define y1 ansdj
#define endl '\n'
#define _bugl(...) bug(__func__, __LINE__, __VA_ARGS__)

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

template<class T> ostream& operator<<(ostream &os, vector<T> const &v) {
	fto1 (i, 0, sz(v)) { os << v[i]; if (i < sz(v)-1) os << ' '; }
	return os;
}

template<class T> void buga(T const &v, int l, int r) { fto (i, l, r) { cout << v[i] << " \n"[i == r]; } }

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }
 
double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 3e5+3;

complex<double> a[maxn], b[maxn];
int n;
int N = 1 << 18;

int reverse(int num) {
	int res = 0;
	fto1 (i, 0, 18) if (isbit(num, i)) res = onbit(res, 17-i);
	return res;
}

void fft(complex<double> *a, bool invert = 0) {
	fto1 (i, 0, N) {
		int j = reverse(i);
		if (i < j) swap(a[i], a[j]);
	}

	double ang = pi * (invert ? -2 : 2);
	for (int step = 2; step <= N; step <<= 1) {
		complex<double> wk(cos(ang/step), sin(ang/step));
		for (int i = 0; i < N; i += step) {
			complex<double> w(1);
			fto1 (j, 0, step/2) {
				complex<double> u = a[i+j], v = w * a[i+j+step/2];
				a[i+j] = u+v;
				a[i+j+step/2] = u-v;
				w *= wk;
			}
		}
	}

	if (invert) fto1 (i, 0, N) a[i] /= N;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	int x;
	fto (i, 1, n) {
		cin >> x;
		a[x+50000] += 1.0;
	}

	fto (i, 1, n) {
		cin >> x;
		b[x+50000] += 1.0;
	}

	fft(a); fft(b);
	fto1 (i, 0, N) a[i] *= b[i];
	fft(a, 1);

	ll ans = 0;
	fto (i, 1, n) {
		cin >> x;
		ans += round(a[x+100000].real());
	}
	bug(ans);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}