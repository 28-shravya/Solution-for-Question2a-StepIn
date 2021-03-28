#include "unity.h"
#include "unity_internals.h"
#include "header.h"
#include <string.h>

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void test_empty(void)
{
    TEST_ASSERT_EQUAL(1,read_array("data.csv"));
    TEST_ASSERT_EQUAL(0,read_array("candidate_id.csv"));
}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
    /* Run Test functions */
    RUN_TEST(test_empty);
    /* Close the Unity Test Framework */
    return UNITY_END();
}
