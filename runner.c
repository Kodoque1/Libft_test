#include "acutest.h"
#include "Libft/libft.h"
#include <stdio.h>

void test_strnstr(void)
{
    const char big[]= "BonBonjour";
    const char little[]= "Bonjour";

    TEST_CHECK(ft_strnstr(big, little, 11) == strstr(big, little));
    TEST_CHECK(ft_strnstr(big, "", 11) == strstr(big, ""));
}

void test_atoi(void)
{
    TEST_CHECK(ft_atoi("  -123ABC") == atoi("  -123ABC"));
    TEST_CHECK(ft_atoi("  123ABC") == atoi("   123ABC"));
}

void test_bzero(void)
{
    char buffer[50];
    char buffer1[50] = {0};
    ft_bzero(buffer, 50);
    int r = memcmp(buffer, buffer1, 50); 
    TEST_CHECK(r == 0);
    TEST_MSG("Expected same buffer, comparison result: %d", 1);
}

void test_isalnum(void)
{
    TEST_CHECK(ft_isalnum('0'));
    TEST_MSG('0 is alnum');
    TEST_CHECK(ft_isalnum('a'));
    TEST_MSG('a is alnum');
    TEST_CHECK(ft_isalnum('A'));
    TEST_MSG('A is alnum');
    TEST_CHECK(!ft_isalnum(';'));
    TEST_MSG('; is alnum');
}

void test_isalpha(void)
{
    TEST_CHECK(ft_isalpha('a'));
    TEST_MSG('a is alpha');
    TEST_CHECK(ft_isalpha('A'));
    TEST_MSG('A is alpha');
    TEST_CHECK(!ft_isalpha('0'));
    TEST_MSG('0 is not alpha');
}

void test_isdigit(void)
{
    TEST_CHECK(ft_isdigit('0'));
    TEST_MSG('0 is digit');
    TEST_CHECK(!ft_isdigit('A'));
    TEST_MSG('A is not digit');
}

void test_islower(void)
{
    TEST_CHECK(ft_islower('a'));
    TEST_MSG('a is lower');
    TEST_CHECK(!ft_islower('A'));
    TEST_MSG('A is not lower');
}

void test_isprint(void)
{
    TEST_CHECK(ft_isprint('A'));
    TEST_MSG('A is print');
    TEST_CHECK(!ft_isprint(20));
    TEST_MSG('Value 20 is not print');
}

void test_isspace(void)
{
    TEST_CHECK(ft_isspace('\n'));
    TEST_MSG('\\n is space');
    TEST_CHECK(!ft_isspace('a'));
    TEST_MSG('a is not space');
}

void test_tolower(void)
{
    TEST_CHECK(ft_tolower('\n') == '\n');
    TEST_MSG('newline should stay the same');
    TEST_CHECK(ft_tolower('a') == 'a');
    TEST_MSG('a should stay a');
    TEST_CHECK(ft_tolower('A') == 'a');
    TEST_MSG('A should become a');
}

void test_toupper(void)
{
    TEST_CHECK(ft_toupper('\n') == '\n');
    TEST_MSG('newline should stay the same');
    TEST_CHECK(ft_toupper('a') == 'a');
    TEST_MSG('a should stay a');
    TEST_CHECK(ft_toupper('A') == 'a');
    TEST_MSG('A should become a');
}

void test_memset(void)
{
    char buffer[5];
    char buffer2[5] = {5,5,5,5,5};
    ft_memset(buffer, 5, 5);
    TEST_CHECK(memcmp(buffer, buffer2, 5) == 0);
    TEST_MSG('Expected {5,5,5,5,5}');
}

void test_memcpy(void)
{
    char buffer[5];
    char buffer2[5] = {1,2,3,4,5};
    ft_memcpy(buffer, buffer2, 5);
    TEST_CHECK(memcmp(buffer, buffer2, 5) == 0);
    TEST_MSG('Expected {1,2,3,4,5}');
}

void test_memcpy(void)
{
    char buffer[5];
    char buffer2[5] = {1,2,3,4,5};
    ft_memcpy(buffer, buffer2, 5);
    TEST_CHECK(memcmp(buffer, buffer2, 5) == 0);
    TEST_MSG('Expected {1,2,3,4,5}');
}

void test_memmove(void)
{
    char buffer[5] = {5,5,5};
    char buffer1[5] = {1,2,5,5,5};
    ft_memmove(buffer1, buffer1 + 2, 3);
    TEST_CHECK(memcmp(buffer, buffer1, 3) == 0);
    TEST_MSG('Expected {5,5,5}');
}

void test_memccpy(void)
{
    char buffer[5] = {1,2,3,4,5};
    char buffer1[5] = {1,2,3,4,0};
    char buffer2[5] = {0};
    ft_memccpy(buffer2, buffer, 4, 5);
    TEST_CHECK(memcmp(buffer2, buffer1, 5) == 0);
    TEST_MSG('Expected {1,2,3,4,0}');
}

void test_strchr(void)
{
    char *str;
    str = ft_strchr("bonjoujour",'j');
    TEST_CHECK(strcmp(str, "joujour") == 0);
    TEST_MSG('Expected: joujour');
    TEST_MSG('Found: %s', str);
}

void test_strrchr(void)
{
    char *str;
    str = ft_strrchr("bonjoujour",'j');
    TEST_CHECK(strcmp(str, "jour") == 0);
    TEST_MSG('Expected: jour');
    TEST_MSG('Found: %s', str);
}

void test_strstr(void)
{
    char *str;
    str = ft_strstr("bonjoujour tout le monde","jour");
    TEST_CHECK(strcmp(str, "jour tout le monde") == 0);
    TEST_MSG('Expected: jour tout le monde');
    TEST_MSG('Found: %s', str);
    str = ft_strstr("bonjoujour tout le monde","");
    TEST_CHECK(strcmp(str, "bonjoujour tout le monde") == 0);
    TEST_MSG('Expected: bonjoujour tout le monde');
    TEST_MSG('Found: %s', str);
}

void test_strnstr(void)
{
    char *str;
    str = ft_strnstr("bonjoujour tout le monde","jour", 4);
    TEST_CHECK(str == NULL);
    TEST_MSG('jour should not have been found');
}

void test_strcpy(void)
{
    char buffer[10] = {0};
    ft_strcpy(buffer,"Bonjour");
    TEST_CHECK(strcmp(buffer, "Bonjour") == 0);
    TEST_MSG('Expected : Bonjour');
    TEST_MSG('Found: %s', buffer);
}

void test_strncpy(void)
{
    char buffer[10] = {0};
    ft_strncpy(buffer,"Bonjour", 3);
    TEST_CHECK(strcmp(buffer, "Bon") == 0);
    TEST_MSG('Expected : Bon');
    TEST_MSG('Found: %s', buffer);
}

void test_strcat(void)
{
    char buffer[10] = {0};
    ft_strcpy(buffer,"Bon");
    ft_strcat(buffer, "jour");
    TEST_CHECK(strcmp(buffer, "Bonjour") == 0);
    TEST_MSG('Expected : Bonjour');
    TEST_MSG('Found: %s', buffer);
}

void test_strncat(void)
{
    char buffer[10] = {0};
    ft_strcpy(buffer,"Bon");
    ft_strncat(buffer, "jour", 1);
    TEST_CHECK(strcmp(buffer, "Bonj") == 0);
    TEST_MSG('Expected : Bonj');
    TEST_MSG('Found: %s', buffer);
}

void test_strlcat(void)
{
    char buffer[10] = {0};
    char buffer1[10] = {0};
    int len, len1;
    ft_strcpy(buffer,"Bon");
    len = ft_strlcat(buffer, "jour", 5);
    TEST_CHECK(strcmp(buffer, "Bonj") == 0);
    TEST_MSG('Expected : Bonj');
    TEST_MSG('Found: %s', buffer);
    ft_strcpy(buffer1,"Bon");
    len1 = ft_strlcat(buffer1, "jour", 5);
    TEST_CHECK(len == len1);
    TEST_MSG('Expected : %d', len1);
    TEST_MSG('Found: %d', len);
}

void test_strlen(void)
{
    int len = ft_strlen("Bonjour");
    int len1 = strlen("Bonjour");
    TEST_CHECK(len = len1);
    TEST_MSG('Expected : %d', len1);
    TEST_MSG('Found: %d', len);
}

void test_strnlen(void)
{
    int len = ft_strnlen("Bonjour", 3);
    int len1 = strnlen("Bonjour" , 3);
    TEST_CHECK(len = len1);
    TEST_MSG('Expected : %d', len1);
    TEST_MSG('Found: %d', len);
}

void test_strcmp(void)
{
    TEST_CHECK(ft_strcmp("ABC", "ABC") == 0);
    TEST_MSG('Expected equality');
    TEST_CHECK(ft_strcmp("ABC", "AB") > 0);
    TEST_MSG('Expected superior');
    TEST_CHECK(ft_strcmp("ABA", "ABZ") < 0);
    TEST_MSG('Expected inferior');
    TEST_CHECK(ft_strcmp("\201", "A") > 0);
    TEST_MSG('Expected inferior');
}

void test_strncmp(void)
{
    TEST_CHECK(ft_strncmp("ABC", "AB", 2) == 0);
    TEST_MSG('Expected equality');
}

void test_strdup(void)
{
    char *buffer = ft_strdup("Bonjour");
    TEST_CHECK(strcmp(buffer, "Bonjour") == 0);
    TEST_MSG('Expected Bonjour');
}

void test_memalloc(void)
{
    char *buffer = ft_memalloc(10);
    char buffer1[] = {0};
    TEST_CHECK(memcmp(buffer, buffer1, 10) == 0);
    TEST_MSG('Expected same buffer');
}


TEST_LIST = {
   { "ft_strnstr", test_strnstr },
   { "ft_atoi", test_atoi },
   { "ft_bzero", test_bzero },
   { "ft_bzero", test_isalnum },
   { "ft_bzero", test_isalpha },

   { NULL, NULL }     /* zeroed record marking the end of the list */
};