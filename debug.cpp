#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fat(i, a) for(auto i : (a))

#define bc __builtin_popcountll
#define y1 ansdj
#define endl '\n'

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb emplace_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

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
#define Name "main"

int const maxn = 1e7+3;
double const pi = acos(-1);
mt19937_64 rg(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll first = 0, ll last = maxn) {
	return uniform_int_distribution<>(first, last)(rg);
}

double randf(double first = 0.0, double last = maxn) {
	return uniform_real_distribution<>(first, last)(rg);
}

template<class T>
T rand(vector<T> const &v) {
	return v[rand(0, sz(v)-1)];
}

template<typename Type>
void shuffleVec(vector<Type> &vec) {
	shuffle(all(vec), rg);
}

vector<ll> genVec(int n, ll l = 1, ll r = maxn) {
	vector<ll> res(n); fat (&v, res) v = rand(l, r);
	return res;
}

vector<int> genPermu(int n) {
	vector<int> res(n); fto1 (i, 0, n) res[i] = i+1;
	shuffleVec(res);
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
	shuffleVec(res);
	return res;
}

vector<pair<ii, ll>> genWTree(int n, int root = 1, int minDepth = 1, ll l = 1, ll r = maxn) {
	minDepth = max(min(minDepth, n), 1);
	vector<int> node, used(1, root);
	fto (i, 1, n) if (i != root) node.pb(i);
	shuffleVec(node);
	vector<pair<ii, ll>> res;
	static auto push = [&](int from) {
		res.pb(ii(from, node.back()), rand(l, r));
		used.pb(node.back());
		node.pop_back();
	};
	while (--minDepth) push(used.back());
	while (!node.empty()) push(rand(used));
	shuffleVec(res);
	return res;
}

template<typename Type>
void outf(ostream &os, Type const &var) {
	os << var << endl;
}

template<typename Type, typename... Args>
void outf(ostream &os, Type const &var, Args const &... args) {
	os << var << ' ';
	outf(os, args...);
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
 * @using inp -> inp << string << double << pair << vector;
**/

void moveTest(string id, string tid) {
	system(("mkdir " + tid).c_str());
	system(Name".exe");
	system(("copy "Name".inp " + id + ".inp").c_str());
	system(("copy "Name".out " + id + ".out").c_str());
	system(("move " + id + ".inp " + tid).c_str());
	system(("move " + id + ".out " + tid).c_str());
}

string makeID(string id, int n, int num) {
	ostringstream ss; ss << id << setw(num) << setfill('0') << n;
	return ss.str();
}

void genTest() {
	#define outp(args...) outf(inp, args)
	ofstream inp(Name".inp");
	int n = 1e2, m = 1e9;
	outp(n, m);
	outp(genVec(n, 1, 1e5));
	outp(n*(n+1)/2);
	fto (i, 1, n) fto (j, i, n) outp(i, j);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fto (iTest, 10, 10) {
		genTest();
		moveTest("I", makeID("test", iTest, 2));
		//validTest(iTest);
	}

	return 0;
}
