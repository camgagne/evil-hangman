#include <stdio.h>
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_default();
  if(hString == NULL)
    {
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
	      "my_string_init_default returns NULL", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
      return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_get_size(hString) != 0)
    {
      status = FAILURE;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	      "Did not receive 0 from get_size after init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	      , length);
    }
  my_string_destroy(&hString);
  return status;
}

Status non_null_terminated_gets_null_terminated(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();

  my_string_push_back(hString, 'C');
  my_string_push_back(hString, 'A');
  my_string_push_back(hString, 'M');

  if(my_string_c_str(hString)[my_string_get_size(hString)] == '\0')
    {
      status = SUCCESS;
      strncpy(buffer,  "non_null_terminated_gets_null_terminated\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String did not get NULL terminated.\n");
      strncpy(buffer, "non_null_terminated_gets_null_terminated\n"
	      "String did not get NULL terminated.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_init_c_string_set_size(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("Cameron");

  if(my_string_get_size(hString) == 7)
    {
      status = SUCCESS;
      strncpy(buffer,  "non_null_terminated_gets_null_terminated\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String not set to correct size.\n");
      strncpy(buffer, "test_init_c_string_set_size\n"
	      "String did not get set to correct size.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_init_default_correct_size_capacity(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_get_capacity(hString) == 7 && my_string_get_size(hString) == 0)
    {
      status = SUCCESS;
      strncpy(buffer,  "test_init_default_correct_size_capacity\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Size or capacity not set to correct sizes\n");
      strncpy(buffer, "test_init_c_string_set_size\n"
	      "Size or capacity not set to correct sizes\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_init_c_string_correct_size_capacity(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("Cameron");
  if(my_string_get_capacity(hString) == 8  && my_string_get_size(hString) == 7)
    {
      status = SUCCESS;
      strncpy(buffer, "test_init_c_string_correct_size_capacity\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Size or capacity not set to correct sizes\n");
      strncpy(buffer, "test_init_c_string_correct_size_capacity\n"
	      "Size or capacity not set to correct sizes\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_destory_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  my_string_destroy(&hString);
  if(hString == NULL)
    {
      status = SUCCESS;
      strncpy(buffer, "test_destory_string\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String not successfully destoryed\n");
      strncpy(buffer, "test_destory_string\n"
	      "String not successfully destoryed\n", length);
    }
  return status;
}

Status test_get_size(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();

  my_string_push_back(hString, 'C');
  my_string_push_back(hString, 'A');
  my_string_push_back(hString, 'M');
  if(my_string_get_size(hString) == 3)
    {
      status = SUCCESS;
      strncpy(buffer, "test_get_size\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Size not setcorrect\n");
      strncpy(buffer, "test_get_size\n"
	      "Size not set correct\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_get_capacity(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();

  my_string_push_back(hString, 'C');
  my_string_push_back(hString, 'A');
  my_string_push_back(hString, 'M');
  my_string_push_back(hString, 'E');
  my_string_push_back(hString, 'R');
  my_string_push_back(hString, 'O');
  my_string_push_back(hString, 'N');
  my_string_push_back(hString, 'G');

  if(my_string_get_capacity(hString) == 14)
    {
      status = SUCCESS;
      strncpy(buffer, "test_get_capacity\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Capacity not set correct\n");
      strncpy(buffer, "test_get_capacity\n"
	      "Capacity not set correct\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_two_string_compare(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;
  hString1 = my_string_init_c_string("Cameron");
  hString2 = my_string_init_c_string("Gagne");
  if(my_string_compare(hString1, hString2) == 2)
    {
      status = SUCCESS;
      strncpy(buffer, "test_two_string_compare\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String compare is incorrect\n");
      strncpy(buffer, "test_two_string_compare\n"
	      "String compare is incorrect\n", length);
    }
  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  return status;
}

Status test_my_string_extraction_file_with_data(char* buffer, int length)
{
  Status status;
  MY_STRING hMy_string = NULL;
  FILE* fp;
  hMy_string = my_string_init_default();
  fp = fopen("simple.txt", "r");
  
  if(my_string_extraction(hMy_string, fp))
    {
      status = SUCCESS;
      strncpy(buffer, "test_my_string_extraction_file_with_data\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String extraction failed with file with data\n");
      strncpy(buffer, "test_my_string_extraction_file_with_data\n"
	      "String extraction failed with file with data\n", length);
    }
  
  my_string_destroy(&hMy_string);
  fclose(fp);
  return status;
}

Status test_my_string_extraction_file_with_no_data(char* buffer, int length)
{
  Status status;
  MY_STRING hMy_string = NULL;
  FILE* fp;
  hMy_string = my_string_init_default();
  fp = fopen("empty.txt", "r");
  
  if(!(my_string_extraction(hMy_string, fp)))
    {
      status = SUCCESS;
      strncpy(buffer, "test_my_string_extraction_file_with_no_data\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String extraction failed with file with no data\n");
      strncpy(buffer, "test_my_string_extraction_file_with_no_data\n"
	      "String extraction failed with file with no data\n", length);
    }
  my_string_destroy(&hMy_string);
  fclose(fp);
  return status;
}

Status test_my_string_insertion(char* buffer, int length)
{
  Status status;
  MY_STRING hMy_string = NULL;
  FILE* fp;
  hMy_string = my_string_init_default();
  fp = fopen("simple.txt", "r");
  

  my_string_extraction(hMy_string, fp);

  if(my_string_insertion(hMy_string, stdout))
    {
      printf("\n");
      status = SUCCESS;
      strncpy(buffer, "test_my_string_insertion\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String insertion failed with file\n");
      strncpy(buffer, "test_my_string_insertion\n"
	      "String intsertion failed with file\n", length);
    }
  my_string_destroy(&hMy_string);
  fclose(fp);
  return status;
}

Status test_my_string_push_back(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();

  my_string_push_back(hString, 'C');

  if(my_string_get_size(hString) == 1)
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_push_back\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Push back failed size not corrected.\n");
      strncpy(buffer, "test_my_string_push_back\n"
	      "Push back failed size not corrected.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_my_string_pop_back(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("Cameron");

  my_string_pop_back(hString);

  if(my_string_get_size(hString) == 6)
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_pop_back\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Pop back failed size not corrected.\n");
      strncpy(buffer, "test_my_string_pop_back\n"
	      "Pop back failed size not corrected.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}


Status test_my_string_at(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("Cameron");

  if(*my_string_at(hString, 3) == 'e')
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_at\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Wrong index returned.\n");
      strncpy(buffer, "test_my_string_at\n"
	      "Wrong index returned.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_my_string_c_str(char* buffer, int length){
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  my_string_push_back(hString, 'C');
  my_string_push_back(hString, 'A');
  my_string_push_back(hString, 'M');
  my_string_push_back(hString, 'E');
  my_string_push_back(hString, 'R');
  my_string_push_back(hString, 'O');
  my_string_push_back(hString, 'N');
  my_string_push_back(hString, 'G');
 
  if(!strcmp(my_string_c_str(hString), "CAMERONG"))
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_c_str\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String is not getting NULL terminated.\n");
      strncpy(buffer, "test_my_string_c_str\n"
	      "String is not getting NULL terminated.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_my_string_concat(char* buffer, int length){
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;

  hString1 = my_string_init_default();
  my_string_push_back(hString1, 'C');
  my_string_push_back(hString1, 'A');
  my_string_push_back(hString1, 'M');

  hString2 = my_string_init_c_string("GAGNE");

  my_string_concat(hString1, hString2);

  if(my_string_get_size(hString1) == 8  && my_string_get_capacity(hString1) == 9)
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_concat\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String is not concat correctly.\n");
      strncpy(buffer, "test_my_string_concat\n"
	      "String is not getting concat correctly\n", length);
    }
  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  return status;
}


Status test_my_string_empty_non_empty_size(char* buffer, int length){
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  my_string_push_back(hString, 'C');
  my_string_push_back(hString, 'A');
  my_string_push_back(hString, 'M');
 
  if(!my_string_empty(hString))
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_empty_non_empty_size\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String is empty but has characters in it.\n");
      strncpy(buffer, "test_my_string_empty_non_empty_size\n"
	      "String is empty but has characters in it.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_my_string_empty_will_empty_size(char* buffer, int length){
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
 
  if(my_string_empty(hString))
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_empty_will_empty_size\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String is not empty but has nothing in it.\n");
      strncpy(buffer, "test_my_string_empty_will_empty_size\n"
	      "String is not empty but has nothing in it.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}


Status test_my_string_init_with_NULL_pointer(char* buffer, int length){
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string(NULL);
 
  if(my_string_empty(hString))
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_empty_will_empty_size\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String is not empty but has nothing in it.\n");
      strncpy(buffer, "test_my_string_empty_will_empty_size\n"
	      "String is not empty but has nothing in it.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}


Status test_my_string_concat_with_large_strings(char* buffer, int length){
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;

  hString1 = my_string_init_default();
  my_string_push_back(hString1, 'C');
  my_string_push_back(hString1, 'A');
  my_string_push_back(hString1, 'M');
  my_string_push_back(hString1, 'E');
  my_string_push_back(hString1, 'R');
  my_string_push_back(hString1, 'O');
  my_string_push_back(hString1, 'N');
  my_string_push_back(hString1, 'C');
  my_string_push_back(hString1, 'A');
  my_string_push_back(hString1, 'M');
  my_string_push_back(hString1, 'E');
  my_string_push_back(hString1, 'R');
  my_string_push_back(hString1, 'O');
  my_string_push_back(hString1, 'N');

  hString2 = my_string_init_c_string("GAGNEGAGNEGAGNEGAGNE");

  my_string_concat(hString1, hString2);

  if(my_string_get_size(hString1) == 34  && my_string_get_capacity(hString1) == 35)
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_concat_with_large_strings\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String is not concat large strings correctly.\n");
      strncpy(buffer, "test_my_string_concat_with_large_strings\n"
	      "String is not concat large strings correctly\n", length);
    }
  my_string_destroy(&hString1);
  my_string_destroy(&hString2);
  return status;
}

Status test_destory_string_with_NULL_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
 
  my_string_destroy(&hString);
  if(hString == NULL)
    {
      status = SUCCESS;
      strncpy(buffer, "test_destory_string_with_NULL_string\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("String not successfully destoryed\n");
      strncpy(buffer, "test_destory_string_with_NULL_string\n"
	      "String not successfully destoryed\n", length);
    }
  return status;
}

Status test_my_string_push_back_with_NULL_pointer(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  my_string_push_back(hString, 'C');
  my_string_push_back(hString, 'A');
  my_string_push_back(hString, 'M');
  my_string_push_back(hString, '\0');
  
  if(my_string_get_size(hString) == 3)
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_push_back_with_NULL_terminater(\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Push back failed trying to push NULL terminater on string.\n");
      strncpy(buffer, "test_my_string_push_back_with_NULL_terminater(\n"
	      "Push back failed trying to push NULL terminater on string.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_my_string_at_invaild_index(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("Cameron");

  if(my_string_at(hString, -1) == NULL)
    {
      status = SUCCESS;
      strncpy(buffer,  "test_my_string_at_invaild_index\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("Wrong index returned.\n");
      strncpy(buffer, "test_my_string_at_invaild_index\n"
	      "Wrong index returned.\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_get_word_key_value(char* buffer, int length)
{
  Status status;
  MY_STRING hOld_key = my_string_init_c_string("--ppy");
  MY_STRING hNew_key = my_string_init_c_string("-----");
  MY_STRING hWord = my_string_init_c_string("happy");

  get_word_key_value(hOld_key, hNew_key, hWord, 'h');
  
  if(strcmp(my_string_c_str(hNew_key), "h-ppy") == 0)
    {
      status = SUCCESS;
      strncpy(buffer,  "test_get_word_key_value\n"
	      , length);
    }
  else
    {
      status = FAILURE;
      printf("New key not changed correctly.\n");
      strncpy(buffer, "test_get_word_key_value\n"
	      "New key not changed correctly.\n", length);
    }
  my_string_destroy(&hOld_key);
  my_string_destroy(&hNew_key);
  my_string_destroy(&hWord);
  return status;
}
