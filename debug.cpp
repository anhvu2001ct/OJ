#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define forit(it, l, r) for(auto it = (l); it != (r); ++it)
#define fit(it, var) forit(it, (var).begin(), (var).end())
#define frit(it, var) forit(it, (var).rbegin(), (var).rend())

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb emplace_back
#define sz(v) int((v).size())

template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << v.x << ' ' << v.y;
}

template<typename T> ostream& operator<< (ostream &os, vector<T> const &vec) {
	fto1 (i, 0, sz(vec)) {
		os << vec[i];
		if (i < sz(vec)-1) os << ' ';
	}
	return os;
}

#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 1000000
#define Name "main"

double const pi = acos(-1);
mt19937 rg(chrono::steady_clock::now().time_since_epoch().count());

int rand() {
	return uniform_int_distribution<>(0, maxn)(rg);
}

template<typename T = int>
T rand(T l, T r) {
	return uniform_int_distribution<>(l, r)(rg);
}

double rand(double l, double r) {
	return uniform_real_distribution<>(l, r)(rg);
}

template<typename Type>
Type rand(vector<Type> &vec) {
	return vec[rand(0, sz(vec)-1)];
}

template<typename Type>
void shuffleVec(vector<Type> &vec) {
	shuffle(vec.begin(), vec.end(), rg);
}

template<typename Type = int>
vector<Type> genVec(int n, Type l = 1, Type r = maxn) {
	vector<Type> res(n); fit (it, res) *it = rand(l, r);
	return res;
}

template<typename T1 = int, typename T2 = int>
vector<pair<T1, T2>> genPair(int n, T1 l1 = 1, T1 r1 = maxn, T2 l2 = 1, T2 r2 = maxn) {
	vector<pair<T1, T2>> res(n); fit (it, res) it->x = rand(l1, r1), it->y = rand(l2, r2);
	return res;
}

vector<ii> genTree(int n, int root = 1, int minDepth = 1) {
	minDepth = max(min(minDepth, n), 1);
	vector<int> node, used(1, root);
	fto (i, 1, n) if (i != root) node.pb(i);
	shuffleVec(node);
	vector<ii> res;
	static auto push = [&](int from) {
		res.pb(from, node.back());
		used.pb(node.back());
		node.pop_back();
	};
	while (--minDepth) push(used.back());
	while (!node.empty()) push(rand(used));
	return res;
}

template<typename Type = int>
vector<pair<ii, Type>> genWTree(int n, int root = 1, int minDepth = 1, Type l = 1, Type r = maxn) {
	minDepth = max(min(minDepth, n), 1);
	vector<int> node, used(1, root);
	fto (i, 1, n) if (i != root) node.pb(i);
	shuffleVec(node);
	vector<pair<ii, Type>> res;
	static auto push = [&](int from) {
		res.pb(ii(from, node.back()), rand(l, r));
		used.pb(node.back());
		node.pop_back();
	};
	while (--minDepth) push(used.back());
	while (!node.empty()) push(rand(used));
	return res;
}

template<typename Type>
void outf(ofstream &f, Type const &var) {
	f << var << endl;
}

template<typename Type, typename... Args>
void outf(ofstream &f, Type const &var, Args const &... args) {
	f << var << ' ';
	outf(f, args...);
}

template<typename Type>
void outvec(ofstream &f, vector<Type> const &vec) {
	fto1 (i, 0, sz(vec)) f << vec[i] << endl;
}

void runTest() {
	system(Name".exe");
	system(Name"_debug.exe");
}

string& formatted(string &str) {
	for (int i = sz(str)-1; i >= 0; --i) {
		if (str[i] != ' ') return i == sz(str)-1 ? str : str.erase(i+1);
	}
	return str;
}

void validTest(int const &iTest) {
	runTest();
	ifstream out(Name".out"), ans(Name".ans");
	static string answer, output;

	cerr << iTest << ": ";

	for (int i = 1; getline(ans, answer); ++i) {
		if (getline(out, output) && formatted(answer) == formatted(output)) continue;
		cerr << "Wrong answer on line " << i << ".\n";
		exit(0);
	}

	if (getline(out, output)) {
		cerr << "Warning, too much lines.\n";
		exit(0);
	}

	cerr << "OK.\n";
}



/**
 *  --[[ Generating will start here ]]--
 * **** Examples: ****
 * @single param -> outp(int);
 * @vector -> outp(vector);
 * @multi params -> outp(int, pair, string, vector, ...);
 * @using inp -> inp << char << double << pair << vector;
**/
void genTest() {
	#define nTest 1
	#define outp(args...) outf(inp, args)
	#define outv(vec) outvec(inp, v)
	ofstream inp(Name".inp");
	int t = rand(1, 50);
	outp(t);
	fto(i, 1, t) {
		int n = rand(1, 50);
		int m = rand(1, 50);		
		auto a = genVec(n, 1, 1000000000);
		auto b = genVec(m, 1, 1000000000);
		outp(n, m);
		outp(a);
		outp(b);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fto (iTest, 1, nTest) {
		genTest();
		//validTest(iTest);
	}

	return 0;
}
