Exercise

1.read two inputs from user(//parent process)
	name:
	reg no:
	age:
	
2.print the output from the child(// child process)
	 name: abc
	 regno: 2021/ict/01
	 age: 25
	 
code:...........



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Student {
    char name[50];
    char regno[50];
    int age;
};

int main() {
    int fd[2];
    pid_t pid;
    struct Student s;

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        
        close(fd[0]); // Close reading end

        printf("Enter your Name: ");
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = '\0'; // Remove newline

        printf("Enter your reg no: ");
        fgets(s.regno, sizeof(s.regno), stdin);
        s.regno[strcspn(s.regno, "\n")] = '\0';

        printf("Enter your age: ");
        scanf("%d", &s.age);

        write(fd[1], &s, sizeof(s));
        close(fd[1]); // Close writing end
    } else {
        
        close(fd[1]); // Close writing end

        read(fd[0], &s, sizeof(s));
        close(fd[0]);

        printf("\nChild Process Output:\n");
        printf("name: %s\n", s.name);
        printf("regno: %s\n", s.regno);
        printf("age: %d\n", s.age);
    }

    return 0;
}



