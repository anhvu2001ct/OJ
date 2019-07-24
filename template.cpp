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

char __c; 
template<typename T> void read(T &val) {
    for (__c = getchar(); __c != '-' && (__c < '0' || __c > '9'); __c = getchar());
    bool neg = (__c == '-'); if (neg) val = 0; else val = __c - '0';
    for (__c = getchar(); __c >= '0' && __c <= '9'; __c = getchar()) val = val*10 + __c - '0';
    if (neg) val = -val;
}
void read(char &c) { c = getchar(); }
void read(string &s) {
	for (__c = getchar(); __c == ' ' || __c == '\n'; __c = getchar());
	if (__c != EOF) s += __c; for (__c = getchar(); __c != ' ' && __c != '\n' && __c != EOF; __c = getchar()) s += __c;
}

template<typename T, typename... Args> void read(T &val, Args&... args) { read(val); read(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 1000003



int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	
	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}