#include <stdio.h>
#include <stdlib.h>
#include "stacklib.h"

int main(void)
{
    // test code functionality
    stack_t *stack = stack_create();
    if (!stack)
    {
        printf("Could not create stack\n");
        return 0;
    }
    printf("Created stack!\n");
    for (int idx = 0; idx < 20; idx++)
    {
        if (!stack_push(stack, idx))
        {
            printf("Failed to push %d\n", idx);
            exit(EXIT_FAILURE);
        }
    }
    stack_print(stack);
    node_t *top = NULL;
    top = stack_top(stack);
    node_print(top);
    for (int idx = 0; idx < 5; idx++)
    {
        if (!stack_pop(stack))
        {
            printf("Failed to pop\n");
            exit(EXIT_FAILURE);
        }
    }
    top = stack_top(stack);
    node_print(top);
    // printf("Top of stack: %d\n", top->value);
    if (!stack_destroy(stack))
    {
        printf("Failed to destroy stack\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
