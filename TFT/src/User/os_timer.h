#ifndef _OS_TIMER_H_
#define _OS_TIMER_H_
#include "stdint.h"
 	  

typedef void (*FP_TASK)(void *); 

typedef struct 
{     
  uint32_t time;
  uint32_t start_time;
  FP_TASK  task;
  void    *para;
  uint8_t  is_exist; 
  uint8_t  is_repeat; 
}OS_TASK;


void OS_TimerInit(uint16_t psc, uint16_t arr); 
uint32_t OS_GetTime(void);

void OS_TaskInit(OS_TASK *task, uint32_t time, FP_TASK function,void *para);
void OS_TaskCheck(OS_TASK *task);
void OS_TaskEnable(OS_TASK *task, uint8_t is_exec, uint8_t is_repeat);
void OS_TaskDisable(OS_TASK *task);
 
#endif
