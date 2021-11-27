struct DSU {
	vector<int> p;
	vector<tuple<int,int,int>> st;
	int comps;

	void init(int n) {
		p.resize(n+1, -1);
		comps = n;
	}

	int get(int u) {
		return p[u] < 0 ? u : get(p[u]);
	}

	bool unify(int u, int v) {
		u = get(u); v = get(v);
		if (u == v) return false;
		if (p[u] > p[v]) swap(u, v);
		st.emplace_back(u, v, p[v]);
		p[u] += p[v];
		p[v] = u;
		--comps;
		return true;
	}

	void rollback() {
		auto [u, v, size] = st.back();
		st.pop_back();
		p[u] -= (p[v] = size);
		++comps;
	}
} dsu;