#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct node_t node_t;
typedef struct stack_t stack_t;

stack_t *stack_create();
node_t *stack_top(stack_t *stack);
void node_print(node_t *node);
void stack_print(const stack_t *stack);
int stack_push(stack_t *stack, const int value);
int stack_isempty(const stack_t *stack);
int stack_size(const stack_t *stack);
int stack_destroy(stack_t *stack);
int stack_pop(stack_t *stack);

typedef struct node_t {
    node_t *head; // pointer to head
    int value;  // integer value to hold
    node_t *tail; // pointer to tail
} node_t;

typedef struct stack_t {
    node_t *entry;
    size_t size;
} stack_t;

// create()
// Create an empty stack, returns pointer
stack_t *stack_create()
{
    stack_t *new_stack = malloc(sizeof(stack_t));

    if (!new_stack)
    {
        return NULL;
    }

    new_stack->size = 0;
    new_stack->entry = NULL;
    return new_stack;
}

// destroy()
// Destroy the stack.
int stack_destroy(stack_t *stack)
{
    if (!stack)
    {
        return 0;
    }

    while (stack->entry != NULL)
    {
        node_t *current = stack->entry;
        stack->entry = current->tail;
        printf("Freeing node with value %d\n", current->value);
        free(current);
    }

    free(stack);
    return 1;
}

// top()
// Return the top of the stack but do not remove it.
node_t *stack_top(stack_t *stack)
{
    if (!stack || stack_isempty(stack))
    {
        return NULL;
    }
    node_t *top = stack->entry;
    return top;
}


// push(x)
// Add value x to the top.
int stack_push(stack_t *stack, const int value)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
    {
        printf("Failed to alloc memory for new node.\n");
        return 0;
    }
    new_node->head = NULL;
    new_node->tail = NULL;
    new_node->value = value;

    if (!stack->entry)
    {
        stack->entry = new_node;
        stack->size++;
        return 1;
    }

    else // it means the stack entry already exists
    // here, the stack entry should point to the new node
    // the previous stack entry head should point to the new node
    {
        node_t *temp_node = stack->entry;
        new_node->tail = temp_node;
        stack->entry = new_node;
        temp_node->head = new_node;
    }
    stack->size++;
    return 1;
}

// pop()
// Remove the topmost value.
int stack_pop(stack_t *stack)
{
    if (!stack || stack_isempty(stack))
    {
        return 0;
    }
    // remove and free the top
    node_t *top = stack->entry;
    stack->entry = top->tail;
    free(top);
    stack->size--;
    // decrement the size
}

// size()
// Return the number of items in the stack.
int stack_size(const stack_t *stack)
{
    return stack->size;
}

// empty()
// Returns a Boolean to denote if the stack is empty.
int stack_isempty(const stack_t *stack)
{
    return (0 == stack->size);
}

// print()
// Prints the stack
void stack_print(const stack_t *stack)
{
    node_t *current = stack->entry;
    while (current != NULL)
    {
        node_print(current);
        current = current->tail;
    }
}

void node_print(node_t *node)
{
    if (node)
    {
        printf("Node: %d\n", node->value);
    }
    else
    {
        return;
    }
}
