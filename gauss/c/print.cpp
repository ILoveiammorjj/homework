
#include <cstdio>

void print(int ans, int n, double x[]) {
	if (ans) {
		puts(ans > 0 ? "One solution:" : "Infinitely many solutions. Example:");
		for (int i(0); i < n; ++i)
			printf("%.3lf ", x[i]);
	} else
		puts("Solutions do not exist");
}
