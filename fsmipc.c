#include "fsmipc.h"

// extern int errno;


void *shmalloc(key_t key,int size, int *shmid)
{
	void	*a;

	if ((*shmid = shmget(key, size, IPC_CREAT|0666)) == -1){
		perror("shmget");
		return -1;
        } else {
		if ((a = shmat(*shmid, (void *)0, 0666)) == -1){
			perror("shmat");
			return -1;
		} else 
			return a;
	}
}

int shmemcreat(key_t key, int size)
{
	int shmid;
        if ((shmid = shmget(key, size, IPC_CREAT|0666)) == -1){
                perror("shmemget");
                return -1;
        } else
		return shmid;
}

int shmemget(key_t key, int size)
{
	int shmid;
        if ((shmid = shmget(key, size, 0666)) == -1){
                perror("shmemget");
                return -1;
        } else
		return shmid;
}

void *shmemat(int shmid)
{
        void    *a;

	if ((a = shmat(shmid, (void *)0, 0666)) == -1){
		perror("shmat");
		return -1;
	} else
		return a;
}


int shmrm(int shmid)
{
	int error;
	if ((error=shmctl(shmid, IPC_RMID, 0))== -1)
		perror("shmremove");
	return error;
}


int shmemdet(void *m)
{
	int error;
	if ((error=shmdt((void *)m))== -1)
                perror("shmdet");
        return error;
}

/*
 ************ semaforos  ***********
 */
#define ERRO (-1)
/*
struct  sembuf _P_semaforo = {0,-1,SEM_UNDO};
struct  sembuf _V_semaforo = {0,1,SEM_UNDO};
*/
struct  sembuf _P_semaforo = {0,-1,0};
struct  sembuf _V_semaforo = {0,1,0};
/*
union semun {
	int val;
        struct semid_ds *buf;
        ushort *array;
};
*/

int cria_semaforo(key_t chave, int inicial)
{
        int     id;
	union semun	valor;
        if ((id = semget((key_t) chave, 1, IPC_CREAT|IPC_EXCL|0666)) == ERRO)
                if ((id = semget((key_t) chave,1,0666)) == ERRO){
                        perror("Erro no get_semaforo");
                        return(ERRO);
                } else
                        return(id);

        else {
                /* inicializa o semaforo */
		valor.val = inicial;
                if (semctl(id,0,SETVAL,valor) == ERRO) {
                        perror("Erro no cria_semaforo");
                        return(ERRO);
                } else
                        return(id);
        }
}
                
P(int id)
{
        int     temp;
        if ((temp = semop(id,&_P_semaforo,1)) == ERRO) {
                printf("Erro no P(%d) errno=%d\n",id, errno);
		perror("P");
                return(ERRO);
        } else
                return(temp);
}
                

V(int id)
{
        int     temp;
        if ((temp = semop(id,&_V_semaforo,1)) == ERRO) {
                printf("Erro no V(%d) errno=%d\n",id, errno);
		perror("V");
                return(ERRO);
        } else
                return(temp);
}


remove_semaforo(int id)
{
	int error;
	if ((error = semctl(id,0,IPC_RMID,0)) == ERRO) {
		perror("Erro no remove_semaforo");
	}        
	return(error);
}
