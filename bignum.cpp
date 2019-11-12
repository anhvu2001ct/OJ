#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)

#define bc __builtin_popcountll
#define isb(x, bit) (((x >> bit) & 1) != 0)
#define onb(x, bit) (x | (1LL << bit))
#define offb(x, bit) (x & ~(1LL << bit))
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

template<class T> ostream& operator<<(ostream &os, vector<T> const &v) {
	fto1 (i, 0, sz(v)) { os << v[i]; if (i < sz(v)-1) os << ' '; }
	return os;
}

template<class T> void buga(const T &v, int l, int r) { fto (i, l, r) { cout << v[i] << " \n"[i == r]; } }

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }
 
double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 2e5+3;

struct bignum {
	vector<ll> a;
	short sign;

	static const int base     = 1000000000;
	static const short digits = 9;

	bignum() { a.clear(); sign = 1; }

	bignum(string const &s) {
		int pos = 0;
		*this = bignum();
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

	void plus(bignum const &v) {
		a.resize(max(sz(a), sz(v.a)));
		fto1 (i, 0, sz(v.a)) a[i] += v.a[i];
	}

	void minus(bignum const &v) {
		a.resize(max(sz(a), sz(v.a)));
		fto1 (i, 0, sz(v.a)) a[i] -= v.a[i];
	}

	bignum& operator+=(bignum const &v) {
		if (sign == v.sign) plus(v);
		else if (less_abs(v, 1)) {
				bignum tmp = v;
				tmp.minus(*this);
				sign *= -1, a = tmp.a;
		} else minus(v);
		trim(); return *this;
	}

	bignum& operator-=(bignum const &v) {
		bignum tmp = v;
		tmp.sign *= -1;
		return (*this) += tmp;
	}

	bignum& operator*=(const int v) {
		if (v < 0) sign = -sign;
		fto1 (i, 0, sz(a)) a[i] *= v;
		trim(); return *this;
	}

	#define _multi(index, value) res.a[index] += value, res.a[index+1] += res.a[index]/base, res.a[index] %= base

	bignum multiply(bignum const &v) const {
		bignum res;
		res.a.resize(sz(a) + sz(v.a));
		fto1 (i, 0, sz(a)) fto1 (j, 0, sz(v.a)) _multi(i+j, a[i] * v.a[j]);
		res.trim(); return res;
	}

	static bignum karatsuba(bignum x, bignum y) {
		int n = max(sz(x.a), sz(y.a));
		if (n <= 40) return x.multiply(y);
		while (sz(x.a) < n) x.a.pb(0);
		while (sz(y.a) < n) y.a.pb(0);
		int m = n >> 1;
		bignum x0, x1, y0, y1;
		x0.a.assign(x.a.begin(), x.a.begin() + m);
		x1.a.assign(x.a.begin() + m, x.a.end());
		y0.a.assign(y.a.begin(), y.a.begin() + m);
		y1.a.assign(y.a.begin() + m, y.a.end());
		bignum a = karatsuba(x0, y0), c = karatsuba(x1, y1);
		bignum b = karatsuba(x1+x0, y1+y0) - a - c;
		bignum res;
		res.a.resize(n+n);
		fto1 (i, 0, sz(a.a)) _multi(i, a.a[i]);
		fto1 (i, 0, sz(b.a)) _multi(i+m, b.a[i]);
		fto1 (i, 0, sz(c.a)) _multi(i+m+m, c.a[i]);
		res.trim(); return res;
	}

	bignum& operator*=(bignum const &v) {
		short s = sign * v.sign;
		*this = karatsuba(*this, v);
		this->sign = s;
		return *this;
	}

	bool less_abs(bignum const &v, short sign) const {
		if (sz(a) != sz(v.a)) return sz(a) * sign < sz(v.a) * sign;
		fdto (i, sz(a)-1, 0) if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
		return 0;
	}
	
	bool operator<(bignum const v) const {
		return (sign != v.sign) ? (sign < v.sign) : less_abs(v, sign);
	}

	bool operator>(bignum const v) const { return v < *this; }

	bool operator<=(bignum const v) const { return !(*this > v); }

	bool operator>=(bignum const v) const { return !(*this < v); }

	void trim() {
		a.pb(0);
		fto1 (i, 0, sz(a)-1) {
			if (a[i] < 0) --a[i+1], a[i] += base;
			else a[i+1] += a[i]/base, a[i] %= base;
		}
		while (sz(a) && a.back() == 0) a.pop_back();
		if (!sz(a)) sign = 1;
	}

	friend bignum operator+(bignum l, bignum const &r) { return l += r; }
	
	friend bignum operator-(bignum l, bignum const &r) { return l -= r; }

	friend bignum operator*(bignum l, bignum const &r) { return l *= r; }

	friend bignum operator*(bignum l, const int r) { return l *= r; }

	friend bignum abs(bignum v) { v.sign = 1; return v; }

	friend istream& operator>>(istream &stream, bignum& v) {
		string tmp; stream >> tmp; v = bignum(tmp);
		return stream;
	}

	friend ostream& operator<<(ostream &stream, bignum const& v) {
		if (!sz(v.a)) return stream << 0;
		if (v.sign == -1) stream << '-';
		stream << v.a.back();
		fdto (i, sz(v.a)-2, 0) stream << setfill('0') << setw(digits) << v.a[i];
		return stream;
	}
};

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bignum a, b;
	cin >> a >> b;
	bug(a+b, (a*b).tostring());

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}