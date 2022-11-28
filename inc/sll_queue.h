#ifndef SLL_QUEUE_H
#define SLL_QUEUE_H

#ifdef  __cplusplus
extern "C" {
#endif

    #include "c_sll.h"

    typedef struct queue_extends_sll
    {
        sll_t* super;//继承自单链表
        bool (*is_empty)(struct queue_extends_sll *queue);
        uint32_t (*size)(struct queue_extends_sll*queue);
        sll_node_t * (*front)(struct queue_extends_sll *queue);
        sll_node_t * (*back)(struct queue_extends_sll *queue);
        sll_node_t * (*push)(struct queue_extends_sll *queue, struct queue_extends_sll *node);
        void (*pop)(struct queue_extends_sll *queue);
        void (*clear)(struct queue_extends_sll *queue);
        
    }class_sll_queue_t;



#define new_queue (class_sll_queue_t *) malloc(sizeof(class_sll_queue_t))
bool sll_queue_is_empty(class_sll_queue_t *queue);

uint32_t sll_queue_size(class_sll_queue_t *queue);
sll_node_t * sll_queue_front(class_sll_queue_t *queue);
sll_node_t * sll_queue_back(class_sll_queue_t *queue);
sll_node_t * sll_queue_push (class_sll_queue_t *queue, sll_node_t *node);
void sll_queue_pop(class_sll_queue_t *queue);
void sll_queue_clear(class_sll_queue_t* queue);

class_sll_queue_t * new_sll_queue(void* msg);








#ifdef  __cplusplus
}
#endif

#endif // SLL_QUEUE_H