#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(var, it) for (auto it = (var).begin(); it != (var).end(); ++it)
#define frit(var, it) for (auto it = (var).rbegin(); it != (var).rend(); ++it)

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

template<typename T> void read(T &val) {
    char c; for (c = getchar(); c != '-' && (c < '0' || c > '9'); c = getchar());
    bool neg = (c == '-'); if (neg) *val = 0; else *val = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) *val = *val*10 + c - '0';
    if (neg) *val = -*val;
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
	
	
	
	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}