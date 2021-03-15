#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* myThread(void* vargp) {
  sleep(1);
  printf("From thread, %d\n", pthread_self());
  return NULL;
}

int main() {
  pthread_t thread_id;
  printf("Not in thread %d\n", pthread_self());
  sleep(2);
  pthread_create(&thread_id, NULL, myThread, NULL);
  printf("Joining thread\n");
  pthread_join(thread_id, NULL);
  printf("Out of thread\n");
  exit(0);
}