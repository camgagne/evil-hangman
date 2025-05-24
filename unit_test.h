#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status non_null_terminated_gets_null_terminated(char* buffer, int length);
Status test_init_c_string_set_size(char* buffer, int length);
Status test_init_default_correct_size_capacity(char* buffer, int length);
Status test_init_c_string_correct_size_capacity(char* buffer, int length);
Status test_destory_string(char* buffer, int length);
Status test_get_size(char* buffer, int length);
Status test_get_capacity(char* buffer, int length);
Status test_two_string_compare(char* buffer, int length);
Status test_my_string_extraction_file_with_data(char* buffer, int length);
Status test_my_string_extraction_file_with_no_data(char* buffer, int length);
Status test_my_string_insertion(char* buffer, int length);
Status test_my_string_push_back(char* buffer, int length);
Status test_my_string_pop_back(char* buffer, int length);
Status test_my_string_at(char* buffer, int length);
Status test_my_string_c_str(char* buffer, int length);
Status test_my_string_concat(char* buffer, int length);
Status test_my_string_empty_non_empty_size(char* buffer, int length);
Status test_my_string_empty_will_empty_size(char* buffer, int length);
Status test_my_string_init_with_NULL_pointer(char* buffer, int length);
Status test_my_string_concat_with_large_strings(char* buffer, int length);
Status test_destory_string_with_NULL_string(char* buffer, int length);
Status test_my_string_push_back_with_NULL_pointer(char* buffer, int length);
Status test_my_string_at_invaild_index(char* buffer, int length);
Status test_get_word_key_value(char* buffer, int length);

#endif
