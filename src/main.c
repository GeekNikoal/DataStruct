
#include "c_sll.h"

#include "sll_stack.h"
#include "sll_queue.h"


#include "string.h"
#include "stdio.h"


void printf_string_list(sll_t* str);

int main(int c,char* v[])
{

//  sll_t * str = sll_create("string");
//  printf("%s.len:%d\n",(char*)str->msg,str->len);
 
// sll_node_t *  ss =sll_new_node("123",strlen("123")*sizeof(char));
// sll_insert_by_pos(str,ss,0);

//  printf("%s.len:%d\n",(char*)str->msg,str->len);
// sll_node_t *  ss2 =sll_new_node("456",strlen("456")*sizeof(char));
// sll_insert_by_pos(str,ss2,1);
// printf("[%d]=%s\n",1,((c_link2_t*)(str->head->pointer))->next->data);  

// sll_node_t *  ss3 =sll_new_node("789",strlen("789")*sizeof(char));
// sll_insert_by_pos(str,ss3,1);

// sll_push_front(str,ss3);
// sll_pop_back(str);
// sll_erase_by_pos(str,0);
// sll_erase_by_pos(str,0);
// sll_erase_by_range(str,0,1);

// sll_clear(str);
//  printf("%s.len:%d\n",(char*)str->msg,str->len);

//----------------------------------------------------------------------------------------------------------------



class_sll_stack_t* stack=new_sll_stack("str");

sll_node_t* node1 =sll_new_node("n1",strlen("n1")*sizeof(char*));

stack->push(stack,node1);


sll_node_t* node2 =sll_new_node("n2",strlen("n1")*sizeof(char*));

stack->push(stack,node2);

printf_string_list(stack->super);



return 0;


}



void printf_string_list(sll_t* str)
{
    printf("[");
sll_node_t* sll_node;
sll_forech(str,sll_node)
{
    
   printf("\"%s\"",(char*)sll_node->data);
   if(sll_node->next!=NULL)
   printf(","); 
}
printf("]\r\n");

}