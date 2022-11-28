#include "sll_stack.h"

bool sll_stack_is_empty(class_sll_stack_t *stack)
{

return(stack->super->len==0);

}

uint32_t sll_stack_size(class_sll_stack_t *stack)
{

return(stack->super->len);

}

sll_node_t * sll_stack_top(class_sll_stack_t *stack)
{

return stack->super->head;

}

sll_node_t * sll_stack_push (class_sll_stack_t *stack, sll_node_t *node)
{

    return sll_push_front(stack->super,node);

}

void sll_stack_pop(class_sll_stack_t *stack)
{

     sll_pop_front(stack->super);

}


void sll_stack_clear(class_sll_stack_t* stack)
{
   sll_clear(stack->super);
}

class_sll_stack_t * new_sll_stack(void* msg)
{
    
    class_sll_stack_t * stack =new_stack;
    stack->super=new_sll;

    stack->is_empty=sll_stack_is_empty;
    stack->size=sll_stack_size;
    stack->top=sll_stack_top;
    stack->push=sll_stack_push;
    stack->pop=sll_stack_pop;
    stack->clear=sll_stack_clear;

}


