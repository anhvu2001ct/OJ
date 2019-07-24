#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T, Cmp = less<T>>
using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

char* sfm(const char *fmt, ...) {
	static char res[100];va_list args;va_start(args, fmt);vsnprintf(res, 100, fmt, args);va_end(args);return res;
}