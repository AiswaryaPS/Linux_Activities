#include "sum.h"

int Array[1000] = {};
int sum[10] = {};


int sumof1000() {

  int i, k = 0, n = 10, final_sum = 0;
  pthread_t ptarr[n];
  srand(time(0));

  for(i=0; i<1000; i++) {
 
    /* Assigning random value to Array */   Array[i] = random()%10;
  }

  for (i = 0; i < n; i++) {
   
    pthread_create(&ptarr[i], NULL, task_body, (void *)(__intptr_t)i);
  }

  for (i = 0; i < n; i++)
  {pthread_join(ptarr[i], NULL);}

  for(i=0; i<100; i++)
  {
    /* Adding the results from thread to get final value */final_sum += sum[i]; 
  }
  return final_sum; 
}
