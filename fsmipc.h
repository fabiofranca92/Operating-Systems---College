#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <errno.h>

void *shmalloc(key_t, int, int *);
int shmemcreat(key_t, int);
int shmemget(key_t, int);
void *shmemat(int);
int shmemdet(void *);
int shmrm(int);

int cria_semaforo(key_t,int);
int remove_semaforo(int);
int P(int);
int V(int);
