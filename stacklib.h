#ifndef STACKLIB_H
#define STACKLIB_H

typedef struct node_t_ node_t;
typedef struct stack_t_ stack_t;

stack_t *stack_create();
node_t *stack_top(stack_t *stack);
void node_print(node_t *node);
void stack_print(const stack_t *stack);
int stack_push(stack_t *stack, const int value);
int stack_isempty(const stack_t *stack);
int stack_size(const stack_t *stack);
int stack_destroy(stack_t *stack);
int stack_pop(stack_t *stack);

#endif // STACKLIB_H