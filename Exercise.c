--------------------------------------------------------------

Exercise1: 
First Child: Slept for 1 seconds
Second Child: Slept for 3 seconds
Parent :Both Children have executed.

#include <stdio.h>
#include <stdlib.h>  
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;

    printf("Parent Process. PID: %d\n", getpid());

    pid1 = fork();

    if (pid1 < 0)
    {
        perror("Fork for first child failed");
        exit(1);
    }
    if (pid1 == 0) 
    {
        printf("First Child Process. PID: %d sleeping for 1 second...\n", getpid());
        sleep(1);
        exit(0);
    }
    else // Parent process
    {
        pid2 = fork(); // Creating second child

        if (pid2 < 0)
        {
            perror("Fork for second child failed");
            exit(1);
        }
        if (pid2 == 0) // Second child process
        {
            printf("Second Child Process. PID: %d sleeping for 3 seconds...\n", getpid());
            sleep(3);
            exit(0);
        }
        else // Parent waiting for both children
        {
            int status;
            printf("Parent waiting for children to finish...\n");

            waitpid(pid1, &status, 0); // Wait for first child
            waitpid(pid2, &status, 0); // Wait for second child

            printf("Parent Process ending.\n");
        }
    }

    return 0;
}

[2021ict75@fedora ~]$ gcc forkwait.c -o forkwait
[2021ict75@fedora ~]$ ./forkwait
Parent Process. PID: 13908
Parent waiting for children to finish...
First Child Process. PID: 13909 sleeping for 1 second...
Second Child Process. PID: 13910 sleeping for 3 seconds...
Parent Process ending.

	
----------------------------------------------------
EX0-2

First Child: sleeps for 2 seconds, exit with status 2.
Second child: sleeps for 1 second, exit with status 1.
Parent: wait twice, and prints which child(by PID or exit code) finished first and second

#include <stdio.h>
#include <stdlib.h>  
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;
    int status1, status2;
    
    printf("Parent Process. PID: %d\n", getpid());

    // Create first child
    pid1 = fork();
    
    if (pid1 < 0) {
        perror("Fork for first child failed");
        exit(1);
    }
    
    if (pid1 == 0) { // First child process
        printf("First Child Process (PID: %d) sleeping for 2 seconds...\n", getpid());
        sleep(2);
        exit(2); // Exit with status 2
    }

    // Create second child
    pid2 = fork();
    
    if (pid2 < 0) {
        perror("Fork for second child failed");
        exit(1);
    }

    if (pid2 == 0) { // Second child process
        printf("Second Child Process (PID: %d) sleeping for 1 second...\n", getpid());
        sleep(1);
        exit(1); // Exit with status 1
    }

    // Parent waits for both children
    pid_t finished_pid1 = wait(&status1);
    pid_t finished_pid2 = wait(&status2);

    // Check exit status
    int exit_status1 = WEXITSTATUS(status1);
    int exit_status2 = WEXITSTATUS(status2);

    printf("Parent Process: First completed -> PID: %d, Exit Status: %d\n", finished_pid1, exit_status1);
    printf("Parent Process: Second completed -> PID: %d, Exit Status: %d\n", finished_pid2, exit_status2);
    
    printf("Parent Process ending.\n");

    return 0;
}

##output

[2021ict75@fedora ~]$ ./sleepex2
Parent Process. PID: 14562
First Child Process (PID: 14563) sleeping for 2 seconds...
Second Child Process (PID: 14564) sleeping for 1 second...
Parent Process: First completed -> PID: 14564, Exit Status: 1
Parent Process: Second completed -> PID: 14563, Exit Status: 2
Parent Process ending.

----------------------------------------------------

Ex-3
The parent creates a child process
The child creates a grandchild process.
the grandchild sleeps 2 seconds and then exit with status 2
the child waits for the grandchild,prints its exit status,then exit with status55

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, grandchild_pid;
    int grandchild_status, child_status;

    printf("Parent process. PID: %d\n", getpid());

    // Create child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork for child failed");
        exit(1);
    }

    if (child_pid == 0) { // Child process
        printf("Child process (PID: %d) created by Parent.\n", getpid());

        // Create grandchild process
        grandchild_pid = fork();

        if (grandchild_pid < 0) {
            perror("Fork for grandchild failed");
            exit(1);
        }

        if (grandchild_pid == 0) { // Grandchild process
            printf("Grandchild process (PID: %d) sleeping for 2 seconds...\n", getpid());
            sleep(2);
            printf("Grandchild exiting with status 2.\n");
            exit(2);
        } else { // Child process waits for grandchild
            waitpid(grandchild_pid, &grandchild_status, 0);
            printf("Child process (PID: %d) detected grandchild exit with status: %d.\n", getpid(), WEXITSTATUS(grandchild_status));
            printf("Child exiting with status 55.\n");
            exit(55);
        }
    } else { // Parent waits for child
        waitpid(child_pid, &child_status, 0);
        printf("Parent process detected child exit with status: %d.\n", WEXITSTATUS(child_status));
        printf("Parent process ending.\n");
    }

    return 0;
}

##output

[2021ict75@fedora ~]$ ./sleepex3
Parent process. PID: 14852
Child process (PID: 14853) created by Parent.
Grandchild process (PID: 14854) sleeping for 2 seconds...
Grandchild exiting with status 2.
Child process (PID: 14853) detected grandchild exit with status: 2.
Child exiting with status 55.
Parent process detected child exit with status: 55.
Parent process ending.

----------------------------------------------------


