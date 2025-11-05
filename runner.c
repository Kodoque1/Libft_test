#include "acutest.h"
#include "Libft/libft.h"
#include<limits.h>
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

void test_isprint(void)
{
    TEST_CHECK(ft_isprint('A'));
    TEST_MSG('A is print');
    TEST_CHECK(!ft_isprint(20));
    TEST_MSG('Value 20 is not print');
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

void test_memmove(void)
{
    char buffer[5] = {5,5,5};
    char buffer1[5] = {1,2,5,5,5};
    ft_memmove(buffer1, buffer1 + 2, 3);
    TEST_CHECK(memcmp(buffer, buffer1, 3) == 0);
    TEST_MSG('Expected {5,5,5}');
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

void test_strnstr(void)
{
    char *str;
    str = ft_strstr("bonjoujour tout le monde","jour",24);
    TEST_CHECK(strcmp(str, "jour tout le monde") == 0);
    TEST_MSG('Expected: jour tout le monde');
    TEST_MSG('Found: %s', str);
    str = ft_strstr("bonjoujour tout le monde","",24);
    TEST_CHECK(strcmp(str, "bonjoujour tout le monde") == 0);
    TEST_MSG('Expected: bonjoujour tout le monde');
    TEST_MSG('Found: %s', str);
    str = ft_strnstr("bonjoujour tout le monde","jour", 4);
    TEST_CHECK(str == NULL);
    TEST_MSG('jour should not have been found');
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

void test_strncmp(void)
{
    TEST_CHECK(ft_strncmp("ABC", "ABC", 3) == 0);
    TEST_MSG('Expected equality');
    TEST_CHECK(ft_strncmp("ABC", "AB", 3) > 0);
    TEST_MSG('Expected superior');
    TEST_CHECK(ft_strncmp("ABA", "ABZ", 3) < 0);
    TEST_MSG('Expected inferior');
    TEST_CHECK(ft_strncmp("\201", "A", 3) > 0);
    TEST_MSG('Expected inferior');
    TEST_CHECK(ft_strncmp("ABC", "AB", 2) == 0);
    TEST_MSG('Expected equality');
}

void test_strdup(void)
{
    char *buffer = ft_strdup("Bonjour");
    TEST_CHECK(strcmp(buffer, "Bonjour") == 0);
    TEST_MSG('Expected Bonjour');
}

void test_toloweri(unsigned int i, char *c)
{
    if( i % 2 == 0)
        *c = ft_tolower(*c);
}

void test_strmapi(void)
{
    
    char *buffer = (char*) ft_strmapi("Bonjour", test_toloweri);
    TEST_CHECK(strcmp(buffer, "Bonjour") == 0);
    TEST_MSG('Expected Bonjour');
    free(buffer);
}

void test_striteri(void)
{
    char buffer[] = "Bonjour";
    ft_striteri(buffer, test_toloweri);
    TEST_CHECK(strcmp(buffer, "bOnJoUr") == 0);
    TEST_MSG('Expected bOnJoUr');
    TEST_MSG('Found: %d', buffer);
}

void test_substr(void)
{
    char *buffer = ft_strdup("Bonjour tout le monde");
    char *buffer1 = ft_substr(buffer, 8, 4);
    TEST_CHECK(strcmp(buffer1, "tout") == 0);
    TEST_MSG('Expected bOnJoUr');
    TEST_MSG('Found: %d', buffer1);
    free(buffer);
    free(buffer1);
    char *buffer = ft_strdup("Bonjour tout le monde");
    char *buffer1 = ft_substr(buffer, 22, 22);
    TEST_CHECK(strcmp(buffer1, "") == 0);
    TEST_MSG('Expected empty string');
    TEST_MSG('Found: %d', buffer1);
}

void test_strjoin(void)
{
    char *buffer = ft_strjoin("tata","toto");
    TEST_CHECK(strcmp(buffer, "tatatoto") == 0);
    TEST_MSG('Expected bOnJoUr');
    TEST_MSG('Found: %d', buffer);
}

void test_strtrim(void)
{
    char *buffer = ft_strtrim("   t t  "," ");
    TEST_CHECK(strcmp(buffer, "t t") == 0);
    TEST_MSG('Expected "t t"');
    TEST_MSG('Found: %d', buffer);
}

void compare_array(char **a1, char **a2)
{
    int i = 0;
    while(a1[i])
    {
        TEST_CHECK(strcmp(a1[i], a2[i]) == 0);
        TEST_MSG('Expected: %s', a1[i]);
        TEST_MSG('Found: %s', a2[i]);
        i++;
    }
}

void free_aos(char **a1)
{
    while(*a1)
    {
        free(a1);
        a1++;
    }
}

void test_split(void)
{
    char* aos[] = {"Bonjour","tout","le","monde"};
    char **aos_test = ft_split("  Bonjour tout le monde  ", ' ');
    compare_array(aos_test, aos);
    free_aos(aos_test);
    free(aos_test);
    char* aos1[] = {"Bonjour"};
    aos_test = ft_split("Bonjour", ' ');
    compare_array(aos_test, aos1);
    free_aos(aos_test);
    free(aos_test);
}

void test_itoa(void)
{
    char *buffer = ft_itoa(INT_MIN);
    TEST_CHECK(strcmp(buffer, "-2147483648") == 0);
    TEST_MSG('Expected: %s', "-2147483648");
    TEST_MSG('Found: %s', buffer);
    free(buffer);
    buffer = ft_itoa(INT_MAX);
    TEST_CHECK(strcmp(buffer, "2147483647") == 0);
    TEST_MSG('Expected: %s', "2147483647");
    TEST_MSG('Found: %s', buffer);
    free(buffer);
    buffer = ft_itoa(0);
    TEST_CHECK(strcmp(buffer, "0") == 0);
    TEST_MSG('Expected: %s', "0");
    TEST_MSG('Found: %s', buffer);
    free(buffer);
}

void test_putchar_fd(void)
{
    char c;
    int f = open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putchar_fd('c', f);
    fseek(f, 0, SEEK_SET);
    read(f, &c, 1);
    TEST_CHECK(c =='c');
    TEST_MSG('Expected: c', "0");
    TEST_MSG('Found: %s', &c);
    close(f);
    unlink("test.txt");
}

void test_putstr_fd(void)
{
    char str[5] = {0};
    int f = open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putstr_fd("toto", f);
    fseek(f, 0, SEEK_SET);
    read(f, str, 4);
    TEST_CHECK(strcmp(str, "toto") == 0);
    TEST_MSG('Expected: toto', "0");
    TEST_MSG('Found: %s', str);
    close(f);
    unlink("test.txt");
}

void test_putendl_fd(void)
{
    char str[6] = {0};
    int f = open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putendl_fd("toto", f);
    fseek(f, 0, SEEK_SET);
    read(f, str, 4);
    TEST_CHECK(strcmp(str, "toto\n") == 0);
    TEST_MSG('Expected: toto\\n', "0");
    TEST_MSG('Found: %s', str);
    close(f);
    unlink("test.txt");
}

void test_putnbr_fd(void)
{
    char str[12] = {0};
    int f = open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putendl_fd(INT_MIN, f);
    fseek(f, 0, SEEK_SET);
    read(f, str, 11);
    TEST_CHECK(strcmp(str, "-2147483648") == 0);
    TEST_MSG('Expected: -2147483648', "0");
    TEST_MSG('Found: %s', str);
    close(f);
    unlink("test.txt");
    open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putendl_fd(INT_MAX, f);
    fseek(f, 0, SEEK_SET);
    read(f, str, 10);
    TEST_CHECK(strcmp(str, "2147483647") == 0);
    TEST_MSG('Expected: 2147483647', "0");
    TEST_MSG('Found: %s', str);
    close(f);
    unlink("test.txt");
    open("test.txt", O_CREAT | O_RDWR, 0644);
    ft_putendl_fd(0, f);
    fseek(f, 0, SEEK_SET);
    read(f, str, 1);
    TEST_CHECK(strcmp(str, "0") == 0);
    TEST_MSG('Expected: 0', "0");
    TEST_MSG('Found: %s', str);
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
   { "ft_memmove", test_memmove },


   { NULL, NULL }     /* zeroed record marking the end of the list */
};