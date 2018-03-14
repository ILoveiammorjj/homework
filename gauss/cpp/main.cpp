#include "parse.h"
#include "gauss.h"

gauss g;

int main(int argc, const char *argv[]) {
	g.read(parse(argc, argv));
	g.write_ans();
	return 0;
}
