#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for (int i = s; i <= e; ++i)
#define fto1(i, s, e) for (int i = s; i < e; ++i)
#define fdto(i, s, e) for (int i = s; i >= e; --i)
#define fdto1(i, s, e) for (int i = s; i > e; --i)
#define fit(var, it) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for (__typeof(var.rbegin()) it = var.rbegin(); it != var.rend(); ++it)

#define newl '\n'
#define Vname(var) #var
#define debugt cerr << 0.001*clock() << newl
#define debug1(x, i) cout << Vname(x) << '[' << i << ']' << " = " << x[i] << newl
#define debug2(x, i, j) cout << Vname(x) << '[' << i << ']' << '[' << j << ']' << " = " << x[i][j] << newl

template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}

#define ll long long
#define ii pair<int, int>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define glen(v) ((int) (v).size())

#define eps 1e-15
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003

struct node {
	ii val;
	pair<ii, int> mn;
	int sz, y;
	bool rev;
	node *l, *r;

	node(ii const val) {
		sz = mn.ss = 1;
		this->val = mn.ff = val;
		rev = 0;
		y = (rand() << 15) ^ rand();
		l = r = nullptr;
	}
};

typedef node* pnode;

int getsz(pnode t) {
	return t ? t->sz : 0;
}

pair<ii, int> getmn(pnode t) {
	return t ? t->mn : mp(ii(oo, oo), oo);
}

int getp(pnode t) {
	return t ? t->mn.ss : -1;
}

void down(pnode t) {
	if (!t || !t->rev) return;
	if (t->l) t->l->rev ^= 1;
	if (t->r) t->r->rev ^= 1;
	swap(t->l, t->r);
	t->rev = 0;
	t->mn.ss = t->sz - t->mn.ss + 1;
}

void upd(pnode t) {
	if (!t) return;
	down(t->l); down(t->r);
	t->sz = 1 + getsz(t->l) + getsz(t->r);
	t->mn = min(mp(t->val, 1 + getsz(t->l)), getmn(t->l));
	pair<ii, int> tmp = getmn(t->r);
	if (t->mn > tmp) t->mn = mp(tmp.ff, tmp.ss + 1 + getsz(t->l));
}

void merge(pnode &t, pnode l, pnode r) {
	down(l); down(r);
	if (!l || !r) t = l ? l : r;
	else if (l->y > r->y) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd(t);
}

void split(pnode t, int k, pnode &l, pnode &r) {
	if (!t) l = r = nullptr;
	else {
		down(t);
		int sz = getsz(t->l);
		if (sz+1 < k) {
			split(t->r, k-sz-1, t->r, r);
			l = t;
		} else {
			split(t->l, k, l, t->l);
			r = t;
		}
		upd(t);
	}
}

int n, x;
pnode tmp1, tmp2, root;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);
	srand(time(0));

	while (scanf("%d", &n), n) {
		fto (i, 1, n) {
			scanf("%d", &x);
			merge(root, root, new node(ii(x, i)));
		}

		fto (i, 1, n) {
			int p = getp(root);
			printf("%d ", p+i-1);
			split(root, p+1, root, tmp1);
			root->rev ^= 1;
			split(root, 2, root, tmp2);
			delete root;
			merge(root, tmp2, tmp1);
		}
		puts("");
	}

	return 0;
}
