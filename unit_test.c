#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
  Status (*tests[])(char*, int) =
    {
      test_init_default_returns_nonNULL,
      test_get_size_on_init_default_returns_0,
      non_null_terminated_gets_null_terminated,
      test_init_c_string_set_size,
      test_init_default_correct_size_capacity,
      test_init_c_string_correct_size_capacity,
      test_destory_string,
      test_get_size,
      test_get_capacity,
      test_two_string_compare,
      test_my_string_extraction_file_with_data,
      test_my_string_extraction_file_with_no_data,
      test_my_string_insertion,
      test_my_string_push_back,
      test_my_string_pop_back,
      test_my_string_at,
      test_my_string_c_str,
      test_my_string_concat,
      test_my_string_empty_non_empty_size,
      test_my_string_empty_will_empty_size,
      test_my_string_init_with_NULL_pointer,
      test_my_string_concat_with_large_strings,
      test_destory_string_with_NULL_string,
      test_my_string_push_back_with_NULL_pointer,
      test_my_string_at_invaild_index,
      test_get_word_key_value
    };
 
  int number_of_functions = sizeof(tests) / sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;
 
  for(i=0; i<number_of_functions; i++)
    {
      if(tests[i](buffer, 500) == FAILURE)
	{
	  printf("FAILED: Test %d failed miserably\n", i);
	  printf("\t%s\n", buffer);
	  failure_count++;
	}
      else
	{
	  // printf("PASS: Test %d passed\n", i);
	  // printf("\t%s\n", buffer);
	  success_count++;
	}
    }
 
  printf("Total number of tests: %d\n", number_of_functions);
  printf("%d/%d Pass, %d/%d Failure\n", success_count,
	 number_of_functions, failure_count, number_of_functions);
  return 0;
}
