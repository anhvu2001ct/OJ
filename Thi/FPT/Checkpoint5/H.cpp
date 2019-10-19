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

int n;
ii ans[maxn];
bool visited[maxn];
vector<int> a[maxn];

void bfs(int x) {
	queue<int> q;
	vector<int> vec;
	q.push(x);
	visited[x] = 1;
	ans[x] = {1, 2};
	int cnt = 2;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		bool flag = 1;
		fit (it, a[u]) {
			int v = *it;
			if (visited[v]) continue;
			visited[v] = 1;
			vec.pb(v);
			ans[v].x = ++cnt;
			ans[v].y = flag ? ans[u].x : ans[u].y;
			flag ^= 1;
		}
		if (q.empty()) {
			while (!vec.empty()) q.push(vec.back()), vec.pop_back();
		}
	}
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;

	int u, v;
	fto1 (i, 1, n) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}

	bfs(1);

	fto (i, 1, n) {
		bug(ans[i].x, ans[i].y);
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}