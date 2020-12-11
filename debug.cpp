#include "debug.hpp"

using namespace debug;
using namespace validate;

#define oo 1000000007
#define OO 1000000000000000003LL

int const maxn = 1e7+3;
double const pi = acos(-1);

template<typename Type>
void outf(ostream &os, Type const &var) {
	os << var << endl;
}

template<typename Type, typename... Args>
void outf(ostream &os, Type const &var, Args const &... args) {
	os << var << ' ';
	outf(os, args...);
}

void runTest(bool runAns = 1) {
	system("main.exe");
	if (runAns) system("main_debug.exe");
}

void genTest() {
	#define outp(args...) outf(inp, args)
	ofstream inp("main.inp");
	int tc = rand(1, 1);
	outp(tc);
	while (tc--) {
		int n = rand(1e6, 1e6), m = rand(1e6, 1e6);
		outp(n, m);
		auto a = genVec(n, 0, INT_MAX);
		outp(a);
		while (m--) {
			int t = rand(0, 2), l = rand(1, n), r = rand(l, n), x = rand(0, INT_MAX);
			if (t == 0) outp(t, l, r, x);
			else outp(t, l, r);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fto (iTest, 1, 1) {
		genTest();
		runTest(0);
		// validTest(iTest);
	}

	return 0;
}
