#ifndef SLL_STACK_H
#define SLL_STACK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdbool.h"
#include "c_sll.h"

    typedef struct stack_extends_sll
    {

        sll_t * super; // 继承自单链表
        bool (*is_empty)(struct stack_extends_sll *stack);
        uint32_t (*size)(struct stack_extends_sll *stack);
        sll_node_t * (*top)(struct stack_extends_sll *stack);
        sll_node_t * (*push)(struct stack_extends_sll *stack, sll_node_t *node);
        void (*pop)(struct stack_extends_sll *stack);
        void (*clear)(struct stack_extends_sll *stack);

    } class_sll_stack_t;

#define new_stack (class_sll_stack_t *)malloc(sizeof(class_sll_stack_t))

    bool sll_stack_is_empty(class_sll_stack_t *stack);
    uint32_t sll_stack_size(class_sll_stack_t *stack);
    sll_node_t *sll_stack_top(class_sll_stack_t *stack);
    sll_node_t *sll_stack_push(class_sll_stack_t *stack, sll_node_t *node);
    void sll_stack_pop(class_sll_stack_t *stack);
    void sll_stack_clear(class_sll_stack_t *stack);
    class_sll_stack_t *new_sll_stack(void *msg);

#ifdef __cplusplus
}
#endif

#endif // SLL_STACK_H