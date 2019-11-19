#include <stdlib.h>
#include <assert.h>

#include "dynarray.h"

struct dynarray {
  void** data;
  int size;
  int capacity;
  int start;
};

#define DYNARRAY_INIT_CAPACITY 4

struct dynarray* dynarray_create() {
  struct dynarray* da = malloc(sizeof(struct dynarray));
  assert(da);

  da->data = malloc(DYNARRAY_INIT_CAPACITY * sizeof(void*));
  assert(da->data);
  da->size = 0;
  da->start = 0;
  da->capacity = DYNARRAY_INIT_CAPACITY;

  return da;
}

/*frees the memory in a dynarry*/
void dynarray_free(struct dynarray* da) {
  assert(da);
  free(da->data);
  free(da);
}

/*returns the size of a dynarray*/
int dynarray_size(struct dynarray* da) {
  assert(da);
  return da->size;
}

/*resizes a dynarray*/
void _dynarray_resize(struct dynarray* da, int new_capacity) {
  assert(new_capacity > da->size);

  /*
   * Allocate space for the new array.
   */
  void** new_data = malloc(new_capacity * sizeof(void*));
  assert(new_data);

  /*
   * Copy data from the old array to the new one.
   */
  for (int i = 0; i < da->size; i++) {
    new_data[i] = da->data[(i + da->start) % da->capacity];
  }

  /*
   * Put the new array into the dynarray struct.
   */
  free(da->data);
  da->data = new_data;
  da->capacity = new_capacity;
  da->start = 0;
}

/*inserts a new function into a dynarray*/
void dynarray_insert(struct dynarray* da, void* val) {
  assert(da);


  if (da->size == da->capacity) {
    _dynarray_resize(da, 2 * da->capacity);
  }


  da->data[(da->size + da->start) % da->capacity] = val;
  da->size++;
}

/*removes an element from a dynarray */
void dynarray_remove(struct dynarray* da) {
  assert(da);

  /*Overwriiten to work with queue. Only possible value of idx should be zero.*/
  da->start++;
  da->size--;
}

/*returns the first element in the dynarray*/
void* dynarray_get(struct dynarray* da) {
  assert(da);

  return da->data[da->start];
}

/*sets an element in the dynarray*/
void dynarray_set(struct dynarray* da, int idx, void* val) {
  assert(da);
  assert(idx < da->size && idx >= 0);

  da->data[idx] = val;
}