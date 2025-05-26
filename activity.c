%Example sleep

#include <stdio.h>
#include <stdlib.h>  //for exit()
#include <unistd.h>  //for fork(),sleep()

int main() {
	printf("Program started.\n");
	
	printf("Sleeping for 3 seconds....\n");
	sleep(3); //pause for 3 seconds
	
	printf("Existing the program.\n");
	exit(0); //clean exit
	
	return 0;
}


[2021ict75@fedora ~]$ ./forksleep
Program started.
Sleeping for 3 seconds....
Existing the program.


----------------------------------------------------------------------
%Example wait

#include <stdio.h>
#include <stdlib.h>  
#include <unistd.h>
#include<sys/wait.h>  //for wait()

int main()
{
	pid_t pid;
	
	printf("Parent process started.  PID: %d\n",getpid());
	
	pid = fork(); //create a new child process
	if(pid<0)
	{
		perror("fork failded");
		exit(1);
	}
	
	if (pid == 0)
	{
		//child process
		printf("Child process. PID: %d sleeping for 2 seconds....\n");
		sleep(2);
		
		printf("Child process existing.\n");
		exit(0);  //child exits with status 0
	} 
	 else 
	{
		//parent process
		int status;
		printf("parent waiting for child to finish...\n");
		wait(&status); //wait for child to finish
		if (WIFEXITED(status)) {
			printf("Child exited with status: %d\n", WEXITSTATUS(status));
			 //WEXITSTATUS(status) gets the actual exit code (0 here)
		}else {
			printf("Child didnot exit normally.\n");
		}
		printf("Parent process ending./n");
	}
	
	return 0;
}

[2021ict75@fedora ~]$ ./wait
Parent process started.  PID: 11820
parent waiting for child to finish...
Child process. PID: 11821 sleeping for 2 seconds....
Child process existing.
Child exited with status: 0

