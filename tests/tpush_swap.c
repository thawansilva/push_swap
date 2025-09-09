#include "minunit.h"
#include "../include/push_swap.h"
#include "test_push_swap.c"

int main(void)
{
	MU_RUN_SUITE(push_swap_test_suite);
	MU_REPORT();

	return MU_EXIT_CODE;
}
