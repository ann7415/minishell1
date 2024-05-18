/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** test_minishell
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Test for copy_name function
Test(env_functions, copy_name)
{
    char *str = "VAR=value";
    int len_name = 4;
    char *name = NULL;

    name = copy_name(name, len_name, str);
    cr_assert_str_eq(name, "VAR");
    free(name);
}

// Test for copy_value function
Test(env_functions, copy_value)
{
    char *str = "VAR=value";
    char *str2 = "VAR=";
    int len_value = 6;
    int k = 4;
    char *value = NULL;
    char *value1 = NULL;

    value1 = copy_value(value1, len_value, str, k);
    value = copy_value(value, len_value, str2, k);
    cr_assert_str_eq(value1, "value");
    cr_assert_str_eq(value, "", "Value should be an empty string");
    len_value = 0;
    value = copy_value(value, len_value, str2, k);
}

// Test for str_to_env_variable function
Test(env_functions, str_to_env_variable)
{
    char *str = "name=value";
    env_variable_t *env_var = malloc(sizeof(env_variable_t));
    env_var = str_to_env_variable(str);
    cr_assert_str_eq(env_var->name, "name");
    cr_assert_str_eq(env_var->value, "value");

    char *str_without_equal = "name_without_equal";
    env_variable_t *env_var_null = str_to_env_variable(str_without_equal);
    cr_assert_null(env_var_null, "Should return NULL when '=' is not present");

    char *str_with_equal = "name=value";
    env_variable_t *env_var2 = str_to_env_variable(str_with_equal);
    cr_assert_str_eq(env_var2->name, "name");
    cr_assert_str_eq(env_var2->value, "value");
    free(env_var2);
}

// Test for env_variable_to_str function
Test(env_functions, env_variable_to_str)
{
    env_variable_t *env_var = malloc(sizeof(env_variable_t));
    env_var->name = "name";
    env_var->value = "value";
    char *str = env_variable_to_str(env_var);
    cr_assert_str_eq(str, "name=value");
    free(env_var);
}

// Test for compare_env_variable function
Test(env_functions, compare_env_variable)
{
    env_variable_t *env_var = malloc(sizeof(env_variable_t));
    env_var->name = "name";
    env_var->value = "value";
    char *str = "name";
    bool result = compare_env_variable(env_var, str);
    cr_assert(result, "Comparison should return true");
    char *non_matching_str = "non_matching_name";
    bool non_matching_result = compare_env_variable(env_var, non_matching_str);
    cr_assert_not(non_matching_result, "Comparison should return false");
    free(env_var);
}

// Test for display_env_variable function
Test(env_functions, display_env_variable, .init = redirect_all_std)
{
    env_variable_t *env_var = malloc(sizeof(env_variable_t));
    env_var->name = "name";
    env_var->value = "value";

    display_env_variable(env_var);
    cr_assert_stdout_eq_str("name=value\n");
}

// Test for create_env_variable function
Test(env_functions, create_env_variable, .init = redirect_all_std)
{
    char *name = "name";
    char *value = "value";
    env_variable_t *env_var = create_env_variable(name, value);

    cr_assert_not_null(env_var);
    cr_assert_str_eq(env_var->name, name);
    cr_assert_str_eq(env_var->value, value);
    destroy_env_variable(env_var);
}

// Test for reverse_list function
Test(env_functions, reverse_list, .init = redirect_all_std)
{
    list_t *original_list = create_list();
    original_list->first = create_node((void *)1);
    original_list->first->next = create_node((void *)2);
    original_list->first->next->next = create_node((void *)3);

    // Reverse the list
    list_t *reversed_list = reverse_list(original_list);

    cr_assert_eq(reversed_list->first->data, (void *)3);
    cr_assert_eq(reversed_list->first->next->data, (void *)2);
    cr_assert_eq(reversed_list->first->next->next->data, (void *)1);

    free(original_list);
    free(reversed_list);
}

// Test for add_node function
Test(env_functions, add_node)
{
    list_t *list = create_list();
    node_t *new_node = create_node(NULL);
    add_node(list, new_node);

    cr_assert_not_null(list->first);
    cr_assert_eq(list->first, new_node);
    cr_assert_null(new_node->prev);
    cr_assert_null(new_node->next);

    free(list);
}

// Test for destroy_node function
Test(env_functions, destroy_node)
{
    int *data = malloc(sizeof(int));
    *data = 42;
    node_t *new_node = create_node(data);

    destroy_node(new_node, free);
    cr_assert(new_node);
}

// Test for delete_node function
Test(env_functions, delete_node)
{
    list_t *list = create_list();
    node_t *node1 = create_node(NULL);
    node_t *node2 = create_node(NULL);
    add_node(list, node1);
    add_node(list, node2);

    delete_node(list, NULL, node1, free);

    cr_assert_eq(list->first, node2);
    free(list);
}

// Test for push_to_list_tail function
Test(env_functions, push_to_list_tail)
{
    list_t *list = create_list();

    char *data1 = "test_data1";
    char *data2 = "test_data2";
    char *data3 = "test_data3";

    cr_assert_not_null(list, "List should not be NULL");
    cr_assert_null(list->first, "First node in the list should be NULL");

    push_to_list_tail(list, data1);
    push_to_list_tail(list, data2);
    push_to_list_tail(list, data3);

    cr_assert_not_null(list->first, "First node in the list should not be NULL");

    free(list);
}

// Test for replace_in_list function
Test(env_functions, replace_in_list)
{
    list_t *list = create_list();
    char *name1 = "name2";
    char *value1 = "value1";
    char *name2 = "name2";
    char *value2 = "value2";
    char *name3 = "name3";
    char *value3 = "value3";
    env_variable_t *replacementEnv = create_env_variable(name2, value2);
    env_variable_t *initialEnv = create_env_variable(name1, value1);
    env_variable_t *initialEnv3 = create_env_variable(name3, value3);
    env_variable_t *initialEnv4 = create_env_variable("name", "value");

    bool result = replace_in_list(list, replacementEnv, NULL);
    cr_assert_not(result, "replace_in_list should return true for successful replacement");

    push_to_list_tail(list, initialEnv);
    push_to_list_tail(list, initialEnv3);

    result = replace_in_list(list, replacementEnv, my_strcmp);
    cr_assert(result, "replace_in_list should return true for successful replacement");
    result = replace_in_list(list, initialEnv4, my_strcmp);
    cr_assert_not(result, "replace_in_list should return false when no match is found");

    cr_assert_not_null(list->first, "First node in the list should not be NULL");
    cr_assert_str_eq(((env_variable_t*)list->first->data)->name, name2, "Name should match");
    cr_assert_str_eq(((env_variable_t*)list->first->data)->value, value2, "Value should match");

    free(list);
}

Test(env_functions, replace_in_list_with_multiple_elements_and_no_match)
{
    list_t *list = create_list();
    char *name1 = "name1";
    char *value1 = "value1";
    char *name2 = "name2";
    char *value2 = "value2";
    char *name3 = "name3";
    char *value3 = "value3";
    env_variable_t *replacementEnv = create_env_variable(name2, value2);
    env_variable_t *initialEnv1 = create_env_variable(name1, value1);
    env_variable_t *initialEnv3 = create_env_variable(name3, value3);

    push_to_list_tail(list, initialEnv1);
    push_to_list_tail(list, initialEnv3);

    bool result = replace_in_list(list, replacementEnv, my_strcmp);

    cr_assert_not(result, "replace_in_list should return false when no match is found");
    cr_assert_not_null(list->first, "First node in the list should not be NULL");
    free(list);
}

// Test for destroy_list function
Test(env_functions, destroy_list)
{
    list_t *list = NULL;

    char *data1 = "test_data1";
    char *data2 = "test_data2";
    char *data3 = "test_data3";

    destroy_list(list, destroy_node);
    cr_assert_null(list, "List should be NULL");

    list = create_list();
    push_to_list_tail(list, data1);
    push_to_list_tail(list, data2);
    push_to_list_tail(list, data3);

}

// Test for delete_in_list function
Test(env_functions, delete_in_list)
{
    list_t *list = create_list();
    char *name1 = "name1";
    char *value1 = "value1";
    char *name2 = "name2";
    char *value2 = "value2";
    char *name3 = "name3";
    char *value3 = "value3";

    env_variable_t *env1 = create_env_variable(name1, value1);
    env_variable_t *env2 = create_env_variable(name2, value2);
    env_variable_t *env3 = create_env_variable(name3, value3);

    push_to_list_tail(list, env1);
    push_to_list_tail(list, env2);
    push_to_list_tail(list, env3);

    bool result = delete_in_list(list, name2, my_strcmp, destroy_env_variable);
    cr_assert_not(result);

    result = delete_in_list(NULL, name2, NULL, destroy_env_variable);
    cr_assert_not(result);

    cr_assert_not_null(list->first, "First node in the list should not be NULL");
    cr_assert_str_eq(((env_variable_t*)list->first->data)->name, name1, "Name should match");
    cr_assert_str_eq(((env_variable_t*)list->first->data)->value, value1, "Value should match");

    // env_variable_t *env4 = create_env_variable("name4", "value4");
    // push_to_list_tail(list, env4);
    // env_variable_t *env5 = create_env_variable("name5", "value5");
    // push_to_list_tail(list, env5);
    // char *ref = "name4";
    // result = delete_in_list(list, ref, my_strcmp, destroy_env_variable);
    // cr_assert(result);

}

// Test for search_in_list function
Test(env_functions, search_in_list)
{
    list_t *list = create_list();
    char *name1 = "name1";
    char *value1 = "value1";
    char *name2 = "name2";
    char *value2 = "value2";
    char *name3 = "name3";
    char *value3 = "value3";

    env_variable_t *env_var1 = create_env_variable(name1, value1);
    env_variable_t *env_var2 = create_env_variable(name2, value2);
    env_variable_t *env_var3 = create_env_variable(name3, value3);

    push_to_list_tail(list, env_var1);
    push_to_list_tail(list, env_var2);
    push_to_list_tail(list, env_var3);

    char *result = search_in_list(list, name2, my_strcmp);
    cr_assert_not_null(result, "Search for an existing element should not return NULL");
    cr_assert_str_eq(result, value2, "Value should match for the existing element");

    result = search_in_list(NULL, name2, my_strcmp);
    cr_assert_null(result, "Search with NULL list should return NULL");

    char *nonExistingName = "nonExistingName";
    result = search_in_list(list, nonExistingName, my_strcmp);
    cr_assert_null(result, "Search for a non-existing element should return NULL");

    result = search_in_list(list, name2, NULL);
    cr_assert_null(result, "Search with NULL compare function should return NULL");

    destroy_env_variable(env_var1);
    destroy_env_variable(env_var2);
    destroy_env_variable(env_var3);
    free(list);
}

// Test for display_list function
Test(env_functions, display_list, .init = redirect_all_std)
{
    list_t *list = create_list();
    env_variable_t *env_var = create_env_variable("name", "value");

    push_to_list_tail(list, env_var);
    display_list(list, display_env_variable);
    cr_assert_stdout_eq_str("name=value\n");
    display_list(list, NULL);
    free(list->first);
    free(list);
}
