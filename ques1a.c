#include <stdio.h> 
#include <pthread.h> 
#include"mythreads.h"  
int flag[2]; 
int turn; 
const int MAX = 1e9; 
int ans = 0; 
  
void lock_init() 
{ 
    flag[0] = flag[1] = 0; 
    turn = 0; 
} 
void lock(int self) 
{ 
    flag[self] = 1; 
    turn = 1-self; 
    while (flag[1-self]==1 && turn==1-self) ; 
} 
void unlock(int self) 
{ 
    flag[self] = 0; 
} 
void* func(void *s) 
{ 
    int i = 0; 
    int self = (int *)s; 
    printf("Thread Entered: %d\n", self); 
    lock(self); 
    // Critical section 
    for (i=0; i<MAX; i++) 
        ans++; 
    unlock(self); 
} 
int main() 
{ 
    // Initialized the lock then fork 2 threads 
    pthread_t p1, p2; 
    lock_init(); 
    pthread_create(&p1, NULL, func, (void*)0); 
    pthread_create(&p2, NULL, func, (void*)1); 
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
  
    printf("Actual Count: %d | Expected Count: %d\n", ans, MAX*2); 
  
    return 0; 
} 
