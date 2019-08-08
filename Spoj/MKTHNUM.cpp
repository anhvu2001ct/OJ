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
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

char* sfm(const char *fmt, ...) {
	static char res[256];va_list args;va_start(args, fmt);vsnprintf(res, 256, fmt, args);va_end(args);return res;
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003

struct data {
	int lid, rid, cnt;
	data(int l, int r, int cnt): lid(l), rid(r), cnt(cnt) {}
};

vector<data> node(1, data(0, 0, 0));
int n, q;
int a[maxn], root[maxn], b[maxn];

int create(int l, int r, int pos, int root) {
	if (l > pos || r < pos) return root;
	if (l == r) node.pb(data(0, 0, node[root].cnt + 1));
	else {
		int mid = (l+r)/2;
		node.pb(data(create(l, mid, pos, node[root].lid), create(mid+1, r, pos, node[root].rid), node[root].cnt + 1));
	}
	return sz(node)-1;
}

int query(int id1, int id2, int k, int l, int r) {
	if (l == r) return l;
	int cnt = node[node[id1].lid].cnt - node[node[id2].lid].cnt;
	int mid = (l+r)/2;
	if (cnt >= k) return query(node[id1].lid, node[id2].lid, k, l, mid);
	return query(node[id1].rid, node[id2].rid, k - cnt, mid+1, r);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	scanf("%d%d", &n, &q);

	fto (i, 1, n) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	sort(b + 1, b + 1 + n);

	fto (i, 1, n) {
		int pos = lower_bound(b + 1, b + 1 + n, a[i]) - b;
		root[i] = create(1, n, pos, root[i-1]);
	}

	int u, v, k;
	while (q--) {
		scanf("%d%d%d", &u, &v, &k);
		printf("%d\n", b[query(root[v], root[u-1], k, 1, n)]);
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}