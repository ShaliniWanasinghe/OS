//print numbers from 1 to 10 and 1-5 should be print by child process 
//and from 6 to 10 should be parent process 
//calculate summation of those numbers

#include<stdio.h>
#include<unistd.h>

int main()
{
	   int sum=0;
       int f= fork();
	   if(f==0)
	   {
		   printf("\nHello I am Child process!");
		   
		   for(int i=1;i<6;i++){
			   printf("%d", i);
			   sum = sum + i;
		   }
		   
		    printf("\nChild process summation is: %d\n", sum);
	   }else{
		   
		   printf("\nHello I am Parent process!");
		   for (int j=6; j <11; j++) {
            printf("%d ", j);
            sum = sum + j;
        }
        printf("\nParent process summation is: %d\n", sum);
	   }
	   
	   return 0;
}

##Output 
[2021ict75@fedora ~]$ vi acti.c
[2021ict75@fedora ~]$ gcc acti.c -o acti
[2021ict75@fedora ~]$ ./acti

Hello I am Parent process!6 7 8 9 10
Parent process summation is: 40

Hello I am Child process!1 2 3 4 5
Child process summation is: 15


