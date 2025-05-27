#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("\nHello World!");
	int f=fork();
	int p=getpid();
	
	printf("\n the pid is %d", p);
	printf("\n the fork is %d", f);
	
	return 0;
}

##output

[2021ict75@fedora ~]$ vi fork.c
[2021ict75@fedora ~]$ gcc fork.c -o fork
[2021ict75@fedora ~]$ ./fork

Hello World!
 the pid is 11640
 the fork is 11641Hello World!
 the pid is 11641
 the fork is 0
 
 [2021ict75@fedora ~]$ ./fork

Hello World!
 the pid is 12085
 the fork is 12086Hello World!
 the pid is 12086
 the fork is 0
 
 ------------------------------------------------------------------------------
 
 #include<stdio.h>
#include<unistd.h>


int main()
{
	int f=fork();
	
	if(f==0)
	{
		printf("\nHello I'm Child Process");
	}
	else{
		printf("\nHello i'm Parent Process!");
	}
	
	return 0;
}


##output
[2021ict75@fedora ~]$ vi child.c
[2021ict75@fedora ~]$ gcc child.c -o child
[2021ict75@fedora ~]$ ./child

Hello i'm Parent Process!
Hello im Child process!
 the pid is 13638
 the fork is 13639Hello im Child process!
 the pid is 13639
 the fork is 0
