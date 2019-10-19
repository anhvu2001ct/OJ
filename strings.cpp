#include <bits/stdc++.h>
#include <ext/rope>
 
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

string tmp, R;
int t, x, y;
char c;

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;
	bool flag = 1;
	while (t--) {
		__gnu_cxx::rope<char> s;
		cin >> tmp;
		fit (it, tmp) s.pb(*it);

		while (cin >> c) {
			if (c == 'I') {
				cin >> R >> x;
				if (x == sz(s)) fit (it, R) s.pb(*it);
				else frit (it, R) s.insert(x, *it);
			} else if (c == 'P') {
				cin >> x >> y;
				if (flag) flag = 0;
				else cout << endl;
				cout << s.substr(x, y-x+1);
			} else break;
		}
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}