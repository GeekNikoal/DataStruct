#ifndef MCSTL_H
#define MCSTL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "assert.h"//调试断言assert()
#define NDEBUG //取消所有断言







#include "c_sll.h"




#define C_new(type) =(type*) malloc (sizeof(type))
#define C_news(type,len) =(type*) malloc (sizeof(type*len))

#define is_empty(val) val==NULL


#define C_del(val) free(val)



#ifdef  __cplusplus
}
#endif

#endif // MCSTL_H