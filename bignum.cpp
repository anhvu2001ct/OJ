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
#define onbit(x, bit) (x | (1LL << bit))
#define offbit(x, bit) (x & ~(1LL << bit))
#define y1 ansdj
#define endl '\n'
#define _bug(...) bug(__func__, __LINE__, __VA_ARGS__)

#define ll long long
#define cd complex<double>
#define ii pair<int, int>
#define pll pair<ll, ll>
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
int const maxn = 2e5+3;

template<int digits, int base>
struct bigint {
	vector<ll> a;
	short sign;

	bigint() { a.clear(); sign = 1; }

	bigint(string const &s) {
		int pos = 0;
		*this = bigint();
		if (s[0] == '-') sign = -1, ++pos;
		for (int i = sz(s)-1; i >= pos; i -= digits) {
			int num = 0;
			fto (j, max(pos, i-digits+1), i) num = num * 10 + s[j] - 48;
			a.pb(num);
		}
	}

	string tostring() const {
		ostringstream s; s << *this;
		return s.str();
	}

	void plus(bigint const &v) {
		a.resize(max(sz(a), sz(v.a)));
		fto1 (i, 0, sz(v.a)) a[i] += v.a[i];
	}

	void minus(bigint const &v) {
		a.resize(max(sz(a), sz(v.a)));
		fto1 (i, 0, sz(v.a)) a[i] -= v.a[i];
	}

	bigint& operator+=(bigint const &v) {
		if (sign == v.sign) plus(v);
		else if (less_abs(v, 1)) {
				bigint tmp = v;
				tmp.minus(*this);
				sign *= -1, a = tmp.a;
		} else minus(v);
		trim(); return *this;
	}

	bigint& operator-=(bigint v) {
		v.sign *= -1;
		return (*this) += v;
	}

	bigint& operator*=(int const v) {
		if (v < 0) sign = -sign;
		fto1 (i, 0, sz(a)) a[i] *= v;
		trim(); return *this;
	}

	static void prefft(bigint const &v1, bigint const &v2, vector<cd> &a1, vector<cd> &a2) {
		int n = sz(v1.a) + sz(v2.a), N = 1;
		while (N <= n) N <<= 1;
		a1.resize(N); a2.resize(N);
		fto1 (i, 0, sz(v1.a)) a1[i] = v1.a[i];
		fto1 (i, 0, sz(v2.a)) a2[i] = v2.a[i];
	}

	static int reverse(int num, int lg) {
		int res = 0;
		fto1 (i, 0, lg) if (isbit(num, i)) res = onbit(res, lg-i-1);
		return res;
	}
	static void fft(vector<cd> &a, bool invert = 0) {
		int N = sz(a), lg = __builtin_ctz(N);
		fto1 (i, 0, N) {
			int j = reverse(i, lg);
			if (i < j) swap(a[i], a[j]);
		}

		double ang = pi * (invert ? -2 : 2);
		for (int step = 2; step <= N; step <<= 1) {
			cd wk(cos(ang/step), sin(ang/step));
			for (int i = 0; i < N; i += step) {
				cd w(1);
				fto1 (j, 0, step/2) {
					cd u = a[i+j], v = w * a[i+j+step/2];
					a[i+j] = u+v;
					a[i+j+step/2] = u-v;
					w *= wk;
				}
			}
		}

		if (invert) fto1 (i, 0, N) a[i] /= N;
	}

	bigint& operator*=(bigint const &v) {
		if (!sz(a) || !sz(v.a)) return *this = bigint();
		vector<cd> v1, v2; prefft(*this, v, v1, v2);
		fft(v1); fft(v2);
		fto1 (i, 0, sz(v1)) v1[i] *= v2[i];
		fft(v1, 1);
		a.resize(sz(v1));
		fto1 (i, 0, sz(v1)) a[i] = round(v1[i].real());
		trim();
		sign *= v.sign;
		return *this;
	}

	bool less_abs(bigint const &v, short sign) const {
		if (sz(a) != sz(v.a)) return sz(a) * sign < sz(v.a) * sign;
		fdto (i, sz(a)-1, 0) if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
		return 0;
	}
	
	bool operator<(bigint const &v) const {
		return (sign != v.sign) ? (sign < v.sign) : less_abs(v, sign);
	}

	bool operator>(bigint const &v) const { return v < *this; }

	bool operator<=(bigint const &v) const { return !(*this > v); }

	bool operator>=(bigint const &v) const { return !(*this < v); }

	void trim() {
		a.pb(0);
		fto1 (i, 0, sz(a)-1) {
			if (a[i] < 0) --a[i+1], a[i] += base;
			else a[i+1] += a[i]/base, a[i] %= base;
		}
		while (sz(a) && a.back() == 0) a.pop_back();
		if (a.empty()) sign = 1;
	}

	friend bigint operator+(bigint l, bigint const &r) { return l += r; }
	
	friend bigint operator-(bigint l, bigint const &r) { return l -= r; }

	friend bigint operator*(bigint l, bigint const &r) { return l *= r; }

	friend bigint operator*(bigint l, int const &r) { return l *= r; }

	friend bigint abs(bigint v) { v.sign = 1; return v; }

	friend istream& operator>>(istream &stream, bigint &v) {
		string tmp; stream >> tmp; v = bigint(tmp);
		return stream;
	}

	friend ostream& operator<<(ostream &stream, bigint const &v) {
		if (!sz(v.a)) return stream << 0;
		if (v.sign == -1) stream << '-';
		stream << v.a.back();
		fdto (i, sz(v.a)-2, 0) stream << setfill('0') << setw(digits) << v.a[i];
		return stream;
	}
}; typedef bigint<3, 1000> bignum;

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bignum a, b; cin >> a >> b;
	bug(a+b); bug(a-b); bug(a*b);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}