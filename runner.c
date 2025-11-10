#include "acutest.h"
#include "Libft/libft.h"
#include<limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

/*
- Compare to the real function
- Valgrind:
- substr
- strjoin
*/

void test_strnstr(void)
{
    char *str;
    char *tgt;
    char static_str[] = "bonjoujour tout le monde";
    str = ft_strnstr(static_str, "jour",24);
    tgt = strnstr(static_str, "jour",24);
    TEST_CHECK(strcmp(str, tgt) == 0);
    TEST_MSG("Expected: %s", tgt);
    TEST_MSG("Found: %s", str);
    str = ft_strnstr(static_str,"",24);
    tgt = strnstr(static_str, "",24);
    TEST_CHECK(strcmp(str, tgt) == 0);
    TEST_MSG("Expected: %s", tgt);
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
    char buffer1[50];
    ft_bzero(buffer, 50);
    bzero(buffer1, 50);
    TEST_CHECK(memcmp(buffer, buffer1, 50)  == 0);
    TEST_DUMP("Expected:", buffer1, 50);
    TEST_DUMP("Produced:", buffer, 50);
}

void test_isalnum(void)
{
    int chr;
    int tgt;
    for(int i = 0; i < 128; i++)
    {
        chr = ft_isalnum(i);
        tgt = isalnum(i);
        TEST_CHECK(!((chr > 0) ^ (tgt > 0)));
        TEST_MSG("Expected: %d", tgt);
        TEST_MSG("Expected: %d", chr);
    }
}

void test_isalpha(void)
{
    int chr;
    int tgt;
    for(int i = 0; i < 128; i++)
    {
        chr = ft_isalpha(i);
        tgt = isalpha(i);
        TEST_CHECK(!((chr > 0) ^ (tgt > 0)));
        TEST_MSG("Expected: %d", tgt);
        TEST_MSG("Expected: %d", chr);
    }
}

void test_isdigit(void)
{
    int chr;
    int tgt;
    for(int i = 0; i < 128; i++)
    {
        chr = ft_isdigit(i);
        tgt = isdigit(i);
        TEST_CHECK(!((chr > 0) ^ (tgt > 0)));
        TEST_MSG("Expected: %d", tgt);
        TEST_MSG("Expected: %d", chr);
    }
}

void test_isprint(void)
{
    int chr;
    int tgt;
    for(int i = 0; i < 128; i++)
    {
        chr = ft_isprint(i);
        tgt = isprint(i);
        TEST_CHECK(!((chr > 0) ^ (tgt > 0)));
        TEST_MSG("Expected: %d", tgt);
        TEST_MSG("Expected: %d", chr);
    }
}

void test_tolower(void)
{
    int chr;
    int tgt;
    for(int i = 0; i < 128; i++)
    {
        chr = ft_tolower(i);
        tgt = tolower(i);
        TEST_CHECK(chr == tgt);
        TEST_MSG("Expected: %d", tgt);
        TEST_MSG("Expected: %d", chr);
    }
    chr = ft_tolower(EOF);
    TEST_CHECK(chr == -1);
    TEST_MSG("Expected: %d", tgt);
    TEST_MSG("Expected: %d", chr);
}

void test_toupper(void)
{
    int chr;
    int tgt;
    for(int i = 0; i < 128; i++)
    {
        chr = ft_toupper(i);
        tgt = toupper(i);
        TEST_CHECK(chr == tgt);
        TEST_MSG("Expected: %d", tgt);
        TEST_MSG("Expected: %d", chr);
    }
    chr = ft_toupper(EOF);
    TEST_CHECK(chr == -1);
    TEST_MSG("Expected: %d", tgt);
    TEST_MSG("Expected: %d", chr);
}

void test_memset(void)
{
    char buf[5];
    char tgt[5];
    ft_memset(buf, 5, 5);
    memset(tgt, 5, 5);
    TEST_CHECK(memcmp(buf, tgt, 5) == 0);
    TEST_DUMP("Expected:", tgt, 5);
    TEST_DUMP("Produced:", buf, 5);
}

void test_memcpy(void)
{
    char buf[5];
    char tgt[5];
    char static_tgt[5] = {1,2,3,4,5};
    ft_memcpy(buf, static_tgt, 5);
    memcpy(tgt, static_tgt, 5);
    TEST_CHECK(memcmp(buf, tgt, 5) == 0);
    TEST_DUMP("Expected:", tgt, 5);
    TEST_DUMP("Produced:", buf, 5);
}

void test_memmove(void)
{
    char buffer[5] = {1,2,3,4,5};
    char tgt[5] = {1,2,3,4,5};
    ft_memmove(buffer, buffer + 2, 3);
    memmove(tgt, tgt + 2, 3);
    TEST_CHECK(memcmp(buffer, tgt, 3) == 0);
    TEST_DUMP("Expected:", tgt, 3);
    TEST_DUMP("Produced:", buffer, 3);
    ft_memmove(buffer + 2, buffer, 3);
    memmove(tgt + 2, tgt, 3);
    TEST_CHECK(memcmp(buffer, tgt, 3) == 0);
    TEST_DUMP("Expected:", tgt, 3);
    TEST_DUMP("Produced:", buffer, 3);
    ft_memmove(buffer, buffer, 3);
    memmove(tgt, tgt, 3);
    TEST_CHECK(memcmp(buffer, tgt, 3) == 0);
    TEST_DUMP("Expected:", tgt, 3);
    TEST_DUMP("Produced:", buffer, 3);
}

void test_strchr(void)
{
    char *str;
    char *tgt;
    char static_chr[] = "bonjoujour";
    str = ft_strchr(static_chr,'j');
    tgt = strchr(static_chr,'j');
    TEST_CHECK(strcmp(str, tgt) == 0);
    TEST_MSG("Expected: %s", tgt);
    TEST_MSG("Found: %s", str);
}

void test_strrchr(void)
{
    char *str;
    char *tgt;
    char static_chr[] = "bonjoujour";
    str = ft_strrchr(static_chr,'j');
    tgt = strrchr(static_chr,'j');
    TEST_CHECK(strcmp(str, tgt) == 0);
    TEST_MSG("Expected: %s", tgt);
    TEST_MSG("Found: %s", str);
}

void test_strlcpy(void)
{
    char buffer[5] = {0};
    char tgt[5] = {0};
    int len;
    int len_tgt;
    len = ft_strlcpy(buffer, "Bonjour", 5);
    len_tgt = ft_strlcpy(tgt, "Bonjour", 5);
    TEST_CHECK(strcmp(buffer, tgt) == 0);
    TEST_MSG("Expected : %s", tgt);
    TEST_MSG("Found: %s", buffer);
    TEST_CHECK(len == len_tgt);
    TEST_MSG("Expected : %d", len_tgt);
    TEST_MSG("Found: %d", len);
    ft_bzero(buffer, 5);
    ft_bzero(tgt, 5);
    len = ft_strlcpy(buffer, "Bonjour", 0);
    len_tgt = ft_strlcpy(tgt, "Bonjour", 0);
    TEST_CHECK(strcmp(buffer, tgt) == 0);
    TEST_MSG("Expected : %s", tgt);
    TEST_MSG("Found: %s", buffer);
    TEST_CHECK(len == len_tgt);
    TEST_MSG("Expected : %d", len_tgt);
    TEST_MSG("Found: %d", len);
}

void test_strlcat(void)
{
    char buffer[10] = {0};
    char tgt[10] = {0};
    int len, len_tgt;
    strcpy(buffer,"Bon");
    strcpy(tgt,"Bon");
    len = ft_strlcat(buffer, "jour", 5);
    len_tgt = strlcat(tgt, "jour", 5);
    TEST_CHECK(strcmp(buffer, tgt) == 0);
    TEST_MSG("Expected : %s", tgt);
    TEST_MSG("Found: %s", buffer);
    ft_bzero(buffer, 0);
    ft_bzero(tgt, 0);
    strcpy(buffer,"Bon");
    strcpy(tgt,"Bon");
    len = ft_strlcat(buffer, "jour", 0);
    len_tgt = strlcat(tgt, "jour", 0);
    TEST_CHECK(strcmp(buffer, tgt) == 0);
    TEST_MSG("Expected : %s", tgt);
    TEST_MSG("Found: %s", buffer);
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
    int len_tgt = strnlen("Bonjour" , 3);
    TEST_CHECK(len = len_tgt);
    TEST_MSG("Expected : %d", len_tgt);
    TEST_MSG("Found: %d", len);
    len = ft_strnlen("Bonjour", 15);
    len_tgt = strnlen("Bonjour" , 15);
    TEST_CHECK(len = len_tgt);
    TEST_MSG("Expected : %d", len_tgt);
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
    char *tgt = strdup("Bonjour");
    TEST_CHECK(strcmp(buffer, tgt) == 0);
    TEST_MSG("Expected : %s", tgt);
    TEST_MSG("Found : %s", buffer);
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
    buffer1 = ft_substr(buffer, 21, 0);
    TEST_CHECK(strcmp(buffer1, "") == 0);
    TEST_MSG("Expected empty string");
    TEST_MSG("Found: %s", buffer1);
}

void test_strjoin(void)
{
    char *buffer = ft_strjoin("tata","totoo");
    TEST_CHECK(strcmp(buffer, "tatatotoo") == 0);
    TEST_MSG("Expected : %s", "tatatotoo");
    TEST_MSG("Found: %s", buffer);
    free(buffer);
    buffer = ft_strjoin("","totoo");
    TEST_CHECK(strcmp(buffer, "totoo") == 0);
    TEST_MSG("Expected : %s", "totoo");
    TEST_MSG("Found: %s", buffer);
    free(buffer);
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

void test_lstnew(void)
{
    char *content = ft_strdup("Bonjour");
    t_list* list = NULL;
    list = ft_lstnew(content);
    TEST_CHECK(list != NULL);
    TEST_MSG("Expected: %s", "Not Null");
    TEST_CHECK(strcmp((char*) list->content, "Bonjour") == 0);
    TEST_MSG("Expected: %s", "Bonjour");
    TEST_MSG("Found: %s", (char*) list->content);
    TEST_CHECK(list->next == NULL);
    TEST_MSG("Expected: %s", "NULL");
    TEST_MSG("Found: %p", list->next);
    free(list->content);
    free(list);
}

void test_lstadd_front(void)
{
    char *test_string[] = {"Bonjour", "Hello", "Hola", "Salam"};
    t_list* list;
    list = NULL;
    for(int i = 0; i < 4;i++)
        ft_lstadd_front(&list, ft_lstnew(test_string[i]));
    for(int i = 0; i < 4;i++)
    {
        TEST_CHECK(strcmp((char*) list->content, test_string[3 - i]) == 0);
        TEST_MSG("Expected: %s", test_string[3 - i]);
        TEST_MSG("Found: %s", (char*) list->content);
        list = list->next;
    }
}

void test_lstsize(void)
{
    char *test_string[] = {"Bonjour", "Hello", "Hola", "Salam"};
    t_list* list;
    int len;
    list = NULL;
    for(int i = 0; i < 4;i++)
        ft_lstadd_front(&list, ft_lstnew(test_string[i]));
    len = ft_lstsize(list);
    TEST_CHECK(len == 4);
    TEST_MSG("Expected: %d", 4);
    TEST_MSG("Found: %d", len);
}

void test_lstlast(void)
{
    char *test_string[] = {"Bonjour", "Hello", "Hola", "Salam"};
    t_list* list;
    t_list* last;
    list = NULL;
    for(int i = 0; i < 4;i++)
        ft_lstadd_front(&list, ft_lstnew(test_string[i]));
    last = ft_lstlast(list);
    TEST_CHECK(strcmp((char*) last->content, "Bonjour") == 0);
    TEST_MSG("Expected: %s", "Bonjour");
    TEST_MSG("Found: %s", (char*) list->content);
}

void test_lstadd_back(void)
{
    char *test_string[] = {"Bonjour", "Hello", "Hola", "Salam"};
    t_list* list;
    list = NULL;
    for(int i = 0; i < 4;i++)
        ft_lstadd_back(&list, ft_lstnew(test_string[i]));
    for(int i = 0; i < 4;i++)
    {
        TEST_CHECK(strcmp((char*) list->content, test_string[i]) == 0);
        TEST_MSG("Expected: %s", test_string[i]);
        TEST_MSG("Found: %s", (char*) list->content);
        list = list->next;
    }
}

void del(void *data)
{
    free(data);
}

void test_lstclear(void)
{
    char *test_string[] = {ft_strdup("Bonjour"), ft_strdup("Hello"), ft_strdup("Hola"), ft_strdup("Salam")};
    t_list* list;
    int len;
    list = NULL;
    for(int i = 0; i < 4;i++)
        ft_lstadd_front(&list, ft_lstnew(test_string[i]));
    ft_lstclear(&list, del);
    len = ft_lstsize(list);
    TEST_CHECK(len == 0);
    TEST_MSG("Expected: %d", 0);
    TEST_MSG("Found: %d", len);
}

void mod(void* data)
{
    char *ptr = (char*) data;
    while(*ptr)
    {
        *ptr = ft_toupper(*ptr);
        ptr++;
    }
}

void *mod_map(void* data)
{
    char *ptr = (char*) data;
    while(*ptr)
    {
        *ptr = ft_toupper(*ptr);
        ptr++;
    }
    return (data);
}

void test_lstiter(void)
{
    char *test_string[] = {ft_strdup("Bonjour"), ft_strdup("Hello"), ft_strdup("Hola"), ft_strdup("Salam")};
    char *post_string[] = {"BONJOUR", "HELLO", "HOLA", "SALAM"};
    t_list* list;
    list = NULL;
    for(int i = 0; i < 4;i++)
        ft_lstadd_front(&list, ft_lstnew(test_string[i]));
    ft_lstiter(list, mod);
    for(int i = 0; i < 4;i++)
    {
        TEST_CHECK(strcmp((char*) list->content, post_string[3 - i]) == 0);
        TEST_MSG("Expected: %s", post_string[i]);
        TEST_MSG("Found: %s", (char*) list->content);
        list = list->next;
    }
}

void test_lstmap(void)
{
    char *test_string[] = {ft_strdup("Bonjour"), ft_strdup("Hello"), ft_strdup("Hola"), ft_strdup("Salam")};
    char *post_string[] = {"BONJOUR", "HELLO", "HOLA", "SALAM"};
    t_list* list;
    list = NULL;
    for(int i = 0; i < 4; i++)
        ft_lstadd_front(&list, ft_lstnew(test_string[i]));
    ft_lstmap(list, mod_map, del);
    for(int i = 0; i < 4;i++)
    {
        TEST_CHECK(strcmp((char*) list->content, post_string[3 - i]) == 0);
        TEST_MSG("Expected: %s", post_string[i]);
        TEST_MSG("Found: %s", (char*) list->content);
        list = list->next;
    }
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
   { "ft_lstnew", test_lstnew },
   { "ft_lstadd_front", test_lstadd_front},
   { "ft_lstiter", test_lstiter},
   { "ft_lstmap", test_lstmap},
   { "ft_lstclear", test_lstclear},
   { "ft_lstadd_back", test_lstadd_back},
   { "ft_lstlast", test_lstlast},
   { "ft_lstsize", test_lstsize},
   { NULL, NULL }     /* zeroed record marking the end of the list */
};
