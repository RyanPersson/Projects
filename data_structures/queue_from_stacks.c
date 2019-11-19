

#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "queue_from_stacks.h"


struct queue_from_stacks
{
  struct stack *s1;
  struct stack *s2;
};


struct queue_from_stacks *queue_from_stacks_create()
{
  struct queue_from_stacks *qfs = malloc(sizeof(struct queue_from_stacks));
  qfs->s1 = stack_create();
  qfs->s2 = stack_create();
  return qfs;
}


void queue_from_stacks_free(struct queue_from_stacks *qfs)
{
  stack_free(qfs->s1);
  stack_free(qfs->s2);
  free(qfs);
  return;
}

int queue_from_stacks_isempty(struct queue_from_stacks *qfs)
{
  assert(qfs);
  if (stack_isempty(qfs->s1) == 1 && stack_isempty(qfs->s2) == 1)
    return 1;
  return 0;
}


void queue_from_stacks_enqueue(struct queue_from_stacks *qfs, void *val)
{
  assert(qfs);
  stack_push(qfs->s1, val);
  return;
}


void *queue_from_stacks_front(struct queue_from_stacks *qfs)
{
  assert(qfs);
  if (stack_isempty(qfs->s2))
  {
    while (!stack_isempty(qfs->s1))
    {
      void *val = stack_pop(qfs->s1);
      stack_push(qfs->s2, val);
    }
  }
  return stack_top(qfs->s2);
}


void *queue_from_stacks_dequeue(struct queue_from_stacks *qfs)
{
  assert(qfs);
  if (stack_isempty(qfs->s2))
  {
    while (!stack_isempty(qfs->s1))
    {
      void *val = stack_pop(qfs->s1);
      stack_push(qfs->s2, val);
    }
  }
  return stack_pop(qfs->s2);
}
