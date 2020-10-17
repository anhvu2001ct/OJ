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
	int n = rand(5, 10);
	auto a = genVec(n, 1, 20);
	int q = 7;
	outp(n, q);
	outp(a);
	fto (i, 1, q) {
		int t = rand(1, 3);
		int l = rand(1, n), r = rand(l, n);
		if (t == 3) outp(t, l, r);
		else outp(t, l, r, rand(1, 10));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fto (iTest, 1, 10) {
		genTest();
		runTest();
		validTest(iTest);
	}

	return 0;
}
