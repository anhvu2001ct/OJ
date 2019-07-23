#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(var, it) for (auto it = (var).begin(); it != (var).end(); ++it)
#define frit(var, it) for (auto it = (var).rbegin(); it != (var).rend(); ++it)

#define newl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

#define bc __builtin_popcountll
#define onb(x, bit) (x & (1 << bit))
#define gcd __gcd
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}

template<class T> ostream& operator<< (ostream &os, vector<T> const &v) {
	os << sz(v) << '[';fto1 (i, 0, sz(v)) {os << v[i]; if (i < sz(v)-1) os << ',';}return os << ']';
}

char* sfm(const char *fmt, ...) {
	static char res[100];va_list args;va_start(args, fmt);vsnprintf(res, 100, fmt, args);va_end(args);return res;
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003



int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(nullptr);



	return 0;
}