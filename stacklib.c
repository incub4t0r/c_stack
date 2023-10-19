#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct node_t node_t;
typedef struct stack_t stack_t;

stack_t *stack_create();
node_t *stack_top(stack_t *stack);
void stack_print(const stack_t *stack);
void node_print(node_t *node);
int stack_push(stack_t *stack, const int value);
int stack_isempty(const stack_t *stack);
int stack_size(const stack_t *stack);
int stack_destroy(stack_t *stack);
int stack_pop(stack_t *stack);

typedef struct node_t {
    node_t *head;
    int value;
    node_t *tail;
} node_t;

typedef struct stack_t {
    node_t *entry;
    size_t size;
} stack_t;

/**
 * @brief Allocs a new stack
 *
 * @return stack_t* If successful, returns the stack pointer, else NULL
 */
stack_t *stack_create(void)
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

/**
 * @brief Destroys a stack
 *
 * @param stack A pointer to the stack
 * @return int If successful, returns 1, else 0
 */
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

/**
 * @brief Gets the top of the stack without removing it
 *
 * @param stack A pointer to the stack
 * @return node_t* If successful, returns a node, else NULL
 */
node_t *stack_top(stack_t *stack)
{
    if (!stack || stack_isempty(stack))
    {
        return NULL;
    }
    node_t *top = stack->entry;
    return top;
}

/**
 * @brief Pushes a new value onto the stack
 *
 * @param stack A pointer to the stack
 * @param value An int to push to the stack
 * @return int If successful, returns 1, else 0
 */
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

    else
    {
        node_t *temp_node = stack->entry;
        new_node->tail = temp_node;
        stack->entry = new_node;
        temp_node->head = new_node;
    }
    stack->size++;
    return 1;
}

/**
 * @brief Pops the top of the stack
 *
 * @param stack A pointer to the stack
 * @return int If successful, returns 1, else 0
 */
int stack_pop(stack_t *stack)
{
    if (!stack || stack_isempty(stack))
    {
        return 0;
    }
    node_t *top = stack->entry;
    stack->entry = top->tail;
    free(top);
    stack->size--;
    return 1;
}

/**
 * @brief Get the size of the stack
 *
 * @param stack A pointer to the stack
 * @return int An int representing the size of the stack
 */
int stack_size(const stack_t *stack)
{
    return stack->size;
}

/**
 * @brief Check if a stack is empty
 *
 * @param stack A pointer to the stack
 * @return int If empty, returns 1, else 0
 */
int stack_isempty(const stack_t *stack)
{
    return (0 == stack->size);
}

/**
 * @brief Prints the stack
 *
 * @param stack A pointer to the stack
 */
void stack_print(const stack_t *stack)
{
    node_t *current = stack->entry;
    while (current != NULL)
    {
        node_print(current);
        current = current->tail;
    }
}

/**
 * @brief Prints a node
 *
 * @param node A pointer to the node
 */
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
