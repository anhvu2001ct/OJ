#include <bits/stdc++.h>
using namespace std;

char* sfm(const char *fmt, ...) {
	static char res[100];va_list args;va_start(args, fmt);vsnprintf(res, 100, fmt, args);va_end(args);return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
    return 0;
}