#include <munit.h>

#define LIBROCK_IMPL
#include <librock.h>

static const MunitSuite test_suite = {0};

int main(int argc, char *argv[]) {
    return munit_suite_main(&test_suite, (void *)"µnit", argc, argv);
}
