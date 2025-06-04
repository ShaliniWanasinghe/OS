// writer process1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024 // size of sharedmemory segment

int main()
{
	key_t key = ftok("shmfile",1075); //Generate unique key
	int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666) ; //create shm segment
	if (shmid == 1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL, 0); //Attach to shared memmory
	if(shmaddr == (char*) -1) {
		perror("shmat");
		exit(1);
	}
	
	printf("Write Data: ");
	fgets(shmaddr, SHM_SIZE, stdin); //Write data to shared memmory
	
	printf("Data written in memmory: %s\n", shmaddr);
	
	shmdt(shmaddr);  //detach from shared memmory
	
	return 0;
}

----------OUTPUT
[2021ict75@fedora ~]$ vi writershm.c
[2021ict75@fedora ~]$ gcc writershm.c -o writershm
[2021ict75@fedora ~]$ ./writershm
Write Data: Hello Sh
Data written in memmory: Hello Sh


//Reader

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024 


int main(){
	
	key_t key = ftok("shmfile",1075); 
	int shmid = shmget(key, SHM_SIZE, 0666); 
	if (shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL, 0); 
	if(shmaddr == (char*) -1) {
		perror("shmat");
		exit(1);
	}
	
	
	
	printf("Data read from memmory: %s\n", shmaddr);
	
	shmdt(shmaddr);  
	
	return 0;
}
