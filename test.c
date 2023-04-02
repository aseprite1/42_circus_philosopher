# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

pthread_mutex_t mutex;
int cnt;

void *count(void *arg)
{
  char *name;
  int i;

  name = (char *)arg;
  pthread_mutex_lock(&mutex);
  cnt = 0;
  while (i<13)
  {
    printf("%s cnt : %d\n",name , cnt);
    cnt++;
    usleep(1);
    i++;
  }
  pthread_mutex_unlock(&mutex);
  return ((void *)arg);
}

int main(void)
{
  pthread_t ptr1;
  pthread_t ptr2;
  pthread_t ptr3;

  pthread_mutex_init(&mutex, NULL);
  pthread_create(&ptr1, NULL, count, (void *)"thread1"); 
  pthread_create(&ptr2, NULL, count, (void *)"thread2"); 
  pthread_create(&ptr3, NULL, count, (void *)"thread3"); 
  pthread_join(ptr1,NULL);
  pthread_join(ptr2,NULL);
  pthread_join(ptr3,NULL);
  pthread_mutex_destroy(&mutex);
  return 0;
}
