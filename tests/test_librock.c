#include <stdio.h>

#include <librock/librock.h>

int main(int argc, const char* argv[]) {
	RK_UNUSED(argc, argv);

	fprintf(stdout, "stdout\n");
	fprintf(stderr, "stderr\n");

	return 0;
}
