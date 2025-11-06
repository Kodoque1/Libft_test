#include "acutest.h"
#include "Libft/libft.h"
#include<limits.h>
#include <stdio.h>
#include <stdlib.h>

void test_strnstr(void)
{
    char *str;
    str = ft_strnstr("bonjoujour tout le monde","jour",24);
    TEST_CHECK(strcmp(str, "jour tout le monde") == 0);
    TEST_MSG("Expected: jour tout le monde");
    TEST_MSG("Found: %s", str);
    str = ft_strnstr("bonjoujour tout le monde","",24);
    TEST_CHECK(strcmp(str, "bonjoujour tout le monde") == 0);
    TEST_MSG("Expected: bonjoujour tout le monde");
    TEST_MSG("Found: %s", str);
    str = ft_strnstr("bonjoujour tout le monde","jour", 4);
    TEST_CHECK(str == NULL);
    TEST_MSG("jour should not have been found");
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
    TEST_MSG("0 is alnum");
    TEST_CHECK(ft_isalnum('a'));
    TEST_MSG("a is alnum");
    TEST_CHECK(ft_isalnum('A'));
    TEST_MSG("A is alnum");
    TEST_CHECK(!ft_isalnum(';'));
    TEST_MSG("; is alnum");
}

void test_isalpha(void)
{
    TEST_CHECK(ft_isalpha('a'));
    TEST_MSG("a is alpha");
    TEST_CHECK(ft_isalpha('A'));
    TEST_MSG("A is alpha");
    TEST_CHECK(!ft_isalpha('0'));
    TEST_MSG("0 is not alpha");
}

void test_isdigit(void)
{
    TEST_CHECK(ft_isdigit('0'));
    TEST_MSG("0 is digit");
    TEST_CHECK(!ft_isdigit('A'));
    TEST_MSG("A is not digit");
}

void test_isprint(void)
{
    TEST_CHECK(ft_isprint('A'));
    TEST_MSG("A is print");
    TEST_CHECK(!ft_isprint(20));
    TEST_MSG("Value 20 is not print");
}

void test_tolower(void)
{
    char c;
    c = ft_tolower('\n');
    TEST_CHECK(ft_tolower('\n') == '\n');
    TEST_MSG("Expected: %s", "\\n");
    TEST_MSG("Found: %c", c);
    c = ft_tolower('a');
    TEST_CHECK_(c == 'a', "Checking invariant");
    TEST_MSG("Expected: %s", "a");
    TEST_MSG("Found: %c", c);
    c = ft_tolower('A');
    TEST_CHECK_( c == 'a', "Checking conversion");
    TEST_MSG("Expected: %s", "a");
    TEST_MSG("Found: %c", c);
}

void test_toupper(void)
{
    char c;
    c = ft_toupper('\n');
    TEST_CHECK(c == '\n');
    TEST_MSG("Expected: %s", "\\n");
    TEST_MSG("Found: %c", c);
    c = ft_toupper('A');
    TEST_CHECK_( c == 'A', "Checking invariant");
    TEST_MSG("Expected: %s", "A");
    TEST_MSG("Found: %c", c);
    c = ft_toupper('a');
    TEST_CHECK_(c == 'A', "Checking conversion");
    TEST_MSG("Expected: %s", "A");
    TEST_MSG("Found: %c", c);
}

void test_memset(void)
{
    char buffer[5];
    char buffer2[5] = {5,5,5,5,5};
    ft_memset(buffer, 5, 5);
    TEST_CHECK(memcmp(buffer, buffer2, 5) == 0);
    TEST_MSG("Expected {5,5,5,5,5}");
}

void test_memcpy(void)
{
    char buffer[5];
    char buffer2[5] = {1,2,3,4,5};
    ft_memcpy(buffer, buffer2, 5);
    TEST_CHECK(memcmp(buffer, buffer2, 5) == 0);
    TEST_MSG("Expected {1,2,3,4,5}");
}

void test_memmove(void)
{
    char buffer[5] = {5,5,5};
    char buffer1[5] = {1,2,5,5,5};
    ft_memmove(buffer1, buffer1 + 2, 3);
    TEST_CHECK(memcmp(buffer, buffer1, 3) == 0);
    TEST_MSG("Expected {5,5,5}");
}

void test_strchr(void)
{
    char *str;
    str = ft_strchr("bonjoujour",'j');
    TEST_CHECK(strcmp(str, "joujour") == 0);
    TEST_MSG("Expected: joujour");
    TEST_MSG("Found: %s", str);
}

void test_strrchr(void)
{
    char *str;
    str = ft_strrchr("bonjoujour",'j');
    TEST_CHECK(strcmp(str, "jour") == 0);
    TEST_MSG("Expected: jour");
    TEST_MSG("Found: %s", str);
}

void test_strlcpy(void)
{
    char buffer[5] = {0};
    int len;
    len = ft_strlcpy(buffer, "Bonjour", 5);
    TEST_CHECK(strcmp(buffer, "Bonj") == 0);
    TEST_MSG("Expected : Bonj");
    TEST_MSG("Found: %s", buffer);
    TEST_CHECK(len == strlen("Bonjour"));
    TEST_MSG("Expected : %d", (int) strlen("Bonjour"));
    TEST_MSG("Found: %d", len);
}

void test_strlcat(void)
{
    char buffer[10] = {0};
    char buffer1[10] = {0};
    int len, len1;
    strcpy(buffer,"Bon");
    len = ft_strlcat(buffer, "jour", 5);
    TEST_CHECK(strcmp(buffer, "Bonj") == 0);
    TEST_MSG("Expected : Bonj");
    TEST_MSG("Found: %s", buffer);
    strcpy(buffer1,"Bon");
    len1 = ft_strlcat(buffer1, "jour", 5);
    TEST_CHECK(len == len1);
    TEST_MSG("Expected : %d", len1);
    TEST_MSG("Found: %d", len);
}

void test_strlen(void)
{
    int len = ft_strlen("Bonjour");
    int len1 = strlen("Bonjour");
    TEST_CHECK(len = len1);
    TEST_MSG("Expected : %d", len1);
    TEST_MSG("Found: %d", len);
}

void test_strnlen(void)
{
    int len = ft_strnlen("Bonjour", 3);
    int len1 = strnlen("Bonjour" , 3);
    TEST_CHECK(len = len1);
    TEST_MSG("Expected : %d", len1);
    TEST_MSG("Found: %d", len);
}

void test_strncmp(void)
{
    TEST_CHECK(ft_strncmp("ABC", "ABC", 3) == 0);
    TEST_MSG("Expected equality");
    TEST_CHECK(ft_strncmp("ABC", "AB", 3) > 0);
    TEST_MSG("Expected superior");
    TEST_CHECK(ft_strncmp("ABA", "ABZ", 3) < 0);
    TEST_MSG("Expected inferior");
    TEST_CHECK(ft_strncmp("\201", "A", 3) > 0);
    TEST_MSG("Expected inferior");
    TEST_CHECK(ft_strncmp("ABC", "AB", 2) == 0);
    TEST_MSG("Expected equality");
}

void test_strdup(void)
{
    char *buffer = ft_strdup("Bonjour");
    TEST_CHECK(strcmp(buffer, "Bonjour") == 0);
    TEST_MSG("Expected Bonjour");
}

char test_toloweri1(unsigned int i, char c)
{
    if( i % 2 == 0)
        return ft_tolower(c);
    return (c);
}

void test_strmapi(void)
{
    
    char *buffer = (char*) ft_strmapi("Bonjour", test_toloweri1);
    TEST_CHECK(strcmp(buffer, "Bonjour") == 0);
    TEST_MSG("Expected Bonjour");
    free(buffer);
}

void test_toloweri(unsigned int i, char *c)
{
    if( i % 2 == 0)
        *c = ft_tolower(*c);
}

void test_striteri(void)
{
    char buffer[] = "Bonjour";
    ft_striteri(buffer, test_toloweri);
    TEST_CHECK(strcmp(buffer, "bOnJoUr") == 0);
    TEST_MSG("Expected bOnJoUr");
    TEST_MSG("Found: %s", buffer);
}

void test_substr(void)
{
    char *buffer = ft_strdup("Bonjour tout le monde");
    char *buffer1 = ft_substr(buffer, 8, 4);
    TEST_CHECK(strcmp(buffer1, "tout") == 0);
    TEST_MSG("Expected bOnJoUr");
    TEST_MSG("Found: %s", buffer1);
    free(buffer);
    free(buffer1);
    buffer = ft_strdup("Bonjour tout le monde");
    buffer1 = ft_substr(buffer, 22, 22);
    TEST_CHECK(strcmp(buffer1, "") == 0);
    TEST_MSG("Expected empty string");
    TEST_MSG("Found: %s", buffer1);
}

void test_strjoin(void)
{
    char *buffer = ft_strjoin("tata","toto");
    TEST_CHECK(strcmp(buffer, "tatatoto") == 0);
    TEST_MSG("Expected bOnJoUr");
    TEST_MSG("Found: %s", buffer);
}

void test_strtrim(void)
{
    char *buffer = ft_strtrim("   t t  "," ");
    TEST_CHECK(strcmp(buffer, "t t") == 0);
    TEST_MSG("Expected \"t t\"");
    TEST_MSG("Found: %s", buffer);
}

void compare_array(char **a1, char **a2)
{
    int i = 0;
    while(a1[i])
    {
        TEST_CHECK(strcmp(a1[i], a2[i]) == 0);
        TEST_MSG("Expected: %s", a1[i]);
        TEST_MSG("Found: %s", a2[i]);
        i++;
    }
}

void free_aos(char **a1)
{
    while(*a1)
    {
        free(*a1);
        a1++;
    }
}

void test_split(void)
{
    char* aos[] = {"Bonjour","tout","le","monde"};
    char **aos_test = ft_split("  Bonjour tout le monde  ", ' ');
    compare_array(aos_test, aos);
    free_aos(aos_test);
    char* aos1[] = {"Bonjour"};
    aos_test = ft_split("Bonjour", ' ');
    compare_array(aos_test, aos1);
    free_aos(aos_test);
}

void test_itoa(void)
{
    char *buffer = ft_itoa(INT_MIN);
    TEST_CHECK(strcmp(buffer, "-2147483648") == 0);
    TEST_MSG("Expected: %s", "-2147483648");
    TEST_MSG("Found: %s", buffer);
    free(buffer);
    buffer = ft_itoa(INT_MAX);
    TEST_CHECK(strcmp(buffer, "2147483647") == 0);
    TEST_MSG("Expected: %s", "2147483647");
    TEST_MSG("Found: %s", buffer);
    free(buffer);
    buffer = ft_itoa(0);
    TEST_CHECK(strcmp(buffer, "0") == 0);
    TEST_MSG("Expected: %s", "0");
    TEST_MSG("Found: %s", buffer);
    free(buffer);
}

void test_calloc(void)
{
    char *buf = calloc(2,5);
    char buf_test[10] = {0};
    TEST_CHECK(memcmp(buf, buf_test, 10) == 0);
    TEST_MSG("Expected: %s", "NULL buffer");
}

void test_putchar_fd(void)
{
    char c;
    int f = open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putchar_fd('c', f);
    close(f);
    f = open("test.txt", O_RDWR, 0644);
    read(f, &c, 1);
    TEST_CHECK(c =='c');
    TEST_MSG("Expected: %s", "0");
    TEST_MSG("Found: %s", &c);
    close(f);
    unlink("test.txt");
}

void test_putstr_fd(void)
{
    char str[5] = {0};
    int f = open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putstr_fd("toto", f);
    close(f);
    f = open("test.txt", O_RDWR, 0644);
    read(f, str, 4);
    TEST_CHECK(strcmp(str, "toto") == 0);
    TEST_MSG("Expected: %s", "0");
    TEST_MSG("Found: %s", str);
    close(f);
    unlink("test.txt");
}

void test_putendl_fd(void)
{
    char str[6] = {0};
    int f = open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putendl_fd("toto", f);
    close(f);
    f = open("test.txt", O_RDWR, 0644);
    read(f, str, 5);
    TEST_CHECK(strcmp(str, "toto\n") == 0);
    TEST_MSG("Expected: %s", "toto\\n");
    TEST_MSG("Found: %s", str);
    close(f);
    unlink("test.txt");
}

void test_putnbr_fd(void)
{
    char str[12] = {0};
    int f = open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putnbr_fd(INT_MIN, f);
    close(f);
    f = open("test.txt", O_RDWR, 0644);
    read(f, str, 11);
    TEST_CHECK(strcmp(str, "-2147483648") == 0);
    TEST_MSG("Expected: %s", "0");
    TEST_MSG("Found: %s", str);
    close(f);
    unlink("test.txt");
    open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putnbr_fd(INT_MAX, f);
    close(f);
    f = open("test.txt", O_RDWR, 0644);
    ft_bzero(str, 12);
    read(f, str, 10);
    TEST_CHECK(strcmp(str, "2147483647") == 0);
    TEST_MSG("Expected: %s", "2147483647");
    TEST_MSG("Found: %s", str);
    close(f);
    unlink("test.txt");
    open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putnbr_fd(0, f);
    close(f);
    f = open("test.txt", O_RDWR, 0644);
    ft_bzero(str, 12);
    read(f, str, 1);
    TEST_CHECK(strcmp(str, "0") == 0);
    TEST_MSG("Expected: %s", "0");
    TEST_MSG("Found: %s", str);
    close(f);
    unlink("test.txt");
}



TEST_LIST = {
   { "ft_strnstr", test_strnstr },
   { "ft_atoi", test_atoi },
   { "ft_bzero", test_bzero },
   { "ft_isalnum", test_isalnum },
   { "ft_isalpha", test_isalpha },
   { "ft_isdigit", test_isdigit },
   { "ft_isprint", test_isprint },
   { "ft_tolower", test_tolower },
   { "ft_toupper", test_toupper },
   { "ft_memset", test_memset },
   { "ft_memcpy", test_memcpy },
   { "ft_strchr", test_strchr },
   { "ft_strrchr", test_strrchr },
   { "ft_strlcat", test_strlcat },
   { "ft_strlen", test_strlen },
   { "ft_strnlen", test_strnlen },
   { "ft_strdup", test_strdup },
   { "ft_substr", test_substr },
   { "ft_strjoin", test_strjoin },
   { "ft_strtrim", test_strtrim },
   { "ft_split", test_split },
   { "ft_itoa", test_itoa },
   { "ft_putchar_fd", test_putchar_fd },
   { "ft_putstr_fd", test_putendl_fd },
   { "ft_putnbr_fd", test_putnbr_fd },
   { "ft_putendl_fd", test_putendl_fd },
   { "ft_calloc", test_calloc },
   { "ft_strlcpy", test_strlcpy },
   { NULL, NULL }     /* zeroed record marking the end of the list */
};