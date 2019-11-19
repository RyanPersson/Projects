#include <stdlib.h>
#include <assert.h>

#include "list.h"


struct link {
  void* val;
  struct link* next;
};


struct list {
  struct link* head;
};


struct list* list_create() {
  struct list* list = malloc(sizeof(struct list));
  list->head = NULL;
  return list;
}


void list_free(struct list* list) {
  assert(list);


  struct link* next, * curr = list->head;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  free(list);
}


void list_insert(struct list* list, void* val) {
  assert(list);


  struct link* link = malloc(sizeof(struct link));
  link->val = val;
  link->next = list->head;
  list->head = link;
}


void list_remove(struct list* list, void* val, int (*cmp)(void* a, void* b)) {
  assert(list);

  struct link* prev = NULL, * curr = list->head;
  while (curr) {

    if (cmp(val, curr->val) == 0) {
      if (prev) {
        prev->next = curr->next;
      } else {
        list->head = curr->next;
      }
      free(curr);
      return;
    }

    prev = curr;
    curr = curr->next;
  }
}


int list_position(struct list* list, void* val, int (*cmp)(void* a, void* b)) {
  assert(list);

  struct link* curr = list->head;
  int i = 0;
  while (curr) {
  
    if (cmp(val, curr->val) == 0) {
      return i;
    }

    curr = curr->next;
    i++;
  }


  return -1;
}


void list_reverse(struct list* list) {
  assert(list);


  struct link* next, * curr = list->head, * prev = NULL;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    list->head = prev = curr;
    curr = next;
  }
}

void* list_top(struct list* list) {
	assert(list);
	return list->head->val;
}

void* list_pop(struct list* list) {
	assert(list);
	struct link* curr = list->head;
	void* val = curr->val;
	list->head = list->head->next;
	free(curr);
	return val;
}

int list_isempty(struct list* list) {
	assert(list);
	if(list->head == NULL)
		return 1;
	return 0;
}
