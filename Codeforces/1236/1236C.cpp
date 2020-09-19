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

template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

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

int n;
oss<int> s;
vector<int> ans[maxn];

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	fto (i, 1, n*n) s.insert(i);

	fto (i, 1, n) {
		if (n%2) {
			int tmp = n;
			while (tmp > 1) {
				if (tmp%2 == 0) {
					ans[i].pb(*s.rbegin());
					s.erase(s.rbegin());
				} else {
					ans[i].pb(*s.begin());
					s.erase(s.begin());
				}
				--tmp;
			}
			auto it = s.find_by_order(sz(s)/2 - (sz(s)%2 == 0));
			ans[i].pb(*it);
			s.erase(it);
		} else {
			int tmp = n;
			while (tmp) {
				if (tmp%2) {
					ans[i].pb(*s.rbegin());
					s.erase(s.rbegin());
				} else {
					ans[i].pb(*s.begin());
					s.erase(s.begin());
				}
				--tmp;
			}
		}
	}

	fto (i, 1, n) bug(ans[i]);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
