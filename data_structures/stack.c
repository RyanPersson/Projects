#include <stdlib.h>

#include <assert.h>
#include "stack.h"
#include "list.h"



struct stack {
  struct list* list;
};


struct stack* stack_create() {
	struct stack* stack = malloc(sizeof(struct stack));
	stack->list = list_create();
	return stack;
}


void stack_free(struct stack* stack) {
	assert(stack);
	list_free(stack->list);
	free(stack);
  	return;
}


int stack_isempty(struct stack* stack) {
	assert(stack);
	return list_isempty(stack->list);
}


void stack_push(struct stack* stack, void* val) {
	assert(stack);
	list_insert(stack->list, val);
       	return;
}


void* stack_top(struct stack* stack) {
	assert(stack);
	return list_top(stack->list);
}


void* stack_pop(struct stack* stack) {
	assert(stack);
  	return list_pop(stack->list);
}
