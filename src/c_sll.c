#include "c_sll.h"

/**
 * @brief 简介:创建一个空白单链表
 * @param 形参: msg 保留的链表的信息指针，可以为NULL，可指向任意数据取数据。
 * @retval 返回值:sll 单链表指针(对象)
 * @note  注意!!!:msg的类型为 void*指针(泛型)信息指针，可指向任意数据取数据，但是取数据则需自行强转为正确的类型。
 * @author 作者/修改者:冼文基
 * @date 日期:2022-11-27 12:21:56
 **/
sll_t *sll_create(void *msg)
{
    sll_t *sll = new_sll;
    assert(sll);
    sll->head = sll->tail = sll->len = NULL;
    sll->msg = msg;
    return sll;
}

/**
 * @brief 简介:创建一个单链表结点
 * @param 形参: data 任意数据指针
 * @param 形参: data_size 指向数据的大小，单位为字节，需使用sizeof获取
 * @retval 返回值:单链表结点
 * @note  注意!!!:任意类型数据的地址赋值给void*会自动强转，而void*数据无法直接取值，需要强转为对应类型数据再取值
 * @author 作者/修改者:冼文基
 * @date 日期:2022-11-27 12:39:29
 **/
sll_node_t *sll_new_node(void *data, uint32_t data_size)
{
    sll_node_t *node = new_sll_node;
    assert(node);
    node->data = data;
    node->data_size = data_size;
    node->next = NULL;
    return node;
}

/**
 * @brief 简介:根据链表位置获取结点
 * @param 形参:pos 链表位置
 * @retval 返回值:获取到的结点，NULL则为没有找到
 * @note  注意!!!:找不到结点时返回的是NULL，需要判断是否为NULL再对结点进行其他操作，否则对NULL取值会错误
 * @author 作者/修改者:冼文基
 * @date 日期:2022-11-27 12:52:28
 **/
sll_node_t *sll_get_node_by_pos(sll_t *sll, uint32_t pos)
{

    uint32_t node_cnt = 0;
    assert(sll);
    assert(sll->head);
    if (pos < sll->len)
    {

        if ((pos) == sll->len - 1)
        {
            return sll->tail;
        }
        else
        {

            sll_node_t *sll_node;
            sll_forech(sll, sll_node)
            {
                if (node_cnt++ == (pos))
                {
                    return sll_node;
                }
            }
        }
    }

    return NULL;
}

/**
 * @brief 简介:按位置插入结点
 * @param 形参:sll 单链表对象
 * @param 形参:node_insert 要插入的新单链表结点
 * @param 形参:pos 新结点要插入的链表位置
 * @retval 返回值:
 * @note  注意!!!:
 * @author 作者/修改者:冼文基
 * @date 日期:2022-11-27 13:59:40
 **/
sll_node_t *sll_insert_by_pos(sll_t *sll, sll_node_t *node_insert, uint32_t pos)
{

    sll_node_t *node_prev = NULL; // 插入结点的前驱结点
    assert(sll);
    assert(node_insert);

    if (is_sll_empty(sll))
    {
        sll->head = node_insert;
        node_insert->next = NULL;
        sll->tail = node_insert;
        sll->len++;
    }
    else
    {
        assert(sll->head);

        if (pos == 0)
        {

            node_insert->next = sll->head;
            sll->head = node_insert;

            sll->len++;
        }
        else
        {
            // 获取前一结点
            node_prev = sll_get_node_by_pos(sll, pos - 1); // 1为头插，其他中途插
            if (node_prev)
            {

                node_insert->next = node_prev->next;
                node_prev->next = node_insert;
                if (pos == sll->len)
                {
                    sll->tail = node_insert;
                }
                sll->len++;
                return node_prev;
            }
        }
    }
    return NULL; // 插入失败
}
/**
 * @brief 简介:按位置删除结点
 * @param 形参:sll 单链表对象
 * @param 形参:pos 新结点要插入的链表位置
 * @retval 返回值:
 * @note  注意!!!:
 * @author 作者/修改者:冼文基
 * @date 日期:2022-11-27 19:20:19
 **/
void sll_erase_by_pos(sll_t *sll, uint32_t pos)
{

    sll_node_t *node_prev = NULL; // 插入结点的前驱结点
    sll_node_t *del_node = NULL;
    assert(sll);

    if (is_sll_empty(sll))
    {
        return NULL;
    }
    else
    {
        assert(sll->head);

        if (pos == 0)
        {

            del_node = sll->head;
            sll->head = del_node->next;
            del_sll_node(del_node);
            sll->len--;
        }
        else
        {

            // 获取前一结点
            node_prev = sll_get_node_by_pos(sll, pos - 1); // 1为头插，其他中途插
            if (node_prev)
            {
                del_node = node_prev->next;
                node_prev->next = del_node->next;
                del_sll_node(del_node);

                if (pos == sll->len)
                {
                    sll->tail = node_prev;
                }

                sll->len--;
            }
        }
    }
    return NULL; // 插入失败
}

void sll_erase_by_range(sll_t *sll, uint32_t sta, uint32_t end)
{
    uint32_t cnt = 0;
    for (cnt = 0; cnt <= end - sta; cnt++)
        sll_erase_by_pos(sll, sta);
}

void sll_clear(sll_t *sll)
{

    while (!is_sll_empty(sll))
    {
        sll_erase_by_pos(sll, 0);
    }
}

void sll_pop_front(sll_t *sll)
{

sll_erase_by_pos(sll, 0);
    

}

void sll_pop_back(sll_t *sll)
{

    sll_erase_by_pos(sll, sll->len-1);

}

sll_node_t * sll_push_front(sll_t *sll, sll_node_t *node_insert)
{

sll_insert_by_pos(sll,node_insert,0);

}

sll_node_t * sll_push_back(sll_t *sll, sll_node_t *node_insert)
{

sll_insert_by_pos(sll,node_insert,sll->len);

}



// emplace_front()：在容器首个元素前直接生成新的元素；
// emplace_back()：在容器最后一个元素后直接生成新的元素；
// emplace()：在容器的指定位置直接生成新的元素；

// splice()