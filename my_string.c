#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"

struct my_string {
  int size;
  int capacity;
  char* data;
};

typedef struct my_string My_string;

Boolean check_if_used(MY_STRING guess_list, char c) {
  My_string* pMy_string = (My_string*)guess_list;
  int i;
  for (i = 0; i < my_string_get_size(guess_list); i++) {
    if (pMy_string->data[i] == c) {
      printf("You have already guessed that letter try again.\n");
      return TRUE;
    }
  }
  return FALSE;
}

MY_STRING my_string_init_default(void) {
  My_string* pString;
  pString = (My_string*)malloc(sizeof(My_string));
  if (pString != NULL) {
    pString->size = 0;
    pString->capacity = 7;
    pString->data = (char*)malloc(sizeof(char) * pString->capacity);
  } else {
    free(pString);
    pString = NULL;
  }
  return (MY_STRING)pString;
}

void my_string_destroy(Item* pItem) {
  My_string* pMy_string = (My_string*)*pItem;
  free(pMy_string->data);
  free(pMy_string);
  *pItem = NULL;
  return;
}

MY_STRING my_string_init_c_string(const char* c_string) {
  int i = 0;
  int capacity = 0;
  int size = 0;
  char c = 'd';

  for (i = 0; c != '\0'; i++) {
    c = c_string[i];
  }
  size = i - 1;
  capacity = size;

  My_string* pString;
  pString = (My_string*)malloc(sizeof(My_string));
  if (pString != NULL) {
    pString->size = size;
    pString->capacity = capacity;
    pString->data = (char*)malloc(sizeof(char) * pString->capacity);
  } else {
    free(pString);
    pString = NULL;
  }

  for (i = 0; i < capacity; i++) {
    pString->data[i] = c_string[i];
  }

  return (MY_STRING)pString;
}

int my_string_get_capacity(MY_STRING hMy_string) {
  My_string* pString = (My_string*)hMy_string;
  return pString->capacity;
}

int my_string_get_size(MY_STRING hMy_string) {
  My_string* pString = (My_string*)hMy_string;
  return pString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
  My_string *pLeft_string = (My_string *)hLeft_string;
  My_string *pRight_string = (My_string *)hRight_string;
  int i;
  for (i = 0; i < pLeft_string->size && i < pRight_string->size; i++) {
    if (pLeft_string->data[i] < pRight_string->data[i]) {
      return -1;
    } else if (pLeft_string->data[i] > pRight_string->data[i]) {
      return 1;
    }
  }
  return 0;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
  My_string* pString = (My_string*)hMy_string;
  char c = 'd';
  int i = 0;
  c = fgetc(fp);
  while (isspace(c)) {
    c = fgetc(fp);
    if (c == EOF) {
      return FAILURE;
    }
  }
  pString->size = 0;
  for (i = 0; !isspace(c); i++) {
    if (pString->capacity > i + 1) {
      pString->data[i] = c;
      pString->size = i + 1;
    } else {
      pString->data = (char*)realloc(pString->data, pString->capacity * 2);
      if (pString->data == NULL) {
	return FAILURE;
      }
      pString->capacity *= 2;
      pString->data[i] = c;
      pString->size = i + 1;
    }
    c = fgetc(fp);
    if (c == EOF) {
      return FAILURE;
    }
  }
  ungetc(c, fp);
  return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {
  My_string* pString = (My_string*)hMy_string;
  char c = 'd';
  int i = 0;
  if (pString == NULL) {
    return FAILURE;
  } else {
    for (i = 0; i < pString->size; i++) {
      c = pString->data[i];
      fprintf(fp, "%c", c);
    }
    return SUCCESS;
  }
}

Status my_string_push_back(MY_STRING hMy_string, char item) {
  My_string* pString = (My_string*)hMy_string;
  if (pString->capacity > pString->size + 1) {
    pString->data[pString->size] = item;
    pString->size = pString->size + 1;
  } else {
    pString->data = (char*)realloc(pString->data, pString->capacity * 2);
    if (pString->data == NULL) {
      return FAILURE;
    } else {
      pString->capacity *= 2;
      pString->data[pString->size] = item;
      pString->size = pString->size + 1;
    }
  }
  return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string) {
  My_string* pString = (My_string*)hMy_string;
  if (pString->size > 0) {
    pString->size = pString->size - 1;
    return SUCCESS;
  } else {
    return FAILURE;
  }
}

char* my_string_at(MY_STRING hMy_string, int index) {
  My_string* pString = (My_string*)hMy_string;
  if (index < pString->size && index >= 0) {
    return (char*)&pString->data[index];
  } else {
    return NULL;
  }
}

char* my_string_c_str(MY_STRING hMy_string) {
  My_string* pString = (My_string*)hMy_string;
  my_string_push_back(hMy_string, '\0');
  pString->size = pString->size - 1;
  return (char*)&(pString->data[0]);
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {
  My_string* pResult = (My_string*)hResult;
  My_string* pAppend = (My_string*)hAppend;
  int needed_size = (int)pResult->size + (int)pAppend->size;
  int i = 0;
  int continued_i = 0;
  char* c = NULL;
  char* pTemp = NULL;

  pTemp = (char*)malloc(sizeof(char) * needed_size);
  if (pTemp == NULL) {
    return FAILURE;
  }

  c = my_string_c_str(hResult);
  for (i = 0; i < pResult->size; i++) {
    pTemp[i] = *(c + i);
  }

  continued_i = i;

  c = my_string_c_str(hAppend);
  for (i = 0; i < pAppend->size; i++) {
    pTemp[continued_i] = *(c + i);
    continued_i++;
  }

  free(pResult->data);
  pResult->data = pTemp;
  pResult->size = needed_size;
  pResult->capacity = needed_size;

  return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string) {
  My_string* pString = (My_string*)hMy_string;
  if (pString->size <= 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}

void my_string_assignment(Item* pLeft, Item Right) {
  My_string* pLeft_string = (My_string*)*pLeft;
  My_string* pRight_string = (My_string*)Right;
  int i;
  char* temp;
  temp = my_string_c_str((MY_STRING)Right);
  if (pLeft_string == NULL) {
    pLeft_string = my_string_init_c_string(temp);
  } else {
    pLeft_string->size = 0;
    for (i = 0; i < pRight_string->size + 1; i++) {
      my_string_push_back(pLeft_string, pRight_string->data[i]);
    }
  }
  *pLeft = pLeft_string;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess) {
  int i;
  while (!my_string_empty(new_key))
    my_string_pop_back(new_key);
  for (i = 0; i < my_string_get_size(word); i++)
    if (!my_string_push_back(new_key, *my_string_at(word, i) == guess ? guess : *my_string_at(current_word_family, i)))
      return FAILURE;
  return SUCCESS;
}
