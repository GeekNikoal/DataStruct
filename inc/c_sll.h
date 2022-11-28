#ifndef C_SLL_H
#define C_SLL_H

#ifdef  __cplusplus
extern "C" {
#endif

    #include "stdbool.h"
    #include "stdio.h"
    #include "stdlib.h"
    #include "stdint.h"
    #include "assert.h"

    
    //单链表结点
    typedef struct sll_node
    {
        void *data;//数据域
        uint32_t data_size;//结点数据域占用大小
       struct sll_node *next;//后继结点
    } sll_node_t;
    
    //单链表
    typedef struct single_linked_list
    {
        sll_node_t *head;//头结点
        sll_node_t *tail;//尾结点   
        uint32_t len;// 链表长度
        void *msg;// 链表信息可以自定义其他数据，例如指向char* 保存链表名称等

    } sll_t;




//单链表结点
#define new_sll_node (sll_node_t *) malloc(sizeof(sll_node_t))
#define new_sll (sll_t *) malloc(sizeof(sll_t))
#define is_sll_empty(sll) (sll)->len==0
#define del_sll_node(sll_node) free(sll_node);

sll_t *sll_create(void *msg);

sll_node_t *sll_new_node(void *data, uint32_t data_size);
sll_node_t *sll_get_node_by_pos(sll_t *sll, uint32_t pos);
sll_node_t *sll_insert_by_pos(sll_t *sll, sll_node_t *node_insert, uint32_t pos);

void sll_erase_by_pos(sll_t *sll, uint32_t pos);
void sll_erase_by_range(sll_t *sll, uint32_t sta,uint32_t end);
void sll_clear(sll_t *sll);

void sll_pop_front(sll_t *sll);
void sll_pop_back(sll_t *sll);

sll_node_t * sll_push_front(sll_t *sll, sll_node_t *node_insert);
sll_node_t * sll_push_back(sll_t *sll, sll_node_t *node_insert);

#define sll_forech(sll,sll_node) for(sll_node=sll->head;sll_node!=NULL;sll_node=sll_node->next) 

#ifdef  __cplusplus
}
#endif

#endif // C_SLL_H