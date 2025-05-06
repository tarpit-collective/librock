#include <munit.h>
#include <stdio.h>

#define LIBROCK_IMPL
#include <librock.h>

MunitResult sys_pool_create_free(const MunitParameter params[], void *usr) {
    (void)usr;
    (void)params;

    fprintf(stderr, "LMAOOOOO\n");
    // munit_assert(1 == 0);

    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/sys_pool_create_free", sys_pool_create_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite test_suite = {"/pools", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

int main(int argc, char *argv[]) {
    // rk_err_t err;
    // rk_arena_pool_t arena = rk_arena_pool(0x10000, &err);
    // rk_pool_vt_t *pl = RK_POOL(&arena);

    // const char *hello = "Hello, World!";
    // rk_id_t msg = rk_pool_new(pl, hello, strlen(hello), &err);

    // const char *ptr = rk_pool_get_ptr(pl, msg, &err);
    // printf("message: %s\n", ptr);

    // rk_pool_del(pl, msg, &err);
    // rk_pool_free(pl);

    return munit_suite_main(&test_suite, (void *)"µnit", argc, argv);
}
