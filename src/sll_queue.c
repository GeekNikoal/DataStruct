#include "sll_queue.h"



bool sll_queue_is_empty(class_sll_queue_t *queue)
{

return(queue->super->len==0);

}

uint32_t sll_queue_size(class_sll_queue_t *queue)
{

return(queue->super->len);

}

sll_node_t * sll_queue_front(class_sll_queue_t *queue)
{

return queue->super->head;

}

sll_node_t * sll_queue_back(class_sll_queue_t *queue)
{

return queue->super->tail;

}



sll_node_t * sll_queue_push (class_sll_queue_t *queue, sll_node_t *node)
{

    return sll_push_front(queue->super,node);

}

void sll_queue_pop(class_sll_queue_t *queue)
{

     sll_pop_back(queue->super);

}


void sll_queue_clear(class_sll_queue_t* queue)
{
   sll_clear(queue->super);
}

class_sll_queue_t * new_sll_queue(void* msg)
{
    
    class_sll_queue_t * queue =new_queue;
    queue->super=new_sll;

    queue->is_empty=sll_queue_is_empty;
    queue->size=sll_queue_size;

    queue->front=sll_queue_front;
    queue->back=sll_queue_back;

    queue->push=sll_queue_push;
    queue->pop=sll_queue_pop;
    queue->clear=sll_queue_clear;

}