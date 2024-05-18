/*
** EPITECH PROJECT, 2024
** LIB
** File description:
** test_libc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Test for my_put_nbr function
Test(libc, my_put_nbr, .init = redirect_all_std)
{
    char *output = "-92";

    my_put_nbr(-92);

    cr_assert_stdout_eq_str(output);
}

// Test for my_putchar function
Test(libc, my_putchar, .init = redirect_all_std)
{
    char *output = "a";

    my_putchar('a');

    cr_assert_stdout_eq_str(output);
}

// Test for my_putstr function
Test(libc, my_putstr, .init = redirect_all_std)
{
    char *output = "test\n";

    my_putstr("test\n");

    cr_assert_stdout_eq_str(output);
}

// Test for my_strlen function
Test(libc, my_strlen)
{
    int return_val = my_strlen("test\n");

    cr_assert_eq(return_val, 5);
}

// Test for my_getnbr function
Test(libc, my_getnbr)
{
    int return_val = my_getnbr("59974");
    int return_val2 = my_getnbr("-1");

    cr_assert_eq(return_val, 59974);
    cr_assert_eq(return_val2, -1);
}

// Test for my_strcmp function
Test(libc, my_strcmp)
{
    bool return_val = my_strcmp("abcdefg", "abcdefg");
    bool return_val2 = my_strcmp("abc", "abcd");

    cr_assert_eq(return_val, 1);
    cr_assert_eq(return_val2, 0);
}

// Test for my_strcat function
Test(libc, my_strdup)
{
    char *test = "abcdefg";
    char *return_val = my_strdup("abcdefg");

    cr_assert_str_eq(return_val, test);
}

// Test for my_strcat function
Test(libc, my_strcat)
{
    char *s1 = "abc";
    char *s2 = "def";
    char *expected_result = "abcdef";
    char *return_val = my_strcat(s1, s2);

    cr_assert_str_eq(return_val, expected_result);
    free(return_val);
}

// Test for my_check_malloc_arr function
Test(libc, my_check_malloc_arr, .init = redirect_all_std)
{
    char **arr = NULL;

    my_check_malloc_arr(arr);

    cr_assert_stdout_eq_str("Error: unsuccessful malloc\n");
}

// Test for my_check_malloc_str function
Test(libc, my_check_malloc_str, .init = redirect_all_std)
{
    char *str = NULL;

    my_check_malloc_str(str);

    cr_assert_stdout_eq_str("Error: unsuccessful malloc\n");
}

// Test for is_arg_correct function
Test(libc, is_arg_correct)
{
    bool return_val = is_arg_correct('A');
    bool return_val2 = is_arg_correct('7');

    cr_assert_eq(return_val, 1);
    cr_assert_eq(return_val2, 0);
}

// Test for my_isalnum function
Test(libc, my_isalnum)
{
    bool return_val = my_isalnum('_');
    bool return_val2 = my_isalnum('=');

    cr_assert_eq(return_val, 1);
    cr_assert_eq(return_val2, 0);
}

// Test for is_arg_correct function
Test(libc, is_arg_correct2)
{
    bool return_val = is_arg_correct2("hello");
    bool return_val2 = is_arg_correct2("hel=lo");

    cr_assert_eq(return_val, 1);
    cr_assert_eq(return_val2, 0);
}

// Test for my_getnbr function
Test(libc, my_count_char)
{
    char *str = NULL;
    int return_val = my_count_char("it is: a test:");
    int return_val2 = my_count_char(str);

    cr_assert_eq(return_val, 2);
    cr_assert_eq(return_val2, 0);
}

// Test for my_strcpy function
Test(libc, my_strcpy)
{
    char src[] = "Hello, World!";
    char dest[50];
    char *return_val = my_strcpy(dest, src);

    cr_assert_str_eq(return_val, dest);
    cr_assert_str_eq(return_val, src);

    cr_assert_eq(dest[strlen(src)], '\0');
}

// Test for my_getnbr function
Test(libc, linked_list_len)
{
    list_t *list = create_list();
    int return_val = linked_list_len(list);

    cr_assert_eq(return_val, 0);
    push_to_list_tail(list, "haha");
    int return_val2 = linked_list_len(list);
    cr_assert_eq(return_val2, 1);
}

// Test for mprintf function
Test(libc, mprintf, .init = redirect_all_std)
{
    mprintf("integer: %d, character: %c, string: %s, %%", 42, 'H', "Hello");
    cr_assert_stdout_eq_str("integer: 42, character: H, string: Hello, %%");
}
