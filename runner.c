#include "acutest.h"
#include <stdio.h>

void test_strnstr(void)
{
    const char big[]= "BonBonjour";
    const char little[]= "Bonjour";

    TEST_CHECK(ft_strnstr(big, little, 11) == strstr(big, little));
    TEST_CHECK(ft_strnstr(big, "", 11) == strstr(big, "");
}

TEST_LIST = {
   { "strnstr", test_strnstr },
   ...
   { NULL, NULL }     /* zeroed record marking the end of the list */
};